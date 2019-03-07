# Exokernel: An Operating System Architecture for Application-Level Resource Management

## 概述

本文着眼于传统操作系统框架的弊端，提出了一种能够克服此缺陷的新型操作系统框架，即将计算机物理资源管理从底层移至了应用层面。作者先从框架设计所遵循的原则讲起，随后阐述了该操作系统框架的具体实现细节，包括Exokernel以及库操作系统实现所采用的技术及协议，最后作者通过自己写出的该框架实例来进行对比测试，说明该框架的诸多优点。

## 操作系统框架 
 从底至上，该框架分为三部分：
 
- Exokernel  
- Library Operating Systems
- 应用程序

## Summary of major innovations

传统操作系统对计算机进行了封装和抽象，将一系列接口提供给上层应用程序，这种做法限制了应用的性能、灵活度以及功能性。本文提出的Exokernel操作系统框架通过所提出的应用层物理资源管理来解决上述问题。在本框架中，有一个微型内核负责将所有硬件资源通过低级接口安全的输出给一个非信任的“库操作系统”（Library operating systems），再由库操作系统使用这些低级接口对系统对象以及策略进行实例化。以此达成资源保护从资源管理中的分离，这种特性使得应用可以通过扩展、具体化甚至函数库替换来自定义传统操作系统。

## What the problems the paper mentioned?

操作系统作为应用程序和计算机硬件的沟通桥梁，主要负责定义应用程序和物理资源的接口。传统操作系统隐藏了计算机的物理资源，将其抽象为用于应用执行的虚拟机，但是这种方法存在明显的弊端，即会限制应用程序的性能及其实现功能的自由度。

## How about the important related works/papers?

本文的工作是在一些已有工作基础上建成的，例如M. Accetta等人1986年发表的文章Mach: a new kernel foundation for UNIX development阐述了基于Unix的新型内核结构；T.E. Anderson于1992年发表的文章The case for application-specific operating systems以及其团队之前的一篇文章Scheduler activations: Effective kernel support for the user-level management of parallelism介绍了应用层面（或者说用户层面）的资源管理系统相关技术以及基于应用的操作系统；J. S. Chase于1994发表的文章Sharing and protection in a single-address-space operating system介绍了在单地址空间操作系统中如何分享及保护内存，这些文章都从不同层面为本文架构提供了技术支持。

## What are some intriguing aspects of the paper?

本文采用了一种非传统的操作系统框架，这是一种较创新的框架。作者将常规在计算机底层进行的机器资源管理系统迁入到了应用层面，作者这样做的初衷是希望能让应用更加贴近物理机的实际资源，以此提高效率。另外，作者对于此种框架的具体实现也是很新颖，即从底层到上层分别为微内核Exokernel，库操作系统，应用程序。

## How to test/compare/analyze the results?

作者实现了本文框架的一种实现，其中Exokernel叫做Aegis，上层库系统叫做ExOS，作者在这种具体实现基础上进行了一些不同层面的测试，例如设计实验测试在多种相同机器上分别运行Ultrix和ExOS系统，测试其二者进行虚存操作时的时间性能；比较相同机器上不同操作系统的在以太网上的往返延迟，作者分别测试了带有ASH的ExOS、ExOS、Ultrix等。通过比较这些参数，可以大致看出ExOS在大部分情况下表现出比Ultrix更好的或相近的性能。

## How can the research be improved?

文章中的测试用例包含了很多种不同层面，但我认为他还缺少一个应用程序效率方面的测试，在这方面测试的结果也可以从总体体现出一些该框架的特性或者优点，同时也可以在测试上更全面，具有说服性。

## If you write this paper, then how would you do?

综合上一点来讲，我选择几种不同领域的应用程序，将其移植到ExOS中运行，通过其运行时间和原系统的运行时间进行对比，得出适当的结论，同时我还会将ExOS相关代码开源以供后续研究和讨论。

## Give the survey paper list in the same area of the paper your reading.

- Accetta M J, Baron R V, Bolosky W J, et al. Mach: A new kernel foundation for UNIX development[C]// 1986:93-113.
- Anderson T E. The case for application-specific operating systems[C]// The Workshop on Workstation Operating Systems. IEEE Xplore, 1992:92-94.
- Anderson T E. Scheduler activations: effective kernel support for the user-level management of parallelism[J]. Acm Transactions on Computer Systems, 1992, 10(1):53-79.
- Hollander L M. Sharing and Protection in a Single Address Space Operating System[J]. Acm Transactions on Computer Systems, 1998, 12(4):271-307.
