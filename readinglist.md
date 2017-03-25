
### OS Architecture
 - [The Structure of the "THE"-Multiprogramming System](http://uosis.mif.vu.lt/~liutauras/books/Dijkstra%20-%20The%20structure%20of%20the%20THE%20multiprogramming%20system.pdf)
Edsger W. Dijkstra ,Technological University, Eindhoven, The Netherlands, SOSP, 1968
 - [On Micro-Kernel Construction](http://zoo.cs.yale.edu/classes/cs422/2010/bib/liedtke95micro.pdf),ACM SIGOPS Operating Systems Review 29(5):237-250 · December 1995
 - [Exokernel: An Operating System Architecture for Application-Level Resource Management](http://flint.cs.yale.edu/cs428/doc/p251-engler.pdf), Dawson R. Engler, M. Frans Kaashoek, and James O’Toole Jr. MIT,  SIGOPS ’95, 1995
    - [jos project](https://pdos.csail.mit.edu/6.828/2016/labguide.html)
 - [Singularity: Rethinking the Software Stack](http://research.microsoft.com/pubs/69431/osr2007_rethinkingsoftwarestack.pdf) Galen C. Hunt and James R. Larus, Microsoft Research Redmond, OSR2007, 2007
    - [Singularity OS project](https://www.microsoft.com/en-us/research/project/singularity/) 
 - [The UNIX Time-Sharing System](http://pdos.csail.mit.edu/6.828/2014/readings/ritchie78unix.pdf),The Bell System Technical Journal 57 no. 6, part 2 (July-August 1978)
 - [The Evolution of the Unix Time-sharing System](http://www.read.seas.harvard.edu/~kohler/class/aosref/ritchie84evolution.pdf)Dennis M. Ritchie, Bell Laboratories, 1984
    - [xv6 project](https://pdos.csail.mit.edu/6.828/2016/xv6.html)
    - [related info:The Unix-Haters Handbook (1994)](http://web.mit.edu/~simsong/www/ugh.pdf)
 - [Extensibility, Safety and Performance in the SPIN Operating System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.41.7509&rep=rep1&type=pdf), Brian N. Bershad,etc.University of Washington, 1995
 - [Secure Virtual Architecture: A Safe Execution Environment for Commodity Operating Systems](http://sosp2007.org/papers/sosp139-criswell.pdf), John Criswell, Andrew Lenharth, Dinakar Dhurjati, and Vikram Adve,University of Illinois at Urbana–Champaign, SOSP07, 2007
     - [SVA project](https://github.com/jtcriswell/SVA)
 
### Process&Thread&Scheduling
 - [Lottery Scheduling: Flexible Proportional-Share Resource Management](https://www.usenix.org/legacy/publications/library/proceedings/osdi/full_papers/waldspurger.pdf), OSDI94
 - [Stride Scheduling: Deterministic Proportional-Share Resource Management](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.138.3502) tech report, 1995
 - [Supporting Time-Sensitive Applications on a Commodity OS](http://www.eecg.toronto.edu/~ashvin/publications/osdi2002.pdf),OSDI2002
 - [Borrowed-Virtual-Time (BVT) scheduling: supporting latency-sensitive threads in a general-purpose scheduler](http://www.read.seas.harvard.edu/~kohler/class/04f-aos/ref/duda99borrowed.pdf)SOSP1999
 - [Improving Performance Isolation on Chip Multiprocessors via an Operating System Scheduler](https://dash.harvard.edu/bitstream/handle/1/10065537/Improving%20Performance%20Isolation2007%20(1).pdf?sequence=1),PACT2007
 - [A Hierarchical CPU Scheduler for Multimedia Operating Systems](http://www.cs.columbia.edu/~nieh/teaching/e6118_s00/papers/goyal_osdi96.pdf),OSDI1996
 - [Reinventing scheduling for multicore systems](https://pdos.csail.mit.edu/papers/o2:hotos12.pdf),HOTOS 2009
 - [Addressing shared resource contention in multicore processors via scheduling](http://www.cs.sfu.ca/~fedorova/papers/asplos212-zhuravlev.pdf),ASPLOS2010

### Memory Management
 - [The working set model for program behavior](http://denninginstitute.com/pjd/PUBS/WSModel_1968.pdf),In Communications of the ACM 11(5), May 1968.
 - [WSClock - A Simple and Effective Algorithm for Virtual Memory Management](https://www.researchgate.net/publication/220909958_WSClock_-_A_Simple_and_Effective_Algorithm_for_Virtual_Memory_Management),ACM SIGOPS Operating Systems Review 15(5):87-95 · December 1981
 - [Simple But Effective Techniques for NUMA Memory Management](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.380.3461&rank=1),SOSP 1989
 - [TreadMarks: Distributed Shared Memory on Standard Workstations and Operating Systems](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.27.9177&rank=9),IN PROCEEDINGS OF THE 1994 WINTER USENIX CONFERENCE,1994
 - [The Slab Allocator: An Object-Caching Kernel Memory Allocator](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.143.4374&rank=1), USENIX SUMMER TECHNICAL CONFERENCE , 1994
 - [Memory Resource Management in VMware ESX Server](http://dl.acm.org/citation.cfm?id=844146), OSDI2002
 - [Mnemosyne: Lightweight Persistent Memory](http://research.cs.wisc.edu/sonar/papers/mnemosyne-asplos2011.pdf),ASPLOS2011

 
### Sync&Mutex
 - [Algorithms for Scalable Synchronization on Shared-Memory Multiprocessors](http://www.cs.rice.edu/~johnmc/scalable_synch/tocs91.pdf),ACM Transactions on Computer Systems, Feb. 1991.
 - [Scalable Read-mostly Synchronization Using Passive Reader-Writer Locks.](http://ipads.se.sjtu.edu.cn/_media/publications/prwlock-atc14.pdf),Usenix ATC 2014
 - [Non-scalable locks are dangerous](https://pdos.csail.mit.edu/papers/linux:lock.pdf) Linux Symposium 2012.
 - [Tornado: Maximizing Locality and Concurrency in a Shared Memory Multiprocessor Operating System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.53.2410&rep=rep1&type=pdf),OSDI1999
 - [Performance of Multithreaded Chip Multiprocessors and Implications for Operating System Design](http://www.eecs.harvard.edu/margo/papers/usenix05/paper.pdf), USENIX 2005
 
### Virtual Machine Monitor
 - [Virtual machine monitors: current technology and future trends](http://grid.hust.edu.cn/platform/resource/document/Virtual%20Machine%20Monitors%20Current%20Technology%20and%20Future%20Trends.pdf) ,IEEE Computer,vol38,issue 5, pp39-47, 2005
 - [Diagnosing performance overheads in the xen virtual machine environment](https://www.usenix.org/events/vee05/full_papers/p13-menon.pdf), vee 2005
 - [A comparison of software and hardware techniques for x86 virtualization](http://www.cs.columbia.edu/~junfeng/13fa-w4118/lectures/virtualization.pdf), asplos 2006
 - [Live migration of virtual machines](http://www.cs.princeton.edu/courses/archive/fall08/cos597B/papers/vm-migration.pdf), nsdi 2005
 - [Dune: Safe User-level Access to Privileged CPU Features](https://www.usenix.org/system/files/conference/osdi12/osdi12-final-117.pdf) OSDI 2012.
    - [dune project](http://dl.acm.org/citation.cfm?doid=2872362.2872389)
 - [COLO: COarse-grained LOck-stepping Virtual Machines for Non-stop Service](https://www.cs.purdue.edu/homes/ma229/papers/socc13.pdf), socc13, 2013
 - [Xen and the Art of Virtualization](http://www.cl.cam.ac.uk/research/srg/netos/papers/2003-xensosp.pdf),SOSP2003

### Network
 - [The x-Kernel: An Architecture for Implementing Network Protocols](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.42.3620&rank=2),IEEE Transactions on Software Engineering,1991
 - [MegaPipe: A New Programming Interface for Scalable Network I/O](http://www.eecs.berkeley.edu/~sylvia/papers/osdi2012_megapipe.pdf), OSDI 2012
 - [Improving network connection locality on multicore systems](https://pdos.csail.mit.edu/papers/affinity-accept:eurosys12.pdf), EUROSYS 2012
 - [ IX: A Protected Dataplane Operating System for High Throughput and Low Latency](http://courses.cs.washington.edu/courses/cse551/15sp/papers/ix-osdi14.pdf), OSDI 2014.
    - [IX project](https://github.com/ix-project/ix)
 - [mTCP: a Highly Scalable User-level TCP Stack for Multicore Systems](http://www.ndsl.kaist.edu/~kyoungsoo/papers/mtcp.pdf), NSDI 2014
     - [mtcp project](http://shader.kaist.edu/mtcp/)
 - [scalable Kernel TCP Design and Implementation for Short-Lived Connections](http://dl.acm.org/citation.cfm?doid=2872362.2872391), ASPLOS 2016
     - [fastsocket project](https://github.com/fastos/fastsocket)

### File System
 - [ All File Systems Are Not Created Equal: On the Complexity of Crafting Crash-Consistent Applications](http://courses.cs.washington.edu/courses/cse551/15sp/papers/alice-osdi14.pdf)OSDI 2014. 
 - [Rethink the Sync](https://www.usenix.org/legacy/event/osdi06/tech/nightingale/nightingale.pdf), OSDI 2006.
 - [Serverless Network File Systems](http://www.cs.columbia.edu/~nieh/teaching/e6118_s00/papers/p109-anderson.pdf),SOSP1995
 - [The Design and Implementation of a Log-Structured File System](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.41.8933),ACM Transactions on Computer Systems 1991
 - [A Fast File System for UNIX](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.114.9535&rank=1&q=A%20Fast%20File%20System%20for%20UNIX&osm=&ossid=),ACM Transactions on Computer Systems 1984
 - [The Google File System](http://research.google.com/archive/gfs-sosp2003.pdf),SOSP 2003
 - [Design Tradeoffs for SSD Performance](http://www.cs.wisc.edu/adsl/Publications/ssd-usenix08.pdf),USENIX 2008
 - [A Study of Linux File System Evolution](https://www.usenix.org/system/files/conference/fast13/fast13-final75_0.pdf),FAST 2013
 - [F2FS: A New File System for Flash Storage](https://www.usenix.org/conference/fast15/technical-sessions/presentation/lee),FAST 2015
 - [Hare: a file system for non-cache-coherent multicores](https://pdos.csail.mit.edu/papers/hare.pdf),EUROSYS 2015

### SMP & Multicore & Scalability
 - [Corey: An Operating System for Many Cores](https://www.usenix.org/events/osdi08/tech/full_papers/boyd-wickizer/boyd_wickizer.pdf),OSDI 2008
 - [An analysis of Linux scalability to many cores](https://pdos.csail.mit.edu/papers/linux:osdi10.pdf), OSDI 2010
 - [Locating cache performance bottlenecks using data profiling](https://pdos.csail.mit.edu/papers/dprof:eurosys10.pdf), EUROSYS 2010
 - [Non-scalable locks are dangerous](https://pdos.csail.mit.edu/papers/linux:lock.pdf) Linux Symposium 2012.
 - [scalable Kernel TCP Design and Implementation for Short-Lived Connections](http://dl.acm.org/citation.cfm?doid=2872362.2872391), ASPLOS 2016
     - [fastsocket project](https://github.com/fastos/fastsocket)
 - [Scalable Address Spaces Using RCU Balanced Trees](http://courses.cs.washington.edu/courses/cse551/15sp/papers/bonsai-asplos12.pdf), ASPLOS 2012
 - [mTCP: a Highly Scalable User-level TCP Stack for Multicore Systems](http://www.ndsl.kaist.edu/~kyoungsoo/papers/mtcp.pdf), NSDI 2014
     - [mtcp project](http://shader.kaist.edu/mtcp/)
 - [The Multikernel: A new OS architecture for scalable multicore systems](http://www.sigops.org/sosp/sosp09/papers/baumann-sosp09.pdf),SOSP2009
 - [Disco: running commodity operating systems on scalable multiprocessors]()
 

### Finding Bugs &Security
 - [An empirical study of operating systems errors](http://sosp.org/2001/papers/chou.pdf), SOSP 2003.
 - [KLEE: Unassisted and Automatic Generation of High-Coverage Tests for Complex Systems Programs](http://courses.cs.washington.edu/courses/cse551/15sp/papers/klee-osdi08.pdf), OSDI 2008.
     - [KLEE project](http://klee.github.io/)
 - [PF-Miner: A New Paired Functions Mining Method for Android Kernel in Error Paths](http://ieeexplore.ieee.org/xpl/login.jsp?tp=&arnumber=6899198&url=http%3A%2F%2Fieeexplore.ieee.org%2Fxpls%2Fabs_all.jsp%3Farnumber%3D6899198), COMPSAC 2014
 - [RID: Finding Reference Count Bugs with Inconsistent Path Pair Checking](http://dl.acm.org/citation.cfm?doid=2872362.2872389), ASPLOS 2016
 - [Learning from Mistakes A Comprehensive Study on Real World Concurrency Bug Characteristics](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.121.1203),ASPLOS2008
 - [Triage: diagnosing production run failures at the user's site](http://dl.acm.org/authorize?N91454),SOSP2007
 - [MUVI: automatically inferring multi-variable access correlations and detecting related semantic and concurrency bugs](http://dl.acm.org/authorize?N91453), SOSP 2007
 - [Faults in linux: ten years later](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.220.8605),ASPLOS 2011
 - [Linux kernel vulnerabilities: State-of-the-art defenses and open problems](http://pdos.csail.mit.edu/papers/chen-kbugs.pdf),APSYS 2011
 - [Understanding and detecting real-world performance bugs](http://dl.acm.org/authorize?N91341), PLDI 2012
 - [Production-run software failure diagnosis via hardware performance counters](http://dl.acm.org/authorize?N91349),ASPLOS 2013
 - [Early Detection of Configuration Errors to Reduce Failure Damage](http://people.cs.uchicago.edu/~shanlu/paper/osdi16-final321-pcheck.pdf),OSDI 2016
 - [Towards optimization-safe systems: Analyzing the impact of undefined behavior](http://pdos.csail.mit.edu/papers/stack:sosp13.pdf), SOSP 2013
 - [Improving integer security for systems with Kint](http://pdos.csail.mit.edu/papers/kint:osdi12.pdf),OSDI 2012

### API 
 - [A Critique of the Windows Application Programming Interface](http://www.spinellis.gr/pubs/jrnl/1997-CSI-WinApi/html/win.pdf),Computer Standards & Interfaces, 20:1–8, November 1998
 - [Mars Code](http://dl.acm.org/citation.cfm?id=2556647.2560218) Magazine Communications of the ACM CACM Homepage archive
Volume 57 Issue 2, February 2014 Pages 64-73 
 - [The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors](http://courses.cs.washington.edu/courses/cse551/15sp/papers/commutativity-sosp13.pdf), SOSP 2013.
     - [commuter project](https://github.com/aclements/commuter)
 - [MegaPipe: A New Programming Interface for Scalable Network I/O](http://www.eecs.berkeley.edu/~sylvia/papers/osdi2012_megapipe.pdf), OSDI 2012.
 - [Flexsc: Flexible System Call Scheduling with Exception-Less System Calls](https://www.cs.cmu.edu/~chensm/Big_Data_reading_group/papers/flexsc-osdi10.pdf),OSDI 2010
 - [Light-Weight Contexts: An OS Abstraction for Safety and Performance](https://www.usenix.org/conference/osdi16/technical-sessions/presentation/litton),OSDI 2016

### Verification
 - [seL4: Formal Verification of an OS Kernel](http://www.sigops.org/sosp/sosp09/papers/klein-sosp09.pdf) SOSP 2009.
     - [seL4 project](https://github.com/seL4)
 - [Jitk: A Trustworthy In-Kernel Interpreter Infrastructure](https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-wang_xi.pdf) OSDI 2014.
     - [jitk project](http://css.csail.mit.edu/jitk/)
 - [Using Crash Hoare Logic for certifying the FSCQ file system](https://pdos.csail.mit.edu/papers/fscq:sosp15.pdf) SOSP 2015
     - [Specifying crash safety for storage systems](https://pdos.csail.mit.edu/papers/fscq:hotos15.pdf) HotOS XV 2015
 - [Push-Button Verification of File Systems via Crash Refinement.](http://locore.cs.washington.edu/papers/sigurbjarnarson-yggdrasil.pdf),OSDI 2016
 - [Specifying and Checking File System Crash-Consistency Models](http://locore.cs.washington.edu/papers/bornholt-ferrite.pdf), ASPLOS 2016
 - [An Empirical Study on the Correctness of Formally Verified Distributed Systems.](http://locore.cs.washington.edu/papers/fonseca-dsbugs.pdf),EUROSYS 2017

### DEVICES
 - [Improving the Reliability of Commodity Operating Systems](http://www.cs.wisc.edu/~swift/papers/nooks-sosp.pdf), SOSP 2003
 - [Understanding modern device drivers](http://www.cs.wisc.edu/~swift/papers/asplos12_drivers.pdf),ASPLOS 2012
 - [Tolerating Hardware Device Failures in Software.](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.154.5958&rank=1&q=Tolerating%20Hardware%20Device%20Failures%20in%20Software&osm=&ossid=),SOSP 2009
 - [Gdev: First-Class GPU Resource Management in the Operating System](https://www.usenix.org/system/files/conference/atc12/atc12-final319.pdf),USENIX ATC 2012 
 - [GPUvm: Why not virtualizing GPUs at the hypervisor?](https://www.usenix.org/sites/default/files/conference/protected-files/atc14_slides_suzuki.pdf),USENIX ATC 2014
