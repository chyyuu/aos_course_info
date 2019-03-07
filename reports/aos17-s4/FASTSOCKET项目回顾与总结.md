# FASTSOCKET项目回顾与总结

### 1，项目简介

fastsocket是新浪于2014年开源的项目。它主要解决短时TCP连接在多核下扩展性不足的问题。主要解决方案是建立一种局部Listen Table以及established Table,并将这些表绑定到各个CPU上，使得每个给定socket的listen和创建连接，接受连接的工作都在同一个CPU上完成，这样就减少了cache bounce以及每次决定哪个CPU接受监听哪个socket的工作。此外，fastsocket还提出了fastscoket-aware-VFS，因为对于socket来说，一般文件所需要的如dentry，inode并不重要（socket的整个生存周期都在内存，不需要这些需要访问或者获取硬盘信息的数据）。这种解决方案即解决了VFS抽象不至于被破坏，有保证了对于多核建立socket时使用文件操作时的自旋锁。

### 2，安装以及在高版本linux内核编译

##### 2.1，centOS上面的安装过程

首先根据github上面的建议，我们尝试了在centOS6.5上面编译，此时的内核版本为2.6.32，基本步骤如下：

​	git clone https://github.com/fastos/fastsocket.git

​	make defconfig

​	make

​	make modules_install

​	make install

​	注意有的时候这里会报错，说某一些模块找不到，经过研究，这些模块可以通过修改/boot/.config文件，将对应模块设置为y，但是对于fastsocket来说，只要重启的时候fastsocket可以加载即可以实验（这里关于某些模块未加载的原因以及可能的bug尚待之后的分析）。

​       此后，我们只需要修改/etc/grub.conf文件种default的值，将其改为0，重启系统就加载了带有fastsocket模块的linux内核。

​	实验时，只需要modprobe fastsocket就能将fastsocket模块加载到了系统。

##### 2.2，ubuntu16.10编译与安装fastsocket的尝试

​	我们最早直接将fastsocket在ubuntu16.10上编译，失败。发现报错找不到gcc5.h的文件，由此我们联想到可能是版本的原因，因此我们最初查了centOS的gcc编译器，发现版本是4.4.7,但是ubuntu只能apt-get到4.7版本的，于是用这个版本的gcc编译器试了一下，（注，make的版本也同时需要降级，我们选择的是make-3.8.1），发现kernel里面有一个timeconst.pl函数报错，在第373行代码中有错，我们将define(@val)的define删除，编译通过。重复centOS的过程，发现没有错误。对于ubuntu来说，不需要修改grub配置文件，可以直接在ubuntu高级选项中选择需要启动的内核，但是当我们启动带fastsocket版本的内核时，系统无法加载。。。

### 3，实验与测试

​	首先需要实验的时demo中的server程序，此时可以通过(假设此时路径为yourPath/fastsocket/demo)

​		LD_PRELOAD=../library/libfsocket.so ./server -w 8 -a http://yourURL/

加载fastsocket的动态链接库。

同时我们需要在另一个机器上使用apache benchmark对fastsocket的性能进行测试

​		ab -n 1000000 -c 1000 -r http://yourURL/

其中n是总的连接次数，c是并发等级，r是保证即使在连接出错的时候也继续工作。

我们在以下配置的虚拟机上实验：

​	CPU：intel i7 7700HQ 4核 8线程

​	MEN:2GB

​	DISK:20GB

​	NIC:Intel(R)Dual Band Wireless-AC 7265

​	虚拟机：vmware workstation 11,设置的CPU是8核

​	网络配置：NAT

对于两次实验（即使用了fastsocket或者没有使用）结果如下：

|      | 没有使用fastsocket | 使用fastsocket |
| ---- | -------------- | ------------ |
| 时间   | 13.257sec      | 4.736sec     |

同样的实验也可以在服务器端执行反向代理Nginx，其结果如下

|      | 没有使用fastsocket | 使用fastsocket |
| ---- | -------------- | ------------ |
| 时间   | 10.312sec      | 9.281sec     |

实验设计的不足以及可能的改进：
由于本实验在虚拟机上面实验，难免与fastsocket提出的应用背景不符，但是由于暂时手头没有可以用的机器（四核以及以下的机器不能体现出fastsocket的优势），因此此前只能使用虚拟机。

##### 3.2，perf的分析

我们对上述应用进行分析，使用linux自带的分析工具perf。

当Nginx执行时，我们获取其pid

执行下面的命令：

​	perf top -p [pid]

可以观察到随着时间的变化，在不使用fastsocket的时候，有大量的CPU负载都在内核的_spin_lock_bh上，当使用fastsocket时，负载从高于50%降到了1.7%.

#### 4，代码阅读：

代码主要部分在fastsocket/kernel/net/fastsocket里面

其中有三个核心文件：fastsocket.h,fastsocket_core.c,fastsocket_api.c

fastsocket_api.c实现内核模块接口，在源码注册文档的可配置项目

int enable_fastsocket_debug = 3;

int enable_listen_spawn = 2;
int enable_receive_flow_deliver;
int enable_fast_epoll = 1;
int enable_skb_pool;
int enable_rps_framework;
int enable_receive_cpu_selection = 0;
int enable_direct_tcp = 0;
int enable_socket_pool_size = 0;

