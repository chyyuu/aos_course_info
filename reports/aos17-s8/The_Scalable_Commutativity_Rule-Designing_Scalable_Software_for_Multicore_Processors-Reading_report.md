# The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors


## Summary of major innovations

本文从软件界面这一层级提出了一种达到可伸缩性的新方法，这一方法可以使关于可伸缩性的问题能够在实例存在之前以及必要的硬件存在之前进行可伸缩性的测评。

## What the problems the paper mentioned?

通常对软件系统的可伸缩性测试都是基于一定的工作量，测试软件性能随着处理系核数的变化来展开的，这些都是基于固定的工作量及核数的，但可伸缩性的瓶颈经常会出现在另外不同的工作量上或者是更高的处理器核数上，这就使得我们无法达成一个比较全面的可伸缩性测试。

## How about the important related works/papers?

Israeli 和 Rappoport 介绍了一种并行不相交的内存管理系统，这使得应用在使用这种方法使用共享内存时，这种共享内存应用实例是可伸缩的，但是这个工作只受限于内存管理方面，本文提供了一种适用于任何软件界面的方法。


## What are some intriguing aspects of the paper?

本文对于可伸缩交换原则的具体定义上，使用了一种纯理论性的论述，再加上它在文章中的表现方式（色块的这种表示方式），使得作者所表述的原则能很容易被读者理解。

## How to test/compare/analyze the results?

本文提出的是一种准则，然后在这个准则基础上设计了一个类Unix操作系统Xv6，通过比较Xv6和Linux在可伸缩性上的差别来体现这一准则的效果。