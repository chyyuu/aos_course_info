# The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors

#### Background & Problem & Motivation

##### 多核背景下的可扩展性问题

- 通常增强软件可扩展性的方法依赖于开发人员投入大量的精力，不断地进行性能测试，分析限制可扩展性的瓶颈，逐一解决，问题是
  - 不同的工作负载下，同一实现表现出不同的可扩展性能
  - 随着核数的增加，新的可扩展性瓶颈会被暴露出来
  - 限制可扩展性的根源可能在接口设计上

##### 本文的解决思路

- 传统上，可扩展性通常被看作是与具体实现相关的问题，而非接口的属性
  - 状态相关
- 同一个标准有多种多样的实现方式
  - 如果从实现的层次上考虑可扩展性，将会陷入众多实现细节带来的问题中，而这些问题可能并不是表达标准所必须的
  - 如果从接口的层次上考虑可扩展性，则可以将繁杂的实现细节屏蔽掉，有利于更加精确地分析，在保证符合标准的前提下限制接口可扩展性的瓶颈所在；并且反过来，这同样也是对接口设计进行的一种评估
- 接口驱动的可扩展性分析在软件开发的全周期都能起到指导作用
  - 设计环节，以提高可扩展性为指导进行接口设计
  - 实现环节，明确了一个清晰的实现目标
  - 测试环节，系统的工作负载无关的可扩展性测试

#### Summary of Major Innovations

- 提出了形式化的Scalable Commutativity Rule，并对其正确性进行了证明
  - SI SIM 构造性证明
- 实现了COMMUTER，一个自动化的可扩展性测试工具
  - Analyzer TestGen Mtrace
- 在SIM规则的指导下设计实现了具有良好可扩展性的POSIX内核
  - sv6

#### Understanding to the Commutativity Rule

- ##### Commutativity

  - 在分析并发性的场景中，可交换性被用来估计conflict-free；在数据库领域，可交换性被用来评估事务在交错执行后是否能够保证Serializability，这些研究关注于并发执行可交换操作时的正确性，而非可扩展性。
  - commutativity -> conflict-free -> scalability
    - 如果操作可交换，则最终的结果与它们的执行顺序无关，即意味着这些操作之间的通信是没有必要的，去掉这些通信则可以实现conflict-free，在现在的共享内存的多核系统上，conflict-free的操作可以完全执行在单独的某个核上，因此当核数增加时，此类操作将会展现出近线性的可扩展性能。

- ##### Specification

  - > A specification is a prefix-closed set of well-formed histories.The specification distinguishes whether or not a history is correct.The specification distinguishes whether or not a history is correct.

    在接口层次上对接口正确性的抽象，在不涉及具体实现细节的情况下，评估某种执行序列所产生结果的正确性。可以看作是在同一执行上下文中，能过产生正确结果的所有执行序列的集合。

  - 例如，POSIX标准

- ##### Reorder

  - > An action sequence, or region, H' is a reordering of an action sequence H when H|t = H'|t for every thread t.

    Reorder之后每个线程的执行序列与reorder前保持一致，在保证此条件的情况下，对多个线程interleave的方式没有要求。

- ##### SI-Commute

  - 定义表现出的两种性质：状态相关性和基于接口的性质
  - 具体来看定义中的三个序列
    - 序列X将系统置于特定的某个状态，同时这个过程由action表达，并不涉及借口的具体实现
    - 序列Y和Y'反映出对specification的遵守，保证了reorder之后的正确性
    - 序列Z表明，Y和Y‘的重排不应让后续操作有所察觉
  - SI-Commute的不足：没有保证单调性

- ##### SIM-Commute

  - 基于SI rule，解决了单调性问题，同时新添加的约束足够证明commutativity rule

#### Proof of the Rule

- ##### 方法：构造性证明

  - 在数学中，构造性证明是证明方法的一种，通过直接或间接构造出具有命题所要求的性质的实例来完成证明。
  - 与构造性证明相对的概念是非构造性证明（有时也称为存在性证明或纯粹存在性证明），后者只证明满足命题要求的物体存在，而不提供具体的实例或构造这样的实例的方法。

- ##### 构造一个不可扩展的实现

  - 开始于重放模式：对于该实现，只要每次调用匹配到历史调用，只需返回历史中对应的正确响应即可，此时不需要调用参考实现；反之，当该调用不同于历史调用时，就会进入模拟模式，此时需要通过调用参考实现，并将之前的调用历史给其作为输入，使其达到所需的状态。之后只需将收到的所有调用传递给参考实现，得到响应，输出即可。
  - 这样构造出的实现是正确的：因为它所有的输出响应基于历史，而这总是与参考实现相匹配的。但是，这并不是可扩展的实现，因为在重放模式下，任意两个对的访问都会产生冲突。事实上，正是依靠对已发生调用的访问追踪，才可以初始化参考实现的状态，进而实现模拟。因此，对的互斥访问限制了的可扩展性。

- ##### 构造一个可扩展的实现

  - SIM 的定义表明如果满足SIM-Commutative性质，那么历史调用动作的顺序就不会产生影响，因此，对的访问就可以不必保持一致，只要这些调用动作的顺序在满足可交换性的集合内即可，由此说明，满足了可交换性就带了可扩展性。

#### Important Related Works

- 对可扩展性问题的思考
  - disjoint-access-parallel memory system
  - Laws of Order
  - cache-line contention
- 可扩展操作系统内核设计实践与技术
  - Refcache，一个可扩展的引用计数方案
  - RadixM，基于基数树的可扩展虚拟内存系统
  - ScaleFS，可扩展文件系统，通过实现大多数文件操作的可交换

#### Survey Paper List

- **The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors** Austin T. Clements. Ph.D. thesis, Massachusetts Institute of Technology, June 2014.
- ***An analysis of Linux scalability to many cores.*** S. Boyd-Wickizer, A. Clements, Y. Mao, A. Pesterev, M. F. Kaashoek, R. Morris, and N. Zeldovich.OSDI-10