# “The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors”-reading-report

### 1 Summary of major innovations

​	接口（API）的设计对实现的可扩展性有很重要的影响。本文定义了一种规则——Scalable Commutativity Rule，并据此写了一个工具——COMMUTER，这个工具可以指导开发人员设计API，使得接口可扩展性更强。

​	本文的主要创新在于：

（1）传统的研究可扩展性的方法都是针对实现进行多轮的测试和修改，而本文从API的设计这个很高的level去研究最后实现的可扩展性。

（2）研究了特定状态下的可扩展性（特定的系统状态、特定的操作参数、特定的并行执行的指令等），使得COMMUTER的适用范围大大增加。

### 2 What the problems the paper mentioned?

​	研究可扩展性等传统方法是在已有实现的基础上，运行在多核环境下进行测试，然后找到性能瓶颈，对代码进行修改，然后再测试、修改，不断迭代。这样的工作费时费力，有些时候会发现在接口的设计上就存在问题。

### 3 How about the important related works/papers?

##### （1）disjoint- access-parallel memory systems [26]

​	这篇文章提出了一个原理：如果共享内存可以并行不相交访问，而且一组进程访问不相交的内存位置，那么这些进程的可扩展性是线性的。

##### （2）An iterative process to improve scalability: design, implement, measure, repeat [12]

​	介绍了传统的提高可扩展性的方法：迭代设计、实现、测试。

### 4 What are some intriguing aspects of the paper?

​	这篇文章最有意思的点就是Scalability Commutativity Rule，作者提出并证明了这个rule的正确性，这部分理论证明是文章最核心的点。

### 5 How to test/compare/analyze the results?

​	使用POSIX中18个文件系统的接口，与Linux对比，测试数据是COMMUTER根据接口生成的一万多个测试样例，对比sv6与Linux在这些测试样例中发生的冲突数。

### 6 How can the research be improved?

​	将COMMUTER应用到Linux kernel的开发中，本文是基于xv6，用COMMUTER改了文件系统，做成sv6。如果可以在Linux广泛应用，可以对kernel的可扩展性有很大的提高，使Linux更适应于分布式环境。

### 7 If you write this paper, then how would you do?

​	本文只对POSIX标准的18个文件系统接口进行实验，与Linux的实现对比，可以进行更多的实验，做进一步的数据分析。

### 8 Did you test the results by yourself? If so,What’s your test Results?

​	暂无。

### 9 Give the survey paper list in the same area of the paper your reading.

​	暂无。































