# Report for exokernel

## Summary of major innovations
不同于传统的monolithic-kernel或者micro-kernel的操作系统，本文提出了exokernel，它提供了硬件资源的应用层管理。在exokernel架构中，exokernel通过低层的接口向不可信的操作系统层暴露（导出）硬件资源。操作系统库基于exokernel提供的接口实现系统对象和政策。这种脱离于资源管理的资源保护使得应用层程序可以扩展、特化或者替换掉操作系统库，
从而应用程序获得更大的灵活性以及更高的性能。

实验数据表明，exokernel使得应用程序具备更大的灵活性：比如虚拟内存和进程间通信可以在应用层进行管理。此外，基于
exokernel的应用程序获得数倍于monolithic-kernel(Ultrix)的性能。
## Problems this paper mentioned
传统的操作系统都提供并实现了高层次的抽象接口，应用程序必须基于操作系统提供的接口进行系统调用才能获取硬件资源。然而这限制了应用程序的灵活性、性能以及功能。

1. 固定的高层次的接口限制了应用程序的性能。因为对于不同的硬件资源，没有一个统一的方法使得对硬件资源进行抽象并实现后适合所有的应用程序。
1. 固定的高层次的接口对应用程序隐藏了信息。操作系统负责管理，应用程序不能实现自己的管理策略。
1. 固定的高层次的接口限制了应用程序的功能。

由于操作系统的限制，本文提出的exokernel只提供低层次的硬件资源抽象与实现，把资源保护与管理分开。把硬件资源的管理暴露给上层，这就使得应用程序具备很高的灵活性，应用程序可以自定义、特化以及替换掉操作系统实现的库。
## Related work
1. VM/370(R.j.Creasy. The origin of VM/370 time-sharing system. IMB J.Research and Development)提供理想的exkernel的接口：硬件层。在硬件接口之上，VM/370支持虚拟机。exokernel于VM/370重要的不同在于VM/370灵活性的提供是靠虚拟化整个系统，这样，VM/370虚拟化会非常费时且需要硬件支持。此外，机器大部分对于应用层都是透明的，这样应用层很难控制管理硬件资源。总之，虽然说虚拟机可以提供更大的控制，应用程序不得不承受性能的损失，并且缺少真正关键的控制。
1. 当代的微内核工作认为内核扩展的必要性，但是不同于传统的微内核，exokernel允许应用层的库管理虚拟内存、定义IPC等。还有的微内核(J.Liedtke. On micro-kernel construction. Proc of SOSP, 1995)工作把kernel层降低到硬件层，但是由于没有secure binding、visible revocation以及abort协议，应用层对硬件资源的管理非常有限。
1. Cache Kernel(D.Cherition and K.Duda. A caching model of operating system kernel functionality. Proc of OSDI. 1994)提供了可以支持多个应用层操作系统的低层内核。在当时，Cache Kernel和exokernel是唯二实现在多任务环境下的通用的操作系统库。不同之处在于Cache Kernel致力于提供可靠性，而exokernel致力于提高应用层的灵活性以及性能。这样，Cache kernel为服务器设计的系统结构。

## Some intriguing aspects of this paper
Exokernel目标是给应用层的操作系统或者普通应用程序提供尽量多的管理硬件资源的自由，使得硬件资源的保护与管理分开。Exokernel主要使用三个技术：

1. Secure binding: Exokernel设计重要思想是将资源的保护与管理分开。为了保护不同的硬件资源，exokernel必须监控每个资源。Exokernel允许应用层的操作系统使用Secure binding来和硬件资源绑定。Secure binding将硬件的授权于使用分开，仅仅在绑定时验证，kernel在不理解硬件使用情况下保护硬件资源。
    1. 硬件机制：在kernel里，使用硬件直接做访问验证而不需要返回到用户层检测
    1. 软件缓存：在kernel里，使用软件TLB缓存没有在硬件TLB中命中的地址翻译
    1. 下载应用程序代码：在kernel里下载代码后，每次硬件资源访问后代码会执行，决定资源的拥有权。
1. Visble revocation:资源的释放回收：exokernel采用可见的释放回收是因为应用层的操作系统可以决定释放并感知到资源变化。虽然说显式回收会因为应用层加入回收过程而带来代价，exokernel仅仅保存有效状态。
1. Abort protocol:正常情况下，应用层的操作系统会使用Visible revocation释放资源。可是在异常情况下，exokernel支持Abort，即：强制回收资源。（保证应用程序最小的资源分配）

## Experiments: test/compare/analyze
1. exokernel: Aegis具备很高的效率
    1. 很容易记录资源的拥有者
    2. kernel很少的底层接口使得kernel运行起来效率很高
    3. 软件TLB缓存提高了TLB缺失时的处理性能
    4. 下载代码使得网络绑定运行效率很高
1. 应用程序操作系统ExOS具备很高的效率
    1. IPC抽象：pipe、shm、lrpc
    2. 应用层的虚拟内存管理
    3. 针对应用的安全Handlers
1. ExOS扩展：传统的操作系统下，不支持应用程序根据本身特点自定义功能实现
    1. 扩展RPC
    2. 扩展Page-table
    3. 扩展Schedulers

## How can the research be improved?
个人认为这篇文章的工作很有意义，基于传统操作系统的限制，本文设计了exokernel：一个非常底层的内核，暴露给应用层操作系统少量的资源接口，将资源保护于管理分开，大大提高了应用层的灵活性以及运行性能。然后，作者详细阐述了exokernel的设计、实现以及实验对比。其中，实验部分，本文主要说明了Aegis、ExOS都可以具备很高的效率，此外说明了应用程序可以更灵活的管理硬件资源（见Experiments部分）。

个人认为实验部分缺少对真正应用程序运行效果的对比实验，即：同样的硬件环境，同样的程序，在exokernel系统以及Monolithic-kernel系统运行性能的对比。

## Survey paper list
1. R.j.Creasy. The origin of VM/370 time-sharing system. IMB J.Research and Development, 1981
1. J.Liedtke. On micro-kernel construction. Proc of SOSP, 1995 
1. D.Cherition and K.Duda. A caching model of operating system kernel functionality. Proc of OSDI. 1994 
1. M.Frans Kaashoek. Application Performance and Flexibility on Exokernel Systems, Proc of SOSP, 1997.
