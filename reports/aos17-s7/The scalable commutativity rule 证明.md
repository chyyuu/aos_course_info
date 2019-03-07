# The scalable commutativity rule 证明

#### 1 证明目标

​	首先明确一下我们要证明的东西：若一个接口符合SIM Commutativity，那么存在一个scalable的实现。

#### 2 大体方法 

​	要证明这个东西，作者的方法通过：

​	（1）接口的任意参考实现（这个参考实现不需要scalable，只需要能根据输入得到正确的输出即可，也就是实现了接口的定义）；

​	（2）一个操作历史H=X||Y，用于构造出我们要考虑的state。

​	来构造出一个实现，这个实现是scalable的。

#### 3 构造方法 

​	文章用了两个实现来阐述构造方法，第一个实现是non-scalable的，用来阐述这个构造方法能够正确的实现接口的功能；第二个实现在第一个实现的基础上根据SIM Commutativity的性质增加了scalability。

##### （1）Non-scalable实现

​	这个实现有两步：

​	第一步，和操作历史H的invocation相符的时候，直接复制H的response，直到H结束或者某个操作与H不相符，进入第二步。

​	第二步，将之前的invocation历史输入到参考实现，然后用参考实现继续得到正确的response。

​	因为各个thread的先后顺序需要记录，所以该实现non-scalable。

##### （2）Scalable实现

​	与上一个实现不同的一点在于，这个实现

​	（1）在不符合SIM Commutativity的操作历史X部分，与上面完全一样。

​	（2）在符合SIM Commutativity的操作历史Y部分，每个thread只记录自己thread的invocation顺序，当出现invocation与H不符合时，只用讲自己线程的invocation历史输入到参考实现，即可获得输出。因为符合SIM Commutativity，所以不用管其他thread，不需要通信，所以scalable。

































