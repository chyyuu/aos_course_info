# Report for Live Migration of Virutal Machines(NSDI95)

## Summary of major innovations
本文贡献：在数据中心和机器集群管理中，实现了虚拟机的活迁移。它提供了硬件与软件的分离、容错以及方便维护的优点。本文在Xen虚拟机集群中实现了高性能的活迁移：较低的downtime、较低的总迁移时间以及对集群其他服务较小的影响。此外，OS级别的迁移实现了对用户透明的功能，即维护了网络连接、进程状态等信息，用户感知不到虚拟机的迁移。
## Problems this paper mentioned
本文主要考虑到在当前数据中心、云服务等涉及到多台机器集群的管理中，如果需要维护某些机器（下线），那么必须要对这些机器上的虚拟机或者用户服务进行迁移。然而用户进程的迁移难免设计到依赖问题：比如进程之间共享内存、打开文件列表等本地资源。虚拟机OS级别的迁移涉及到更少或者几乎没有的依赖，实际上，虚拟机OS封装了对底层硬件资源的访问，包括内存、网络以及磁盘等。另外，在迁移的过程中，希望能够对用户透明：即用户感受不到服务运行环境的迁移，用户不需要重启服务、重新建立连接，而且感受不到服务的卡顿。
## Related work
1. Collective project实现了虚拟机迁移，这个project设计的目的是为了用户在不同地点工作时候，在中间地点切换中，实现了虚拟机的迁移。这种迁移时间长，需要停止OS。
2. Zap使用了部分虚拟化支持了进程组的迁移。它修改了linux内核，把不同进程组的资源隔离开，这样在迁移的过程中的拷贝代价更低，获得了比Collective project更好的时间性能，然而这种方法也要停止进程的运行。
3. 虚拟机活迁移一个很重要的工作是基于L4微内核的NomadBIOS，它做到了OS的活迁移，使用了预拷贝降低了迁移时间，用户感受不到服务的停止，但是它没有对迁移过程中内存修改过程进行分析。
4. 进程级别的迁移工作有Sprite等，但是这涉及迁移过程中的资源依赖，难以解决。

## Some intriguing aspects of this paper
1. 虚拟机迁移前后硬件资源的变化
    1. Memory
        1. Push phase: 在源虚拟机运行的过程中，将内存页通过网络传输给目的地。对于脏页，需要重传。downtime会降低，总体迁移时间较长。
        2. Stop and copy phase: 源虚拟机停止，传输内存页。downtime较长。
        3. Pull phase: 新虚拟机在运行过程中，如果访问到没有传输过来的内存页，需要向源虚拟机请求该页。缺页代价高。
    2. Network: 局域网中，源虚拟机发送ARP包，告知自己IP位置变到了新的地方。
    3. Disk: network-attached storage
2. 迁移过程
    Stage0 Pre-Migration -> State1: Reservation -> State2: Ierative Pre-Copy -> Stage3: Stop-and-Copy -> Stage4: Commitment -> Stage5: Activation
3. Writable Working Sets分析
    1. 定义：源虚拟机仍在运行时，使用Pre-copy传输内存页，这样可以降低downtime。可是一些内存页在传输之后会被修改，在下一轮后需要重传。
    2. 对于经常变化的内存页在Stop-and-copy阶段传输
    3. 实验表明，在迁移过程中，更多轮的Pre-copy会降低downtime，可是downtime存在lowerbound。这是因为一些内存页更新的过于频繁，Pre-copy传输的内容失效。另外，增加网络带宽会带来更好效果。
4. 实现和优化
    1. Managed Migration & Self Migration: 迁移管理程序实现在VMM中或者在迁移虚拟机内部
    2. Dynamic Rate-Limiting: 在Pre-copy过程中，动态调整网络带宽，根据上一轮dirty page rate，适当调整当前轮网络带宽。在Stop-and-Copy过程中，为了降低downtime，使用尽可能多的网络带宽。
    3. Rapid Page Dirtying: 在Pre-copy过程中，不传输更新过于频繁的内存页。此外，在扫描时，考虑到空间局部性，随机扫描。
    4. Paravirtualized Optimizations: OS知道自己运行在虚拟机环境，可以Stun rogue process或者Free Page-Cache pages。

## Experiments: test/compare/analyze
实验表明，运行SPECweb的虚拟机在两个物理主机之间迁移需要210ms的downtime，运行Quake3的虚拟机只需要60ms的downtime。

## How can the research be improved?
目前live migration基于局域网以及net-attached storge。

## Survey paper list
1. Paul Barham. Xen and the art of virtualization. Proc of SOSP 1995.
2. Jacob G. Hansen. Master's thsis, Dept. of Computer Science, University of Copenhagen, Denmark, 2002.
3. S. Osman. The design and implementation of zap: A system for migrating computing environments. Proc  of OSDI 2002.
