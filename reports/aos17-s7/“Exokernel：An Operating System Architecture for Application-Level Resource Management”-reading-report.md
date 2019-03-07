# “Exokernel：An Operating System Architecture for Application-Level Resource Management”-reading-report

### 1 Summary of major innovations

​	提出并实现了exokernel操作系统体系结构，这种结构通过在应用级提供硬件资源的管理，来解决这些Section 2中提出的问题。在这种体系结构中，一个小的kernel将所有的硬件资源通过一个low-level的接口安全地导出给不受信任的library operating systems。这种将资源保护和管理分离的做法允许通过扩展、定制、甚至替换库的方式来定制传统的操作系统的abstractions。

### 2 What the problems the paper mentioned?

​	传统的操作系统固定了操作系统的接口和实现（比如进程间通、虚拟内存），限制了性能、灵活性以及应用程序可以实现的功能。

### 3 How about the important related works/papers?

这篇文章的related works比较多，比如

（1）1979年和1980年的两篇论文，阐述了对可扩展、灵活性高的kernel的需求；

（2）1970年和1971年的两篇论文，最初提出可扩展的操作系统；

（3）1974年，HYDRA是一个早期的，希望将kernel策略和机器分离的系统。

（4）1981年，VM/370系统诞生，它是exokernel的理想目标——只提供硬件接口。

还有很多关于当时近几年的发展和技术细节的文章，上面这些是文章的idea来源。

### 4 What are some intriguing aspects of the paper?

​	本文最大的贡献在于建议一种操作系统的结构——exokernel，将资源的保护与管理分离，使得在保证安全的前提下，大幅提高性能。如何做到这一点是本文最值得关注的一点。文章理论部分的重点就是阐述下面三种技术，并用这三种技术来实现exokernel的目标：

（1）secure bindings

​	应用程序可以安全地绑定到硬件资源和事件句柄；

（2）visible resource revocation

​	应用程序参与资源回收协议；

（3）abort protocol

​	exokernel可以强制中断不配合的应用程序的bindings；

### 5 How to test/compare/analyze the results?

​	文章的实验部分主要对集中基本的接口（比如进程间通信(IPC)，应用程序级的虚拟内存等）与当时成熟的Ultrix系统进行过比较对比来测试Exokernel的性能。

### 6 How can the research be improved?

​	Exokernel允许application直接操作硬件，虽然提高了performance，但是给应用开发人员增加了不少的负担，并没有广泛运用的价值。IBM曾经花费了不少人力物力，最终不了了之。

​	操作系统内核的发展方向之一就是缩小内核，要么用来定制，要么牺牲一些特性换取其他特性。本文的研究牺牲了应用程序开发的难度，换取高性能，只适用于少数特定开发需求，比如大规模科学计算等由专业开发人员团队开发的应用场景。

​	我认为这个项目提升的空间就在于如何使项目容易部署，降低开发成本。比如现在比较火的Docker和新兴的Unikernel都很注重容易部署。

### 7 If you write this paper, then how would you do?

​	如果在当时那个时代，这篇论文的缺点应该在于实验部分比较少，评测结果不够多，不够general。包括用的参数指标，机器，评测程序等都不够。我会加更多的实验，测试更多的应用场景来让本文的应用范围更广。

### 8 Did you test the results by yourself? If so,What’s your test Results?

​	这个项目是MIT一个实验室的，paper是1998年发的，项目维护到2000年6月份，而且是一个对环境要求很严格的项目，暂时没时间搭出那个年代的开发环境……

​	亲测现在流行的系统是没法直接用的，有时间再试试吧……

### 9 Give the survey paper list in the same area of the paper your reading.

（1）Microkernel Operating System Architecture and Mach，1991

（2）Unikernels: Library Operating Systems for the Cloud，2013




































