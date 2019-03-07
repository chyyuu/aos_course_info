# Report for the paper: PF-Miner

## Summary of major innovations

本文主要创新点在于：基于统计的方法在Linux kernel driver中寻找配对的(paired)的函数。这些函数在正常执行路径和错误执行路径是配对出现的。本文提出了一个有效的工具PF-Miner，可以自动地找出driver中的paired functions，此外还能自动地发现违背配对规则的情况，并选择出具备较大概率的bug。在Linux Kernel 2.6.39到3.10.0，有81个PF-Miner报告出的bug被fix。在3.10.0版本的内核中，983个violation被发现，报告了51个bug给内核community，其中15个被证实是bug。

## Problems this paper mentioned

Linux将driver部分代码放入内核中，这部分代码bug的数量是其他部分的3到7倍，在商用操作系统中，由driver导致的crash占了85。在driver内部中，经常需要申请资源权限等，在失败的情况下，需要释放这些资源。可是由于人为原因，很可能driver开发者没有在错误处理路径中释放资源，这引入了bug。本文致力于解决在正常执行路径和异常处理路径中挖掘Paired functions并基于此检测内核driver中其他违背该规则的部分代码，作为潜在的bug分析并报告给内核开发团队。

## Some intriguing aspects of this paper

PF-Miner过程如下图所示：

在获取配对函数时，本文使用了比较简单但实用的方法来判断两个函数pair的概率：
1. 两个函数名字完全相同，概率最小
2. 两个函数按照下划线划分后，包含了两个反义词或者一个反义词，认为概率最大
3. 按照LCS：最长公共子串
