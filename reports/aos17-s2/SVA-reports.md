# Secure Virtual Architecture: A Safe Execution Environment for Commodity Operating Systems

#### Summary of Major Innovations

1. 通过将编译器技术和运行时环境结合起来，在操作系统之下提供了一个安全的执行环境（SVA），更加有效地解决了系统软件和高层应用的安全性问题。
2. 利用了内核中已有的内存池管理方式，将SAFECode实现的对单个C程序的安全性保证方法应用到了内核场景。
3. SVA为保证系统安全性的新的OS设计方法提供了基础，许多OS安全性上的设计革新都需要一个安全的执行环境为其提供支持。【研究意义】

#### The Problems and Motivations

- 由C/C++编写的（商用）系统软件存在众多安全问题
  - OS & OpenSSH & Apache
  - 通过将编译技术和运行时结合起来往往可以很好地解决一大类安全问题
- 一个底层的安全执行环境可以为系统安全设计提供许多新的设计思路，并为这些设计提供必要实现基础

#### Important related works

- **LLVA: A low level virtual instruction set architecture**

  - 虚拟架构的组成与系统结构

    ![img](https://kwinpeng.gitbooks.io/notes-for-advanced-operating-system/content/assets/LLVA.png)

  - 通过将程序语义的表达（Virtual-ISA）和具体的硬件接口（IImplementation-ISA）解耦合，使前者聚焦于程序的行为信息，后者主要实现软件对硬件的控制机制。这样，在V-ISA这一层可以包含更丰富的程序信息用于硬件无关的编译优化和安全性机制的设计等等。

  - 对比SVA的架构可以发现，SVA正是通过扩充位于V-ISA和I-ISA之间的translator这一层的功能，加入了monitor模块以及安全策略验证等功能实现了SVA虚拟机。

- **SAFECode**

  - SAFECode技术的目标是在不使用垃圾回收机制的情况下，通过尽可能使用静态分析技术和必要时的运行时检查来保证程序安全性。
  - SVA用它来提供对单个程序的强安全性保证，包括数组越界检查，内存访问，类型安全，悬垂指针检测等。

#### Some Intriguing Aspects

- Virtual Instruction Set Computer(**VISC**)
- LLVA中对ISA的理解
  - 传统ISA担负着着两种功能：A 软件的持久化符号表示；B 软件控制硬件的接口
  - 存在的问题：传统ISA在程序行为信息方面提供的太少，留给编译器优化的空间太少【个人理解是距离Hardware太近，导致翻译过程中损失了太多的信息，进而使得需要在ISA这一层次上开展的优化/安全机制难以进行】
- Features of this v-ISA【引入了很多有助于编译优化和安全的信息】
  - Typed
  - Use an infinite virtual registers set(in Static Single Assignment form)
  - Provides with explicit control-flow and data-flow information
  - Use low-level operation closely matched with traditional hardware
- Method: **decouple**

#### Survey Paper List

- Adve V, Lattner C, Brukman M, et al. **LLVA:A Low-level Virtual Instruction Set Architecture[C]**Ieee/acm International Symposium on Microarchitecture, 2003. Micro-36. Proceedings. IEEE, 2003:205--216.
- Criswell J, Monroe B, Adve V. **A virtual instruction set interface for operating system kernels[J]**. 2006.
- **Secure virtual architecture: security for commodity software systems**
  - John Criswell's doctoral dissertation

------

#### Appendix. Idioms/Terms on Computer Security

- **exploit**

> An exploit (from the English verb to exploit, meaning "using something to one’s own advantage") is a piece of software, a chunk of data, or a sequence of commands that takes advantage of a bug or vulnerability in order to cause unintended or unanticipated behavior to occur on computer software, hardware, or something electronic (usually computerized). Such behavior frequently includes things like gaining control of a computer system, allowing privilege escalation, or a denial-of-service (DoS or related DDoS) attack.

- **dangling pointer vs. wild pointer**

> The definitions of two and the differences between them. - [wiki](https://en.wikipedia.org/wiki/Dangling_pointer)
>
> A blog using C code to [illustrate](http://www.cnblogs.com/submarine/archive/2013/03/02/2940169.html) this.