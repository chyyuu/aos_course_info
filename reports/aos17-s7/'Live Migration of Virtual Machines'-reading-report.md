# 'Live Migration of Virtual Machines'-reading-report

### 1 Summary of major innovations

​	本文主要的新方法是pre-copy迁移技术，它综合考虑并权衡了停机时间和迁移时间。

### 2 What the problems the paper mentioned?

​	本文研究的是数据中心的机器在运行时的动态迁移，本文提出并解决的问题如何将迁移过程中的停机时间和迁移时间都尽量缩短。

### 3 How about the important related works/papers?

（1）Collective project：比较早的提出了VM迁移的问题，为用户提供一个可以在不同物理机之间迁移的工具。但是这个工作会停机较长一段时间。

（2）Zap：采用部分OS虚拟化提高速度，但并没有解决动态迁移。

（3）NomadBIOS：本文很多工作继承于此，基于L4微内核开发，提出了pre-copy。但没有解决迁移过程中的写入操作。

### 4 What are some intriguing aspects of the paper?

​	pre-copy的轮数设定。

### 5 How to test/compare/analyze the results?

​	使用SPEC提供的程序，在运行过程中动态迁移，记录停机时间与迁移时间，与其他的项目做对比。

### 6 How can the research be improved?

​	将存储、块设备的迁移也考虑进来。

### 7 If you write this paper, then how would you do?

​	增加一些理论分析，比如计算一下优化的上界。

### 8 Did you test the results by yourself? If so,What’s your test Results?

​	暂无。

### 9 Give the survey paper list in the same area of the paper your reading.

​	暂无。

​	