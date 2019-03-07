#### 介绍

demo为一个简单TCP Server服务器程序,用于基准测试和剖析Linux内核网络堆栈性能表现,也用来展示Fastsocket可扩展性以及性能的提升。



demo应用基于epoll模型和非阻塞式I/O,处理网络连接,但只有在多核的模式下才能工作的很好：程序的每一个进程被绑定到CPU的不同核,起始于CPU core 0,各自独立处理客户端连接请求。

demo具有两种工作模式：

* 服务器模式：任何请求都会直接返回HTTP 200 OK
* 代理模式：服务器接收到客户端请求,转发给后端服务器,同时转发后端响应给客户端。


使用时要求客户端和服务器端只能够携带一个Packet包大小的数据,否则程序会处理不了。

#### 构建

```shell
cd demo && make
```

#### 运行

```shell
./server
```

参数如下：

* -w work_num:定义进程数
  * 默认值为当前可用CPU核心数
* -c start_one:指定第一个绑定worker进程的CPU
  * 默认值为0
* -o log_file:定义日志文件名称
  * 默认值为./demo.log
* -a listen_address:指定监听地址,[ip:port]字符串组合形式,支持监听多个地址
  * 默认值为0.0.0.0:80
* -x backend_address:启动代理模式,需要填写[ip:port]组合形式地址,支持多个代理地址
  * 默认禁用
* -v:启用详细统计数据输出
  * 默认禁用
* -d:启动Debug调试模式,调试信息被写入日志文件中
  * 默认禁用
* -k:启用HTTP keepalive机制,当前只能够工作在服务器模式下
  * 默认被禁用



#### Examples

注意:

* 为了跑满CPU,需要确保客户端和后端服务器都不应该成为瓶颈，两种解决方案：
  * 提供足够多机器用以充当客户端和后端服务器角色
  * 在一台机器上充当客户端和后端服务器，使用fastsocket(推荐方案,较为节省服务器)
* 正确配置网卡,可以参考源码中scripts目录

#### server mode example

服务器模式至少两台主机：

* 主机A作为客户端产生HTTP请求
* 主机B为Web服务器

Web服务器模式单独运行,开启8个工作进程,和CPU核数一致:

```shell
./server -w 8 -a 127.0.0.1:80
```

或者测试借助于Fastspcket所带来的性能：

```shell
LD_PRELOAD=../library/libfsocket.so ./server -w 8 -a 127.0.0.1:80
```

直接不加载libfsocket.so时执行以下指令结果为:

```shell
ab -n 1000000 -c 100  -k http://127.0.0.1:80/
```





```shell
LD_PRELOAD=/home/moonshine/fastsocket/fastsocket-master/library/libfsocket.so ./nginx
```