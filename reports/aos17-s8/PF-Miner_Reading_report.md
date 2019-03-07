# PF-Miner: A new paired functions mining method for Android kernel in error paths

## Summary of major innovations

作者开发出了一种基于数据挖掘和统计模型的工具来挖掘程序源码（C语言）中的成对函数，以此来挖掘出代码中潜在的风险、漏洞。作者用该工具对安卓内核进行了挖掘，用较短的挖掘时间得到了令人满意的结果。

## What the problems the paper mentioned?

驱动程序是一个操作系统的重要组件，通常来说，驱动会在内核模式下运行，需要进行很多错误处理，大部分情况下错误处理路径和程序正常执行路径是成对出现的，当由于程序员的疏忽等原因导致本应有的错误处理并没有时，就有可能造成内存泄漏等风险，同时这种情况的一个特征就是没有与正常执行路径配对的错误处理路径，所以我们可以通过这一现象来挖掘程序中的潜在漏洞。

## How about the important related works/papers?

相关领域中，很多学者提出要提高驱动的可靠性并且也做出了相应的尝试工作，例如说Nooks、Shadow Driver、FGFT等，同时也有人在尝试使用符号执行来进行漏洞挖掘，例如S2E、SymDrive等。  
对于成对函数，Engler提出了一种叫做ECC的方法来用模版提取出成对函数，PR-Miner使用数据挖掘方法提取出大型软件中隐含的编程规则，它也可以找到最长的执行路径。另外，还有诸如Icomment、WYSIWIB、CAR-Miner、WN-Miner等众多方法被提出来解决不同问题。

## What are some intriguing aspects of the paper?

在本文中作者从一个新颖的角度来理解漏洞挖掘。通过检查源码中程序执行路径的配对关系，进而发掘程序的潜在漏洞。这种做法的优点也比较明显，它可以在短时间内发现较多的漏洞，不同于动态执行，这种基于静态代码审计的漏洞挖掘程序能够用更快的时间发现漏洞。

## How to test/compare/analyze the results?

作者在实现了PF-Miner之后，使用它对安卓内核（2.6.39）进行了挖掘，挖掘结果中的81个漏洞已经被证实并且在最新版内核（3.10.0）之前得到了修复，另外，作者把51个威胁报告给了开发者，其中15个被确认为存在漏洞。
## How can the research be improved?

PF-Miner目前只支持C语言，还可以让其支持更多语言，以此提高PF-Miner的适用范围。从挖掘结果来看，潜在风险中只有少部分被证实成为了真正的软件漏洞，所以PF-Miner漏洞挖掘的精确度应当还可以提高。

## If you write this paper, then how would you do?

我会再提供多一些试验来证明工具的有效性，同时如果可以的话会开发出不同语言版本的PF-Miner，基于多种语言选择几个典型程序源码进行漏洞挖掘、分析结果。
## Give the survey paper list in the same area of the paper your reading.

> V.Chipounov,V.KuznetsovandG.Candea,“S2E:Aplatform for in-vivo multi-path analysis of software systems,” Proc. Intl Conf. Architectural Support for Programming Languages and Operating Systems (ASPLOS ’11), vol. 39, pp. 265-278, Mar. 2011.