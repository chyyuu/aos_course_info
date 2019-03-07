# 证明的理解The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors 

对于给定的规范和一个参考实现，若参考实现能产生一个执行历史H=X||Y，这个执行历史满足SIM-commute,则存在一个满足规范的实现，且它在Y中部分的执行是无冲突的



先考虑构造一个non-scalable但满足正确性的实现m_ns,m_ns的每个状态有两个部分，s.h表示在replay模式先历史H中还未被replay的部分，或者表示处于EMULATE状态。s.refstate表示参考实现的状态

m_ns(s,a):

当m_ns在状态s下，收到一个a调用时，

if(s.h表示未被重现的历史H且开头为a) {

则说明之前的调用都是符合历史H的，现在是刚调用a，返回CONTINUE

}

else if a = CONTINUE 且s.h的头部是一个返回 {

说明符合H，且恰好应该返回调用的结果，即s.h的开始

}

else if s.h ！= EMULATE {

H的重现结束了或者输入和H不一致

从这里开始进入EMULATE状态，生成一个和当前s.h的执行历史一致的历史H',将H'中已有的调用先填入s.refstate中，等后面会更新状态

}

开始更新状态

if s.h == EMULATE {

将参考实现 中的状态和相应的动作M(s.refstate, a)填入s.refstate

}

else {

s.h中移除已经匹配并重现的部分

}

上面构造生成的m_ns是正确的，当不同线程都对s.h进行了读写，产生了争用，又因为在H中不同的线程是可以交换执行的，因此让每个线程拥有自己replay的部分H



m(s,a):

找到调用对应的线程t

if  t的s.h[t]是COMMUTE {

进入了可交换区域，s.commute[t]置为TRUE，s.h[t]后移，开始replay

}

if(s.h表示未被重现的历史H且开头为a) {

则说明之前的调用都是符合历史H的，现在是刚调用a，返回CONTINUE

}

else if a = CONTINUE 且s.h的头部是一个返回 {

说明符合H，且恰好应该返回调用的结果，即s.h的开始

}

else if s.h ！= EMULATE {

H的重现结束了或者输入和H不一致

从这里开始进入EMULATE状态，生成一个和当前s.h的执行历史一致的历史H',将H'中已有的调用先填入s.refstate中，所有线程的s.h置为EMULATE

}

开始更新状态

if s.h == EMULATE {

将参考实现 中的状态和相应的动作M(s.refstate, a)填入s.refstate

}

else if s.commute {

处于t的可交换去，将已经匹配的部分删掉

}

else {

所有线程s.h中移除已经匹配并重现的部分

}