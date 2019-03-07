/*
 * libsocket.h
 *
 * Copyright (C) SINA Corporation
 */

#ifndef _LINUX_FASTSOCKET_LIB_H
#define _LINUX_FASTSOCKET_LIB_H

#include <linux/ioctl.h>

typedef unsigned int u32;

#define IOC_ID 0xf5
//socket
#define FSOCKET_IOC_SOCKET _IO(IOC_ID, 0x01)
//listen
#define FSOCKET_IOC_LISTEN _IO(IOC_ID, 0x02)
//accept4   accept(flags=0)
#define FSOCKET_IOC_ACCEPT _IO(IOC_ID, 0x03)
//close
#define FSOCKET_IOC_CLOSE _IO(IOC_ID, 0x04)
//#define FSOCKET_IOC_EPOLL_CTL _IO(IOC_ID, 0x05)

//listen    ret>=0时调用
#define FSOCKET_IOC_SPAWN_LISTEN _IO(IOC_ID, 0x06)
//shutdown
#define FSOCKET_IOC_SHUTDOWN_LISTEN _IO(IOC_ID, 0x07)
//fork
#define FSOCKET_IOC_SPAWN_ALL_LISTEN _IO(IOC_ID, 0x08)

/**
*定义了需要在用户态和内核态通过ioctl进行交互的结构
*
*/
struct fsocket_ioctl_arg {
	u32 fd;
/**
*这个参数涉及到一些网络的细节。进程处理一个一个连接请求的时候，
*可能还存在其它的连接请求。因为TCP连接是一个过程，所以可能存在一种
*半连接的状态，有时由于同时尝试连接的用户过多，使得服务器进程无法
*快速地完成连接请求。如果这个情况出现了，服务器进程希望内核如何
*处理呢？内核会在自己的进程空间里维护一个队列以跟踪这些完成的连接
*但服务器进程还没有接手处理或正在进行的连接，这样的一个队列内核不
*可能让其任意大，所以必须有一个大小的上限。这个backlog告诉内核使用
*这个数值作为上限。
*无疑问，服务器进程不能随便指定一个数值，内核有一个许可的范围。
*这个范围是实现相关的。很难有某种统一，一般这个值会小30以内。
*/	
	u32 backlog;

	union ops_arg {
		struct socket_accept_op_t {
			void *sockaddr;
			int *sockaddr_len;
			int flags;
		}accept_op;

		struct spawn_op_t {
			int cpu;
		}spawn_op;

		struct io_op_t {
			char *buf;
			u32 buf_len;
		}io_op;

		struct socket_op_t {
			u32 family;
			u32 type;
			u32 protocol;
		}socket_op;

		struct shutdown_op_t {
			int how;
		}shutdown_op;

		struct epoll_op_t {
			u32 epoll_fd;
			u32 size;
			u32 ep_ctl_cmd;
			u32 time_out;
			struct epoll_event *ev;
		}epoll_op;
	}op;
};

#endif
