# 阅读报告

## 1，主要创新点

本文[Diagnosing Performance Overheads in the Xen Virtual Machine Environment](http://www.hpl.hp.com/techreports/2005/HPL-2005-80.pdf?jumpid=reg_R1002_USEN)了一个可以用于全系统（system-wide）分析Xen的工具集：Xenprof。它可以协调不同虚拟机来收集所有虚拟机产生的硬件事件。

## 2，主要解决的问题

提出了一个可以解决Xen全系统的性能分析工具，（这是由于Xen的特点，它不能使用一个集中式的性能分析工具），并使用这个工具去分析Xen环境下的网络性能。（注：分析网络的性能主要是因为网络应用越来越重要并且虚拟的网络I/O设备代价高昂）。分析了CPU对于网络吞吐量的影响。并分别分析了在单核和多核情形下Xen对于网络I/O设备虚拟化的性能负载。

## 3，相关工作

之前有工作测试了有网络带宽限制且CPU高可用情况下Xen在网络benchmarks的性能。以下几篇文章分析了几种VMM的实现在微基准测试下虚拟化负载对性能的影响。

## 4，背景介绍

Xen的结构：Xen包含三个部件

​	Xen Hypervisor:直接运行于硬件之上是Xen客户操作系统与硬件资源之间的访问接口。

​	Domain 0：运行在Xen管理程序之上，具有直接访问硬件资源和管理其它Domain的特权。

​	Domain U: 不能直接访问硬件资源，需要通过设备通道机制来与驱动domain通信以便使用硬件资源。

## 5，结果测试

本文测试了三个benchmark：前两个微基准测试测试只有很少网络连接的TCP收发，第三个测试是一个完整的web服务器在不同配置下的综合工作负载。

测试共分为三种不同机器配置：

Xen-domain0：应用运行在单个特权驱动domain。

Xen-guest0:这种配置是非特权guest domain和特权driver domain运行在同一个CPU。

Xen-guest1:与Xen-guest0配置相同，只是guest和driver domain运行在不同CPU。

测试结果：

​	对于receiver这个基准测试程序来说：在guest domain这种设置之下，吞吐量还不到Xen-domain0一半。主要原因是hypervisor以及driver domain的计算负载导致了指令的代价上升了2.2到2.5倍。此外工作集的大小增大以及局部性减弱导致很大的L2缺失也是一个原因。

​	对于sender基准程序来说：guest配置下的吞吐量少于Xen-domain0吞吐量的五分之一。这是由于Xen的I/O driver domain 不允许guest使用TSO。当然，工作集增长和局部性的降低也同样影响性能。

​	对于Web服务器基准来说：所有的guest设置都受到了很高的指令代价以及L2缺失的影响。网桥以及页面交换都造成了很高的指令代价。不过，这次没有受TSO的影响。

## 6，可能的进一步改进

可以尝试使用其他的性能分析工具进行实验，如VTune，或者可以尝试分析其他比较有很大负载的应用，比如一些受内存虚拟化影响的。此外，还可以尝试分析软件层次的事件来优化。

## 7，相关论文

[Virtual Machine Monitors:Current Technology and Future Trends](http://grid.hust.edu.cn/platform/resource/document/Virtual%20Machine%20Monitors%20Current%20Technology%20and%20Future%20Trends.pdf) 介绍了VMM的发展史以及对于CPU,内存，I/O虚拟化的挑战与解决。

[ Measuring CPU overhead for I/O processing in the Xen virtual machine monitor](http://static.usenix.org/event/usenix05/tech/general/full_papers/short_papers/cherkasova/cherkasova.pdf)介绍了一种用于性能分析的模型，并提出一种轻量级的监测器分析了处理I/O时的CPU负载。
