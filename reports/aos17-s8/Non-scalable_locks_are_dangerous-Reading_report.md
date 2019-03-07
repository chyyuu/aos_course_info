# Non-scalable locks are dangerous

## Summary of major innovations

本文通过设计模型来论证不可扩展的锁会导致系统性能突然下降，并解释为何会出现这种现象，同时还设计实验比较了不同的可扩展锁效果如何。

## What the problems the paper mentioned?

如今大家对不可扩展锁的观点主要有三种：不可扩展锁会严重下降系统的整体性能；性能下降的现象可能会随着核数的增加而突然出现；尽管决定性的部分通常会比较短，可能只有几个指令，但也会造成性能的骤降。

## How about the important related works/papers?

> - T. E. Anderson. The performance of spin lock alternatives for shared-memory multiprocessors. IEEE Trans. Parallel Distrib. Syst., 1:6–16, January 1990  
> - M. Herlihy and N. Shavit. The art of multiprocessor programming. Morgan Kaufman, 2008
> - J. M. Mellor-Crummey and M. L. Scott. Algorithms for scalable synchronization on shared-memory mul- tiprocessors. ACM Transactions on Computer Sys- tems, 9(1):21–65, 1991.

以上三篇文章介绍了不同种的可扩展性锁机制，是本文的实验对象。

> S. Eyerman and L. Eeckhout. Modeling critical sections in Amdahl’s law and its implications for multicore design. In Proceedings of the 37th Annual International Symposium on Computer Architecture (ISCA), pages 262–370, Saint-Malo, France, June 2010.

本文模型的建立与上文的基础之上。

## What are some intriguing aspects of the paper?

这边文章的有趣之处主要在于作者对实验模型的建立。

## How to test/compare/analyze the results?

从分析结果来看，对于x86多核机器，任意一种可扩展锁都比Ticket lock性能更好，但对于不同可扩展锁之间的比较，似乎它们的差别并不是太大。