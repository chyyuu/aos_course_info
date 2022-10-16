* EXPLODE: a Lightweight, General System for Finding Serious Storage System Errors
    * * **Bugs as Deviant Behavior: A General Approach to Inferring Errors in Systems Code**
    * 可以自动推断代码中的 belief 然后寻找违反 belief 的地方
    * belief 形如 “unlock 似乎应该和 lock 成对使用”
    * 但是必须人手写给出 a 和 b 成对使用，自动推断的是 a 和 b
* **Towards Automatic Discovery of Deviations in Binary Implementations with Applications to Error Detection and Fingerprint Generation**
    * 01 年的论文通过把二进制程序编译成 smt formula 来找 deviation
    * eval 评测了 http server 和 ntp server
    * 提到 diff 需要 domain specific knowledge -> 当然的但是 wt ab os？
* Detecting Missing-Check Bugs via Semantic- and Context-Aware Criticalness and Constraints Inferences
    * * **SymCerts: Practical Symbolic Execution For Exposing Noncompliance in X.509 Certificate Validation Implementations**
    * 用符号执行来发现 x509 证书链确认逻辑的实现有那些地方没有遵照规范
    * 类似 juxta 也是用符号执行拿到路径和路径条件，也有 cross check
    * 他的输出输入很简单，输入就是 certificate chain 的字节流，输出就是一个 accept/reject
    * cross-check：检查是否 sat? (A_i^p /\ R_j^q) 就是 p 实现 accept 但是 q reject
    * 用了 klee 检查 9 个 x509 impl 发现 48 个 noncompilance
* Mining Security Critical Linear Temporal Logic Specifications for Processors
    * * Code Vectors: Understanding Programs Through Embedded Abstracted Symbolic Traces
    * * Finding Semantic Bugs in File Systems with an Extensible Fuzzing Framework
    * * **Static Error Detection using Semantic Inconsistency Inference**
    * 用类型推断作 inconsistency inference
    * 实现了 C 的 npd inference
    * 还是不能做 general belief inference，需要手写 belief scheme
* **Cross-checking Semantic Correctness: The Case of Finding File System Bugs**
    * 需要在同样的 vfs 框架下，在函数粒度 cross check
    * 依赖于 struct inode 等等共同点
    * 符号执行拿到 path + path condition 然后分析副作用、对 flag 的使用
* **SPINFER: Inferring Semantic Patches for the Linux Kernel**
    * atc20，类似 seda
    * 从具体 patch 推断出 semantic patch
    * 和我们的予以推断没有关系
* **MUVI: Automatically Inferring Multi-Variable Access Correlations and Detecting Related Semantic and Concurrency Bugs**
    * 用过程间分析、流不敏感分析得到变量的访问相关性
    * 通过访问相关性直接解决 inconsistent update bug
    * 拓展 lockset 和 happenbefore、加入访问相关性让并发 bug 能探测到多变元的
    * 这个推断可以，但是怎么用到我们想做的 os spec / 规则推断上？
* **code2vec: Learning Distributed Representations of Code**
* **Practical, low-effort equivalence veriﬁcation of real code**
    * uc-klee 的论文，检查等价性是在函数粒度
    * 符号执行，把函数的 arg 最初都是 unconstrained。
    * 在 error path 上让另一个 impl 也执行检查是否一样的 error，在 success path 上检查副作用（写的内存块）是否一致
    * evaluation 做了 uclibc vs newlib、不同版本的 uclibc、编译加不加优化
* **Under-constrained symbolic execution: Correctness checking for real code**
    * uc-klee 的续作，改进 uc-klee 加入 synthesis on the fly
    * 等价检测：patch e.g.  ASSERT old(arg) == new(arg)
* **DistAI: Data-Driven Automated Invariant Learning for Distributed Protocols**
    * 推断分布式算法的 invariant，使用数据驱动的统计方法
    * 在 model 层面而不是 impl 层面作
* **EMI Testing: Finding 1000+ Bugs in GCC and LLVM in 3 Year**
    * 其实是一系列工作，找编译器 bug
    * 生成测例的方法非常好，mutate 没有运行的程序部分然后应该 equivalent modulo input
    * 不能移植到 os 上
* **Will You Still Compile Me Tomorrow? - Static Cross-Version Compiler Validation**

## bug analysis
- A Study of Linux File System Evolution
- An Empirical Study of Operating Systems Errors
- Faults in Linux: Ten Years Later
- An empirical study of optimization bugs in GCC and LLVM
- Toward Understanding Compiler Bugs in GCC and LLVM
