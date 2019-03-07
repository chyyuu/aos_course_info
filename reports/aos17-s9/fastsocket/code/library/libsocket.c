/*
 * libsocket.c
 *
 * Copyright (C) SINA Corporation
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <linux/eventpoll.h>
#include <unistd.h>
//#include <fcntl.h>

#define __USE_GNU
#include <sched.h>
#include <dlfcn.h>

#include "libsocket.h"

static int fsocket_channel_fd = -1;

#define FSOCKET_ERR(msg, ...)
/*
#define FSOCKET_ERR(msg, ...) \
do {\
	fprintf(stderr, "Fastsocket Library:" msg, ##__VA_ARGS__);\
}while(0)
*/

#define INIT_FDSET_NUM	65536

/* fsocket_fd_set is useed to check listen fd to spawn listen
 * socket "automatically" without changing applications' code.
 * This automation is definitely not accurate. However, it's
 * serving Haproxy and Nginx fine in the test environment and
 * the production enviroment */

//TODO: To support multi-thread programme

static int *fsocket_fd_set;
static int fsocket_fd_num;

/**
*获取CPU核数
*/
inline int get_cpus()
{
        return sysconf(_SC_NPROCESSORS_ONLN);
}
/**
*构造函数,在fastsocket_init函数执行之前执行
*/
__attribute__((constructor))
void fastsocket_init(void)
{
	int ret = 0;
	int i;
	cpu_set_t cmask;
/**
*1.连接内核模块已经注册好的设备通过/dev/fastsocket,返回文件描述符
*/
	ret = open("/dev/fastsocket", O_RDONLY);
	if (ret < 0) {
		FSOCKET_ERR("Open fastsocket channel failed, please CHECK\n");
		/* Just exit for safty*/
		exit(-1);
	}
	fsocket_channel_fd = ret;
/**
*2.分配65536个长度为sizeof(int)的空间
*/
	fsocket_fd_set = calloc(INIT_FDSET_NUM, sizeof(int));
	if (!fsocket_fd_set) {
		FSOCKET_ERR("Allocate memory for listen fd set failed\n");
		exit(-1);
	}

	fsocket_fd_num = INIT_FDSET_NUM;
/**
*CPU亲合力就是指在Linux系统中能够将一个或多个进程绑定到一个或多个处理器上运行.
*一个进程的CPU亲合力掩码决定了该进程将在哪个或哪几个CPU上运行.在一个多处理器系统中,
*设置CPU亲合力的掩码可能会获得更好的性能.

 
*一个CPU的亲合力掩码用一个cpu_set_t结构体来表示一个CPU集合,下面的几个宏分别对这个掩码集进行操作:
   ·CPU_ZERO() 清空一个集合
   ·CPU_SET()与CPU_CLR()分别对将一个给定的CPU号加到一个集合或者从一个集合中去掉.
   ·CPU_ISSET()检查一个CPU号是否在这个集合中.
*cpu集可以认为是一个掩码,每个设置的位都对应一个可以合法调度的cpu，
*而未设置的位则对应一个不可调度的CPU。换而言之，线程都被绑定了，只能在那些对应位
*被设置了的处理器上运行。通常，掩码中的所有位都被置位了，也就是可以在所有的cpu中调度。       
*/
	CPU_ZERO(&cmask);

	for (i = 0; i < get_cpus(); i++)
		CPU_SET(i, &cmask);
/**
*下面两个函数就是用来设置获取线程CPU亲和力状态: 
    ·sched_setaffinity(pid_t pid, unsigned int cpusetsize, cpu_set_t *mask) 
      该函数设置进程为pid的这个进程,让它运行在mask所设定的CPU上.如果pid的值为0,
	则表示指定的是当前进程,使当前进程运行在mask所设定的那些CPU上.
	第二个参数cpusetsize是mask所指定的数的长度.通常设定为sizeof(cpu_set_t).
	如果当前pid所指定的进程此时没有运行在mask所指定的任意一个CPU上,则该指定的进程会从其它CPU
	上迁移到mask的指定的一个CPU上运行. 
    ·sched_getaffinity(pid_t pid, unsigned int cpusetsize, cpu_set_t *mask) 
      该函数获得pid所指示的进程的CPU位掩码,并将该掩码返回到mask所指向的结构中.
	即获得指定pid当前可以运行在哪些CPU上.同样,如果pid的值为0.也表示的是当前进程.
*/
	ret = sched_setaffinity(0, get_cpus(), &cmask);
	if (ret < 0) {
		FSOCKET_ERR("Clear process CPU affinity failed\n");
		exit(-1);
	}

	return;
}

