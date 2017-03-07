
### OS Architecture
 - [The Structure of the "THE"-Multiprogramming System](http://uosis.mif.vu.lt/~liutauras/books/Dijkstra%20-%20The%20structure%20of%20the%20THE%20multiprogramming%20system.pdf)
Edsger W. Dijkstra ,Technological University, Eindhoven, The Netherlands, SOSP, 1968
 - [Exokernel: An Operating System Architecture for Application-Level Resource Management](http://flint.cs.yale.edu/cs428/doc/p251-engler.pdf), Dawson R. Engler, M. Frans Kaashoek, and James O’Toole Jr. MIT,  SIGOPS ’95, 1995
    - [jos project](https://pdos.csail.mit.edu/6.828/2016/labguide.html)
 - [Singularity: Rethinking the Software Stack](http://research.microsoft.com/pubs/69431/osr2007_rethinkingsoftwarestack.pdf) Galen C. Hunt and James R. Larus, Microsoft Research Redmond, OSR2007, 2007
    - [Singularity OS project](https://www.microsoft.com/en-us/research/project/singularity/) 
 - [The Evolution of the Unix Time-sharing System](http://www.read.seas.harvard.edu/~kohler/class/aosref/ritchie84evolution.pdf)Dennis M. Ritchie, Bell Laboratories, 1984
    - [xv6 project](https://pdos.csail.mit.edu/6.828/2016/xv6.html)
    - [related info:The Unix-Haters Handbook (1994)](http://web.mit.edu/~simsong/www/ugh.pdf)
 - [Extensibility, Safety and Performance in the SPIN Operating System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.41.7509&rep=rep1&type=pdf), Brian N. Bershad,etc.University of Washington, 1995
 - [Secure Virtual Architecture: A Safe Execution Environment for Commodity Operating Systems](http://sosp2007.org/papers/sosp139-criswell.pdf), John Criswell, Andrew Lenharth, Dinakar Dhurjati, and Vikram Adve,University of Illinois at Urbana–Champaign, SOSP07, 2007
     - [SVA project](https://github.com/jtcriswell/SVA)

### Process&Thread&Scheduling
 - [Lottery Scheduling: Flexible Proportional-Share Resource Management](https://www.usenix.org/legacy/publications/library/proceedings/osdi/full_papers/waldspurger.pdf), OSDI94
 - [Stride Scheduling: Deterministic Proportional-Share Resource Management](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.138.3502) tech report, 1995
 
### Memory Management
 - [Memory Resource Management in VMware ESX Server](http://dl.acm.org/citation.cfm?id=844146), OSDI02
 
### Sync&Mutex
 - [Scalable Read-mostly Synchronization Using Passive Reader-Writer Locks.](http://ipads.se.sjtu.edu.cn/_media/publications/prwlock-atc14.pdf),Usenix ATC 2014
 
### Virtual Machine Monitor
 - [Dune: Safe User-level Access to Privileged CPU Features](https://www.usenix.org/system/files/conference/osdi12/osdi12-final-117.pdf) OSDI 2012.
    - [dune project](http://dl.acm.org/citation.cfm?doid=2872362.2872389)
 - [ IX: A Protected Dataplane Operating System for High Throughput and Low Latency](http://courses.cs.washington.edu/courses/cse551/15sp/papers/ix-osdi14.pdf), OSDI 2014.
    - [IX project](https://github.com/ix-project/ix)

### File System
 - [ All File Systems Are Not Created Equal: On the Complexity of Crafting Crash-Consistent Applications](http://courses.cs.washington.edu/courses/cse551/15sp/papers/alice-osdi14.pdf)OSDI 2014. 
 - [Rethink the Sync](https://www.usenix.org/legacy/event/osdi06/tech/nightingale/nightingale.pdf), OSDI 2006.
 
### Multicore & Scalability
 - [Non-scalable locks are dangerous](https://pdos.csail.mit.edu/papers/linux:lock.pdf) Linux Symposium 2012.
 - [scalable Kernel TCP Design and Implementation for Short-Lived Connections](http://dl.acm.org/citation.cfm?doid=2872362.2872391), ASPLOS 2016
     - [fastsocket project](https://github.com/fastos/fastsocket)
 - [Scalable Address Spaces Using RCU Balanced Trees](http://courses.cs.washington.edu/courses/cse551/15sp/papers/bonsai-asplos12.pdf), ASPLOS 2012
 - [mTCP: a Highly Scalable User-level TCP Stack for Multicore Systems](http://www.ndsl.kaist.edu/~kyoungsoo/papers/mtcp.pdf), NSDI 2014
     - [mtcp project](http://shader.kaist.edu/mtcp/)

 

### Finding Bugs &Security
 - [KLEE: Unassisted and Automatic Generation of High-Coverage Tests for Complex Systems Programs](http://courses.cs.washington.edu/courses/cse551/15sp/papers/klee-osdi08.pdf), OSDI 2008.
     - [KLEE project](http://klee.github.io/)
 - [PF-Miner: A New Paired Functions Mining Method for Android Kernel in Error Paths](http://ieeexplore.ieee.org/xpl/login.jsp?tp=&arnumber=6899198&url=http%3A%2F%2Fieeexplore.ieee.org%2Fxpls%2Fabs_all.jsp%3Farnumber%3D6899198), COMPSAC 2014
 - [· RID: Finding Reference Count Bugs with Inconsistent Path Pair Checking](http://dl.acm.org/citation.cfm?doid=2872362.2872389), ASPLOS 2016


### API 
 - [Mars Code](http://dl.acm.org/citation.cfm?id=2556647.2560218) Magazine Communications of the ACM CACM Homepage archive
Volume 57 Issue 2, February 2014 Pages 64-73 
 - [The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors](http://courses.cs.washington.edu/courses/cse551/15sp/papers/commutativity-sosp13.pdf), SOSP 2013.
     - [commuter project](https://github.com/aclements/commuter)
 - [MegaPipe: A New Programming Interface for Scalable Network I/O](http://www.eecs.berkeley.edu/~sylvia/papers/osdi2012_megapipe.pdf), OSDI 2012.
 
 ### Verification
 - [seL4: Formal Verification of an OS Kernel](http://www.sigops.org/sosp/sosp09/papers/klein-sosp09.pdf) SOSP 2009.
     - [seL4 project](https://github.com/seL4)
 - [Jitk: A Trustworthy In-Kernel Interpreter Infrastructure](https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-wang_xi.pdf) OSDI 2014.
     - [jitk project](http://css.csail.mit.edu/jitk/)
