# 阅读报告

## 1，主要创新点

Corey基于由应用控制所有的共享这一原则提出了一些low-level的抽象。使每个核自己使用本地数据结构，并且让用户程序自己决定共享与计算时间的平衡。并且提出一个默认的库操作系统设计。

Corey用五种抽象来表示资源：shares,segments,address trees,pcores,devices.

### 2，主要问题

多核架构越来越普遍，在一个芯片上有越来越多的CPU，现有的方法解决共享比较耗时并且也很困难。此外，本文在不同机器上面分析了多核架构的以下问题：远程访问其他核心的cache，锁，TLB操作。

### 3，文章比较有趣的地方

Corey不提供分时处理这种抽象给应用程序而是直接分配物理核心。

比较有趣的是，本文使用的address trees抽象：segment objects, internal address。前者适用于本地的，后者是可以共享的地址。

### 4，相关工作

Corey受益于NUMA操作系统以及多核系统的研究。这是因为NUMA系统和多核架构有相似之处。 [Disco: Running Commodity Operating Systems on Scalable Multiprocessors](http://delivery.acm.org/10.1145/270000/265930/p412-bugnion.pdf?ip=166.111.70.33&id=265930&acc=ACTIVE%20SERVICE&key=BF85BBA5741FDC6E%2E587F3204F5B62A59%2E4D4702B0C3E38B35%2E4D4702B0C3E38B35&CFID=921514226&CFTOKEN=42177603&__acm__=1491653068_6e6ba123490f1b0ddcb4b2518032f0c7)试运行在NUMA上面提供类外核的操作系统。其他NUMA上的工作包括[Scaling Linux to the Extreme](https://www.kernel.org/doc/ols/2004/ols2004v1-pages-133-148.pdf)

此外，Linux社区[Understanding the Linux 2.6.8.1 CPU scheduler](http://josh.trancesoftware.com/linux/), [An NUMA API for Linux](http://www.firstfloor.org/~andi/numa.html)也提供了很多为了提高NUMA可扩展性的优化。

[Kernel Scalability—Expanding the Horizon Beyond Fine Grain Locks](http://edgyu.excess.org/ols/2007/Corey%20D%20Gough%20-%20Kernel%20Scalability---Expanding%20the%20Horizon%20Beyond%20Fine%20Grain%20Locks.pdf) , [Performance Scalability of a Multi-Core Web Server](http://www.cse.wustl.edu/ANCS/2007/papers/p57.pdf)分析了Linux在多核架构下提高扩展性的挑战。

此外，最近的[Thread Clustering: Sharing-Aware Scheduling on SMP-CMP-SMT Multiprocessors](http://delivery.acm.org/10.1145/1280000/1273004/p47-tam.pdf?ip=166.111.70.33&id=1273004&acc=ACTIVE%20SERVICE&key=BF85BBA5741FDC6E%2E587F3204F5B62A59%2E4D4702B0C3E38B35%2E4D4702B0C3E38B35&CFID=921514226&CFTOKEN=42177603&__acm__=1491653948_e04e8bfdb1bc520171d829e5f29ed8b1) , [Scheduling threads for constructive cache sharing on CMPs](http://www.ece.northwestern.edu/~hardav/papers/2007_CMPScheduling_SPAA.pdf)提出一些与Corey不同思路的优化。

### 5，实验分析

本文使用MapReduce和Web服务来比较这个系统与Linux系统，从而评估本系统的性能。这两个应用的是数据并行（data-parallel）的应用，但是也有共享数据的需求。本文利用一些相关知识对于Corey的库操作系统进行了一定的扩展。如，对于MapReduce可以充分利用address trees这种抽象获得分隔开的页表以及共享页表。对于Web服务，Corey使用了swebd（spatial web daemons），kernel cores,applications这三个部分提供Web服务。并且将相应的系统调用分配给相应的核心。

对于MapReduce，本实验做了wc（wordcount），实验表明，address trees对于可扩展性有很大帮助。

对于Web服务，本实验表明，分配库操作系统函数给相应的核心可以提高可扩展性。

### 6，进一步工作

Corey目前还只是一个原型，而一些Linux的特性还没有实现。这对于Corey的性能有或好或坏的影响。并且目前Corey还没有一个很好的文件系统。