module_param(enable_fastsocket_debug,int, 0);
module_param(enable_listen_spawn, int, 0);
module_param(enable_receive_flow_deliver, int, 0);
module_param(enable_fast_epoll, int, 0);
module_param(enable_direct_tcp, int, 0);
module_param(enable_skb_pool, int, 0);
module_param(enable_receive_cpu_selection, int, 0);
module_param(enable_socket_pool_size, int, 0);

MODULE_PARM_DESC(enable_fastsocket_debug, " Debug level [Default: 3]" );
MODULE_PARM_DESC(enable_listen_spawn, " Control Listen-Spawn: 0 = Disabled, 1 = Process affinity required, 2 = Autoset process affinity[Default]");
MODULE_PARM_DESC(enable_receive_flow_deliver, " Control Receive-Flow-Deliver: 0 = Disabled[Default], 1 = Enabled");
MODULE_PARM_DESC(enable_fast_epoll, " Control Fast-Epoll: 0 = Disabled, 1 = Enabled[Default]");
MODULE_PARM_DESC(enable_direct_tcp, " Control Direct-TCP: 0 = Disbale[Default], 1 = Enabled");
MODULE_PARM_DESC(enable_skb_pool, " Control Skb-Pool: 0 = Disbale[Default], 1 = Receive skb pool, 2 = Send skb pool,  3 = Both skb pool");
MODULE_PARM_DESC(enable_receive_cpu_selection, " Control RCS: 0 = Disabled[Default], 1 = Enabled");
MODULE_PARM_DESC(enable_socket_pool_size, "Control socket pool size: 0 = Disabled[Default], other are the pool size");

接受用户态的libfastsocket.so通过ioctl传递过来的数据，根据命令进行数据分发

static long fastsocket_ioctl(struct file *filp, unsigned int cmd, unsigned long __user u_arg)
{

	struct fsocket_ioctl_arg k_arg;

	if (copy_from_user(&k_arg, (struct fsocket_ioctl_arg *)u_arg, sizeof(k_arg))) {
		EPRINTK_LIMIT(ERR, "copy ioctl parameter from user space to kernel failed\n");
		return -EFAULT;
	}
	
	switch (cmd) {
	case FSOCKET_IOC_SOCKET:
		return fastsocket_socket(&k_arg);
	case FSOCKET_IOC_LISTEN:
		return fastsocket_listen(&k_arg);
	case FSOCKET_IOC_SPAWN_LISTEN:
		return fastsocket_spawn_listen(&k_arg);
	case FSOCKET_IOC_ACCEPT:
		return fastsocket_accept(&k_arg);
	case FSOCKET_IOC_CLOSE:
		return fastsocket_close(&k_arg);
	case FSOCKET_IOC_SHUTDOWN_LISTEN:
		return fastsocket_shutdown_listen(&k_arg);
	//case FSOCKET_IOC_EPOLL_CTL:
	//	return fastsocket_epoll_ctl((struct fsocket_ioctl_arg *)arg);
	case FSOCKET_IOC_SPAWN_ALL_LISTEN:
		EPRINTK_LIMIT(DEBUG, "ioctl [%d] receive spawn all listen socket", cmd);
		return fastsocket_spawn_all_listen();
	default:
		EPRINTK_LIMIT(ERR, "ioctl [%d] operation not support\n", cmd);
		break;
	}
	return -EINVAL;
}

fastsocket/library/libsocket.h头文件定义的FSOCKET_IOC_* 操作状态码就能够一一对应的上。 ioctl传输数据从用户态->内核态，需要经过一次拷贝过程（copy_from_user），然后根据cmd命令进行功能路由。

void fastsocket_init(void)
{

	int ret = 0;
	int i;
	cpu_set_t cmask;
	
	ret = open("/dev/fastsocket", O_RDONLY);
	...
}

注意到这一段libfsocket.c的代码，它实现了打开fastsocket内核注册的监听通道，这样就可以通过ioctl数据传递。



对于fastsocket_core.c来说，大体上实现的是fastsocket_api.c封装前的函数实现。首先它维护一个状态纪录表，每个cpu都有这样一个纪录当前有多少个socket处于哪种状态。

enum {

	FSOCKET_STATS_SOCK_ALLOC_FROM_SLAB,
	FSOCKET_STATS_SOCK_FREE_TO_SLAB,
	FSOCKET_STATS_SOCK_ALLOC_FROM_POOL,
	FSOCKET_STATS_SOCK_FREE_TO_POOL,
	FSOCKET_STATS_SOCK_IN_POOL,
	FSOCKET_STATS_SOCK_POOL_LOCK,
	FSOCKET_STATS_SOCK_ACCEPT_CONNS,
	
	FSOCKET_STATS_NR
};

其他的内核函数实现了socket的申请释放，以及socket相关文件的申请与释放，并且优化了dentry,以及inode的申请初始化过程，如dentry，通过下面函数生成dentry.d_dname

static char *fastsockfs_dynamic_dname(struct dentry *dentry, char *buffer, int buflen,

			const char *fmt, ...)
{
	va_list args;
	char temp[64];
	int sz;
	
	va_start(args, fmt);
	sz = vsnprintf(temp, sizeof(temp), fmt, args) + 1;
	va_end(args);
	
	if (sz > sizeof(temp) || sz > buflen)
		return ERR_PTR(-ENAMETOOLONG);
	
	buffer += buflen - sz;
	return memcpy(buffer, temp, sz);
}

此外在socket的管理上，使用内存池，并为每个cpu都分配了相应的内存池。

具体请参考fastsocket源码的注释。