__attribute__((destructor))
void fastsocket_uninit(void)
{
	close(fsocket_channel_fd);
	free(fsocket_fd_set);

	return;
}
/**
*假如传入的文件描述符fd大于当前管理的最大文件描述符fsocket_fd_num
*那么按照INIT_FDSET_NUM=65536的大小进行扩展
*假如失败了,通过ioctl调用FSOCKET_IOC_CLOSE传递arg.fd=fd关闭当前要使用的文件
*/
int fastsocket_expand_fdset(int fd)
{
	int *old_fd_set = fsocket_fd_set;
	int ret = fd;
	struct fsocket_ioctl_arg arg;

	if (fd >= fsocket_fd_num) {
		fsocket_fd_set = calloc(fsocket_fd_num + INIT_FDSET_NUM, sizeof(int));
		if (!fsocket_fd_set) {
			FSOCKET_ERR("Re allocate memory for listen fd set failed\n");
			arg.fd = fd;
			ioctl(fsocket_channel_fd, FSOCKET_IOC_CLOSE, &arg);
			//FIXME: Is it a appropriate errno here?
			errno = EMFILE;
			ret = -1;
		} else {
			memcpy(fsocket_fd_set, old_fd_set, fsocket_fd_num * sizeof(int));
			free(old_fd_set);
			fsocket_fd_num += INIT_FDSET_NUM;
		}
	}
	return ret;
}

int socket(int family, int type, int protocol)
{
	//函数指针,接收真实的socket函数
	static int (*real_socket)(int, int, int) = NULL;
	int fd = -1;
	struct fsocket_ioctl_arg arg;
	/**
	*假如/dev/fastsocket打开成功,则调用FSOCKET_IOC_SOCKET
	*传递arg
	*在fastsocket_api中,调用fastsocket_ioctl根据传递的FSOCKET_IOC_SOCKET
	*判断采用fastsocket_socket函数去执行
	*/
	if (fsocket_channel_fd >= 0) {
		arg.op.socket_op.family = family;
		arg.op.socket_op.type = type;
		arg.op.socket_op.protocol = protocol;

		fd = ioctl(fsocket_channel_fd, FSOCKET_IOC_SOCKET, &arg);
		if (fd < 0)
			FSOCKET_ERR("FSOCKET:create light socket failed!\n");
		else
			fd = fastsocket_expand_fdset(fd);
	} else {
		if (!real_socket)
			/**
			*dlsym通过句柄和连接符名称获取函数名或者变量名
			*/
			real_socket = dlsym(RTLD_NEXT, "socket");

		fd =  real_socket(family, type, protocol);
	}

	return fd;
}

int listen(int fd, int backlog)
{
	static int (*real_listen)(int, int) = NULL;
	int ret = 0;
	struct fsocket_ioctl_arg arg;

	if (!real_listen)
		real_listen = dlsym(RTLD_NEXT, "listen");

	if (fsocket_channel_fd >= 0) {
		arg.fd = fd;
		arg.backlog = backlog;

		if (!fsocket_fd_set[fd])
			fsocket_fd_set[fd] = 1;

		ret = ioctl(fsocket_channel_fd, FSOCKET_IOC_LISTEN, &arg);
		if (ret < 0) {
			FSOCKET_ERR("FSOCKET:Listen failed!\n");
			fsocket_fd_set[fd] = 0;
		} else {
			arg.fd = fd;
        	arg.op.spawn_op.cpu = -1;

			if (ioctl(fsocket_channel_fd, FSOCKET_IOC_SPAWN_LISTEN, &arg) < 0) {
				FSOCKET_ERR("FSOCKET: spawn failed!\n");
			}
		}
	} else {
		ret =  real_listen(fd, backlog);
	}

	return ret;
}

