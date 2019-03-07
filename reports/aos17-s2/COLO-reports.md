# COLO: COarse-grained LOck-stepping Virtual Machines for Non-stop Service

#### Background & Problems & Motivations

##### 背景：高可用性系统实现不间断服务的解决方案

- 硬件层面
  - 方法：特定的硬件部件和复杂的系统设计
  - 缺点 昂贵 不通用
- 软件层面
  - 方法：运行时，同步备份；失效时，后备服务器替代主服务器继续提供服务
  - 不同层次的实现方案
    - 应用软件层次
      - 需要大量针对性的定制化设计，对旧有软件不适用
    - 操作系统层次
      - 复杂性大大增加，无法商业化
    - 虚拟机
      - 对应用程序和操作系统透明，避免了上述问题
      - 灵活，易用，适用范围广，可扩展性高

##### VM方法存在的问题

- 锁步技术：一条指令复制一次
  - 同步备份带来过高的复制开销
  - 多处理机场景下，执行不确定性指令时lock-step使性能急剧下降
- 检查点技术：在某个时间点复制一次
  - 输出被缓冲，增加了服务延迟
  - 对整个VM执行checkpoint，频繁进行开销太大

##### COLO的方案

- 减弱了虚拟机状态一致性的强约束
  - Primary-VM和Secondary-VM状态之间精确的一致性不是必需的，在保证语义正确的前提下允许一定的差异
  - 约束的弱化为提升系统性能带来了机会

#### Summary of Major Innovations

- 将**输出相似性**作为衡量标准**引入**粗粒度锁步虚拟机，为实现Client-Server系统的不间断服务提供了新的解决方案

- 基于输出相似性，通过放松一致性约束，

  开辟出了新的提升系统性能的优化空间

  - 复制和同步备份是重要的额外开销，一旦PVM和SVM的输出差异达到临界点，都会触发一次从PVM到SVM的备份数据传输
  - 因此提高两者的输出相似性，进而降低数据复制的频率将是提高系统性能的关键，为此SOLO在此方向上做了重点优化
  - SOLO有针对性地使用提高相似性的优化方法，使其相比周期性检查点方案Remus取得了优越的性能表现

#### Important Related Works

- 对TCP/IP协议栈的修改
  - 粗粒度的时间戳，面向单个链接的对比，高确定性的ACK恢复机制，发送窗口大小等
  - 目的是提升输出相似性
- Remus周期性的Checkpoints
  - 改进了Remus被动的检查点机制使其支持COLO需要的主动检查点机制
  - 增量式Checkpoints减少传输流量
- Xen虚拟化平台
  - todo

#### Survey Paper List

- Barham P, Dragovic B, Fraser K, et al. **Virtual machine monitors: Xen and the art of virtualization[J]**. *Symposium on Operating System Principles*, 2003, 36(August):164--177.

#### Some Question

1. SOLO通过对比PVM和SVM输出的相似性来判断两者的状态是否出现了显著的差异，如果是则重置SVM；但是如果该差异是由于PVM出现系统抖动导致的，重置SVM其实并没有道理？ *SOLO的目标是fail-stop failure*
2. 由1引申出，SVM作为失效备份只需保证其状态在PVM正常状态抖动的范围内即可，相似性对比可以看作实现该保证的一个措施，那么在更高的层次上（比如语义层次上），是否存在进一步放松约束的方法呢？