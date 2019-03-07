# PF-Miner：A New Paired Functions Mining Method for Android Kernel in Error Paths-reading-report

### 1 Summary of major innovations

（1）本文对驱动的源代码的bug进行检测和修改，使用驱动接口的开发人员不需要修改任何代码。

（2）本文是第一篇提出检测正常执行路径和异常执行路径的pair function方法的文章。

（3）使用了数据挖掘和统计学的方法来检测bug。

### 2 What the problems the paper mentioned?

​	在Android kernel的源码中，驱动程序占了很大的比例，85%的系统崩溃是由驱动程序造成的。在函数中，正常的执行路行一般会将资源处理得比较好。但是在异常的执行路径上，会由于doc和经验不足等原因，导致开发人员没能很好地将之前申请的资源回收，这会引起内存泄漏、死锁、系统崩溃等问题。

### 3 How about the important related works/papers?

（1）提高driver可靠性的工作：Nooks、Shadow Driver、FGFT等。但是几乎没有直接研究driver中pair function的。

（2）使用数据挖掘方法进行debug的工作：ECC、PR-Miner等。

（3）数据挖掘的输入：比如Icomment检测源码和注释的不一致性；WYSIWIB将控制流图作为输入。

（4）提高异常执行路径的容错性：CAR- Miner、WN-miner等。

### 4 What are some intriguing aspects of the paper?

​	本文最新奇的地方在于使用了数据挖掘的方法去对源码进行debug，通过函数名匹配、位置匹配等方法去找到pair function。

### 5 How to test/compare/analyze the results?

（1）作者对Android Kernel 2.6.39进行debug，检测到的81个bug在3.10.0版本中都得到修复。

（2）作者对Android Kernel 3.10.0进行检测，将检测到的983个violation里最有可能是bug的51个，向这些代码的开发者发邮件，其中15个被开发者确认为bug。

### 6 How can the research be improved?

​	PF-Miner在本文中用于C语言编写的大型程序的violation检测，但这个工具是general的，可以推广到其他语言，比如C++等。

### 7 If you write this paper, then how would you do?

​	测试更多的代码，让结果看起来更多一些。



