int accept(int fd, struct sockaddr *addr, socklen_t *addr_len)
{
	static int (*real_accept)(int, struct sockaddr *, socklen_t *) = NULL;
	int ret = 0;
	struct fsocket_ioctl_arg arg;

	if (fsocket_channel_fd >= 0) {
		arg.fd = fd;
		arg.op.accept_op.sockaddr = addr;
		arg.op.accept_op.sockaddr_len = addr_len;
		arg.op.accept_op.flags = 0;

		ret = ioctl(fsocket_channel_fd, FSOCKET_IOC_ACCEPT, &arg);
		if (ret < 0) {
			if (errno != EAGAIN)
				FSOCKET_ERR("FSOCKET:Accept failed!\n");
		} else {
			ret = fastsocket_expand_fdset(ret);
		}
	} else {
		if (!real_accept)
			real_accept = dlsym(RTLD_NEXT, "accept");
		ret = real_accept(fd, addr, addr_len);
	}

	return ret;
}
/**
*accept4() 与 accept() 功能一样。下面flags 的值可能通过位求或运算来得到不同的行为：
*SOCK_NONBLOCK
		在新打开的文件描述符设置 O_NONBLOCK 标记。在 fcntl(2)中保存这个标记可以得到
		相同的效果。
*SOCK_CLOEXEC
		在新打开的文件描述符里设置 close-on-exec(FD_CLOEXEC)标记。
		参看在open(2)里关于O_CLOEXEC标记的描述来了解这为什么有用。
*/
int accept4(int fd, struct sockaddr *addr, socklen_t *addr_len, int flags)
{
	static int (*real_accept)(int, struct sockaddr *, socklen_t *) = NULL;
	int ret = 0;
	struct fsocket_ioctl_arg arg;

	if (fsocket_channel_fd >= 0) {
		arg.fd = fd;
		arg.op.accept_op.sockaddr = addr;
		arg.op.accept_op.sockaddr_len = addr_len;
		arg.op.accept_op.flags = flags;

		ret = ioctl(fsocket_channel_fd, FSOCKET_IOC_ACCEPT, &arg);
		if (ret < 0) {
			if(errno != EAGAIN)
				FSOCKET_ERR("FSOCKET:Accept failed!\n");
		} else {
			ret = fastsocket_expand_fdset(ret);
		}
	} else {
		if (!real_accept)
			real_accept = dlsym(RTLD_NEXT, "accept4");
		ret = real_accept(fd, addr, addr_len);
	}

	return ret;
}
/**
*close函数会关闭套接字ID，如果有其他的进程共享着这个套接字，
*那么它仍然是打开的，这个连接仍然可以用来读和写，
*并且有时候这是非常重要的 ，特别是对于多进程并发服务器来说。
*而shutdown会切断进程共享的套接字的所有连接，不管这个套接字的引用计数是否为零，
*那些试图读得进程将会接收到EOF标识，那些试图写的进程将会检测到SIGPIPE信号，
*同时可利用shutdown的第二个参数选择断连的方式。
*/
int close(int fd)
{
	static int (*real_close)(int) = NULL;
	int ret;
	struct fsocket_ioctl_arg arg;

	if (fsocket_channel_fd >= 0) {
		arg.fd = fd;

		if (fsocket_fd_set[fd])
			fsocket_fd_set[fd] = 0;

		ret = ioctl(fsocket_channel_fd, FSOCKET_IOC_CLOSE, &arg);
		if (ret < 0) {
			FSOCKET_ERR("FSOCKET:Close failed!\n");
		}
	} else {
		if (!real_close)
			real_close = dlsym(RTLD_NEXT, "close");
		ret = real_close(fd);
	}

	return ret;
}

int shutdown(int fd, int how)
{
	static int (*real_shutdown)(int, int) = NULL;
	int ret;
	struct fsocket_ioctl_arg arg;

	if ((fsocket_channel_fd >= 0) && fsocket_fd_set[fd]) {
		arg.fd = fd;
		arg.op.shutdown_op.how = how;

		ret = ioctl(fsocket_channel_fd, FSOCKET_IOC_SHUTDOWN_LISTEN, &arg);
		if (ret < 0) {
			FSOCKET_ERR("FSOCKET:Close failed!\n");
		}
	} else {
		if (!real_shutdown)
			real_shutdown = dlsym(RTLD_NEXT, "shutdown");
		ret = real_shutdown(fd, how);
	}

	return ret;
}

pid_t fork(void)
{
	static int (*real_fork)(void) = NULL;
	pid_t ret;

	if (!real_fork) {
		real_fork = dlsym(RTLD_NEXT, "fork");
	}

	ret = real_fork();
	if (-1 == ret) {
		FSOCKET_ERR("FSOCKET: fork failed!\n");
	} else if (0 == ret) {
		// Child process
		if (fsocket_channel_fd >= 0) {
			struct fsocket_ioctl_arg arg;
			memset(&arg, 0, sizeof(arg));
			// Spawn all listenning socket
			ioctl(fsocket_channel_fd, FSOCKET_IOC_SPAWN_ALL_LISTEN, &arg);
		}
	} 

	return ret;
}



