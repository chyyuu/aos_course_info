# COLO: COarse-grained LOck-stepping Virtual Machines for Non-stop Service 阅读报告

## 1.论文背景

虚拟机备份（Virtual machine replication）是用于应对物理机器失败而提出的基于软件的容错机制，通常PVM（primary VM）和SVM（secondary VM）位于不同的物理节点上。 目前的虚拟机备份方法存在开销高的问题。lock-stepping 的解决方法基于指令集的同步，即保证PVM、SVM的每一条指令执行完的时刻保证二者的状态一致，这样做保证了细粒度的一致性，但如果是多处理器的场景下由于访存指令的不确定性，性能将急剧下降；Remux提供里一种相较之下粗粒度和性能开销较小的方案，它通过定时器在checkpoint处检查PVM、SVM的状态是否一致，不一致则进行同步。

COLO 针对常见的server-client paradigm，从client来看，server和它的唯一交互方式只有网络数据包，如果client持续的获得正确的响应数据包，则就认为server端并未失败。因此它采用了更加粗粒度的一致性判断条件，即只要PVM、SVM发出的响应数据包一直，就认为SVM是同步的。因此它的checkpoint的频率更低，因此降低了开销。



## 2.设计架构和创新点



COLO在PVM和SVM中有Heartbeat、Manager、Checkpoint等组件。Heartbeat使用定期互通消息，若超过一定期限没有回复则认为对方失败。COLO认为响应数据包由请求数据包和VM内部的某些非确定因素决定，而非确定因素的作用相较于请求较弱。因此每当PVM收到一个client的请求数据包便转发给SVM，SVM将基于请求生成的响应数据包转发给PVM，PVM比较每个数据包来确定SVM是否保持了一致性。若二者的响应数据包不一致，Manager则 触发checkpoint，使得SVM的内部状态重新和PVM一样。

而影响数据包是否一样的因素很多一部分基于TCP协议内部的非确定性因素，如Timestamp、ACK的频率、窗口更新消息等，为了避免并非数据部分不同导致的整个响应TCP包不同，作者修改了TCP协议，使得包头不同的几率下降，以此降低checkpoint的频率，减少性能开销。

对于内部状态的一致性，COLO也采用了基于checkpoint的机制，当每次成功比对同步后，才commit SVM内部的状态存储。



## 3.实验

在SysBench、Web的GET\PUT请求、pgbench等workload下，COLO性能比原生linux较弱，但比Remus有明显的优势。

