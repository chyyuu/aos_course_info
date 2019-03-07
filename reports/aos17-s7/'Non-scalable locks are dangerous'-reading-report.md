# 'Non-scalable locks are dangerous'-reading-report

### 1 Summary of major innovations

​	本文主要的创新在于构造了一个基于马尔可夫链的预测模型，可以解释随着核数增加，系统性能突然下降的现象。



### 2 What the problems the paper mentioned?

​	现在业界普遍认识到non-scalable locks本身的性能比较差，但是并没有认识到它还会引起整个系统性能的突然崩盘，本文通过理论和实验结合，说明并验证了以下三个问题：

​（1）Non-scalable locks的确可能会在现实使用的多核环境中，本身性能下降严重。原因在于随着竞争cores的增加，锁的开销迅速增长。

（2）随着核数的增加，系统性能随时可能会迅速下降。

（3）即使是非常短的操作（可能只包含几条指令）也会引起性能的突然下降。



### 3 How about the important related works/papers?

（1）[1, 7, 9]

​	这三篇引用讲了在竞争比较多的时候，non-scalable本身的性能比较低。

（2）[8, 9]

​	这两篇引用分别提出了MCS lock和HCLH lock，这两个锁都是scalable lock。



### 4 What are some intriguing aspects of the paper?

​	对scalable locks的一个反对意见称，non-scalable的行为应该通过修改软件来消除串行执行的性能瓶颈，scalable locks只不过推迟了这种修改。作者也认同这种观点，但是在实际中一次性消除kernel中所有竞争是不现实的。即使kernel在当前是scalable，但当硬件升级后，可能又会有新的scaling bottlenecks。Scalable locks放宽了修改scalability问题的时间限制，在实际应用中很有价值。



### 5 How to test/compare/analyze the results?

​	文章主要是用四个benchmark（FOPS, MEMPOP, PFIND, EXIM）进行测试，绘制出吞吐量随核数增加的变化情况曲线，核数变化从单核到48核。

​	先绘制出Linux下non-scalable的自旋锁情况下，吞吐量随核数增加的变化情况曲线。之后用scalable的MCS locks代替Linux的自旋锁，再绘制出吞吐量的变化曲线。将两者对比得到结论。



### 6 How can the research be improved?

​	本文的实验部分验证了scalable locks在48个核中良好的scalability，但不足以证明scalable locks不会造成系统性能的突然下降，实验需要在更多核数的机器上做实验。并说明当前硬件环境下，实验的结果可以覆盖主流的多核机器的核数。



### 7 If you write this paper, then how would you do?

​	我会争取验证在更多核数的机器上，non-scalable locks的系统性能仍然不会突然下降。如果不能验证，也要说明我的实验结论可以对当前大多数多核机器的核数都适用。



### 8 Did you test the results by yourself? If so,What’s your test Results?

​	暂无



### 9 Give the survey paper list in the same area of the paper your reading.

（1）《Modeling critical sec- tions in Amdahl’s law and its implications for mul- ticore design》

​	这篇文章的前期工作，本文的工作是基于这篇文章的工作发展的。







































