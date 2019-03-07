# Scalable Kernel TCP Design and Implementation for Short-Lived Connections 阅读报告

## 1.论文背景

short-lived connections 是一种常见的流量模式，它的特点是频繁的分配和释放系统资源。目前位解决多核下TCP协议栈可拓展性的解决方案有：重新设计协议栈，多在用户空间实现，缺点在于都只实现了基本的协议栈功能，没有内核的功能丰富；内核协议栈，存在共享数据结构争用、连接本地化等问题，可拓展性 差；重新为socket设计了一套api，缺点在于移植困难，兼容性差。

为了解决这些问题，作者提出了在内核中通过协议栈共享数据的合理切分、本地化，保证同一条流的数据包只在一个核上处理、跳过VFS中和socket相关的inode、dentry同步的开销等，实现拓展性好的同时保留了内核协议栈的丰富功能，以及BSD socket接口的兼容性。



## 2.设计架构及创新点

设计主要包括三个方面：TCP管理数据结构的划分、完全的连接本地化、避开VFS中socket不必要的同步开销。

### 2.1TCP管理数据结构的划分

local listen table

在保证每个数据包被其连接所在核上被处理的前提下，每个核都有本地的监听表。新建连接的处理分为fast path和slow path。fast path为正常的处理流程，新来的连接将在本地的监听表中发现，并建立连接；slow path为若应用进程crash导致相应的socket被回收时，为保证鲁棒性，将在全局监听表中处理该socket的请求。

local established table

每个数据包先被steer到其连接所在核上，然后在local established table找到其所在的连接，再进行协议栈处理。

### 2.2完全的连接本地化

连接本地化即保证每个数据包被网卡放在其连接所在的核上。

主动连接的本地化，通过将所在核的id作为目的端口的hash值，使得收到包时计算一次hash能找到所在核的id

被动连接的本地化

RFD通过先分类收到的包是主动连接还是被动连接，再进行后续的core id的解复用

RFD可以和网卡的功能相结合来提高性能，如ATR和perfect-filtering

### 2.3 VFS的修改

在VFS中绕过socket不会使用的逻辑，来降低不必要的同步的开销。



## 3.实验验证

fastsocket   和传统的linux内核协议栈相比，具有优势：cpu占有率低、多核的线性可拓展性、lock争用率低、连接的本地化强。

