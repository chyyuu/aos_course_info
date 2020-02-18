## Contents

  1. [OS Architecture](#os-architecture)
  1. [Process&Thread&Scheduling](#processthreadscheduling)
  1. [Memory Management](#memory-management)
  1. [Concurrency/Sync&Mutex](#concurrencysyncmutex)
  1. [Distributed Systems](#distributed-systems) 
  1. [Virtual Machine Monitor](#virtual-machine-monitor)
  1. [Network](#network)  
  1. [File System](#file-system)
  1. [Scalability](#scalability)
  1. [Bugs/Security/Fault-Tolerant/Recovery](#bugssecurityfault-tolerantrecovery)
  1. [Encryption&Authentication](#encryptionauthentication)  
  1. [Interface Design (API/ABI/ Software-Hardware Interface...)](#interface-design-apiabi-software-hardware-interface)  
  1. [Verification/Proof](#verificationproof)  
  1. [Devices](#devices)      
-----------------------------------------

### OS Architecture
 1. [The Structure of the "THE"-Multiprogramming System](http://uosis.mif.vu.lt/~liutauras/books/Dijkstra%20-%20The%20structure%20of%20the%20THE%20multiprogramming%20system.pdf),
Edsger W. Dijkstra ,Technological University, Eindhoven, The Netherlands, SOSP, 1968 
    - **SIGOPS: The Hall of Fame Award** The first paper to suggest that an operating system be built in a structured way. That structure was a series of layers, each a virtual machine that introduced abstractions built using the functionality of lower layer. The paper stimulated a great deal of subsequent work in building operating systems as structured systems.
 1. [Tenex, A Paged Time Sharing System for the PDP-10](http://dl.acm.org/citation.cfm?id=361271),Daniel G. Bobrow, Jerry D. Burchfiel, Daniel L. Murphy and Raymond S. Tomlinson. Communications of the ACM 15(3), March 1972.
    - **SIGOPS: The Hall of Fame Award**  The Tenex system pioneered many ideas that are prominent in modern operating systems. It included one of the first page based memory systems, copy on write sharing, mapping of files into virtual memory, and user/group/other file protection. It also had mnemonic commands with command-line completion and automatic file versioning. As one reviewer said, “Reading it now, I’m pleasantly surprised by how much is familiar — thanks to its successors.”
 1. [On the criteria to be used in decomposing systems into modules](http://doi.acm.org/10.1145/361598.361623), David. L. Parnas., Communications of the ACM 15(12), December 1972, 1053-1058. 
    - **SIGOPS: The Hall of Fame Award**  This paper introduced a technique for decomposing a complex system into modules. Through a simple example it showed that a modularization that emphasizes what is now known as “information hiding” is superior to more obvious module decompositions in terms of the software engineering lifecycle. The paper argues the beneficial decomposition can be achieved with minimal performance overheads. The “information hiding” approach has influenced software engineering in areas including operating systems, distributed systems, databases, and programming languages. 
 1. [On Micro-Kernel Construction](http://zoo.cs.yale.edu/classes/cs422/2010/bib/liedtke95micro.pdf),J. Liedtke., ACM SIGOPS Operating Systems Review 29(5):237-250 · December 1995
    - **SIGOPS: The Hall of Fame Award**   This paper presented the core design ideas behind the L4 microkernel, especially the minimality principle, which states that functionality must only be implemented inside the kernel if moving it outside would prevent the implementation of required system functionality. This principle was at the heart of L4’s design, and supported a ruthless performance focus, which allowed L4 to outperform other microkernels by an order of magnitude. The core ideas of this paper led to a family of L4 microkernels which were commercially deployed on a large scale, and eventually enabled unprecedented assurance through formal verification.
 1. [Exokernel: An Operating System Architecture for Application-Level Resource Management](http://flint.cs.yale.edu/cs428/doc/p251-engler.pdf), Dawson R. Engler, M. Frans Kaashoek, and James O’Toole Jr. MIT,  SIGOPS ’95, 1995
    - [jos project](https://pdos.csail.mit.edu/6.828/2016/labguide.html)
 1. [Singularity: Rethinking the Software Stack](http://research.microsoft.com/pubs/69431/osr2007_rethinkingsoftwarestack.pdf) Galen C. Hunt and James R. Larus, Microsoft Research Redmond, OSR2007, 2007
    - [Singularity OS project](https://www.microsoft.com/en-us/research/project/singularity/) 
 1. [The UNIX Time-Sharing System](http://pdos.csail.mit.edu/6.828/2014/readings/ritchie78unix.pdf), SOSP 1973, The Bell System Technical Journal 57 no. 6, part 2 (July-August 1978)
    - **SIGOPS: The Hall of Fame Award** At a time when operating systems were trending towards complexity, UNIX emerged as a hallmark of elegance and simplicity.
    - [The Evolution of the Unix Time-sharing System](http://www.read.seas.harvard.edu/~kohler/class/aosref/ritchie84evolution.pdf)Dennis M. Ritchie, Bell Laboratories, 1984
    - [xv6 project](https://pdos.csail.mit.edu/6.828/2016/xv6.html)
    - [related info:The Unix-Haters Handbook (1994)](http://web.mit.edu/~simsong/www/ugh.pdf)
 1. [Extensibility, Safety and Performance in the SPIN Operating System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.41.7509&rep=rep1&type=pdf), Brian N. Bershad,etc.University of Washington, 1995
 1. [Secure Virtual Architecture: A Safe Execution Environment for Commodity Operating Systems](http://sosp2007.org/papers/sosp139-criswell.pdf), John Criswell, Andrew Lenharth, Dinakar Dhurjati, and Vikram Adve,University of Illinois at Urbana–Champaign, SOSP07, 2007
     - [SVA project](https://github.com/jtcriswell/SVA)
 1. [Multiprogramming a 64 kB Computer Safely and Efficiently](https://dl.acm.org/authorize?N47259),Amit Levy and Bradford Campbell and Branden Ghena and Daniel Giffin and Pat Pannuto and Prabal Dutta and Philip Levis. SOSP 2017
     - the tock embedded OS in RUST language
     - [tock os project](https://www.tockos.org/)
 1. [The benefits and costs of writing a POSIX kernel in a high-level language](https://pdos.csail.mit.edu/papers/biscuit.pdf),Cody Cutler, M. Frans Kaashoek, and Robert T. Morris,OSDI 2018    
     - the biscuit POSIX-like OS in GO language
     - [biscuit os project](https://pdos.csail.mit.edu/projects/biscuit.html)
 1. [LegoOS: A Disseminated, Distributed OS for Hardware Resource Disaggregation](https://www.usenix.org/conference/osdi18/presentation/shan), Yizhou Shan, Yutong Huang, Yilun Chen, and Yiying Zhang, Purdue University, OSDI 2018
     - Awarded Best Paper of OSDI 2018
     - [LegoOS project](http://legoos.io/)
 1. [The Nucleus of a Multiprogramming System](https://dl.acm.org/doi/10.1145/362258.362278), P. B. Hansen, Communications of the ACM, Vol. 13, No. 4, April 1970, pp. 238-241, 250. 
 
### Process&Thread&Scheduling
 1. [Programming Semantics for Multiprogrammed Computations](http://dl.acm.org/citation.cfm?id=365252), Jack B. Dennis, Earl C. Van Horn. Communications of the ACM, Volume 9 Issue 3, March 1966.
    - **SIGOPS: The Hall of Fame Award**  The paper lays out the conceptual foundations for multiprogramming and protection in computer systems.
 1. [Lottery Scheduling: Flexible Proportional-Share Resource Management](https://www.usenix.org/legacy/publications/library/proceedings/osdi/full_papers/waldspurger.pdf), OSDI94
 1. [Stride Scheduling: Deterministic Proportional-Share Resource Management](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.138.3502) tech report, 1995
 1. [Supporting Time-Sensitive Applications on a Commodity OS](http://www.eecg.toronto.edu/~ashvin/publications/osdi2002.pdf),OSDI2002
 1. [Borrowed-Virtual-Time (BVT) scheduling: supporting latency-sensitive threads in a general-purpose scheduler](http://www.read.seas.harvard.edu/~kohler/class/04f-aos/ref/duda99borrowed.pdf)SOSP1999
 1. [Improving Performance Isolation on Chip Multiprocessors via an Operating System Scheduler](https://dash.harvard.edu/bitstream/handle/1/10065537/Improving%20Performance%20Isolation2007%20(1).pdf?sequence=1),PACT2007
 1. [A Hierarchical CPU Scheduler for Multimedia Operating Systems](http://www.cs.columbia.edu/~nieh/teaching/e6118_s00/papers/goyal_osdi96.pdf),OSDI1996
 1. [Reinventing scheduling for multicore systems](https://pdos.csail.mit.edu/papers/o2:hotos12.pdf),HOTOS 2009
 1. [Addressing shared resource contention in multicore processors via scheduling](http://www.cs.sfu.ca/~fedorova/papers/asplos212-zhuravlev.pdf),ASPLOS2010

### Memory Management
 1. [The working set model for program behavior](http://denninginstitute.com/pjd/PUBS/WSModel_1968.pdf),Peter J. Denning, SOSP 1967, In Communications of the ACM 11(5), May 1968
    - **SIGOPS: The Hall of Fame Award** This paper introduced the working set model, which has became a key concept in understanding of locality of memory references and for implementing virtual memory. Most paging algorithms can trace their roots back to this work.
 1. [The Multics Virtual Memory: Concepts and Design](http://portal.acm.org/citation.cfm?id=361306), Andre Bensoussan, Charlie T. Clingen, Robert C. Daley, Communications of the ACM 15(5):308-318, May 1972.
     - **SIGOPS: The Hall of Fame Award** 
 1. [Memory Coherence in Shared Virtual Memory Systems](http://dl.acm.org/citation.cfm?id=75105), Kai Li(李凯), Paul Hudak.ACM TOCS 7(4), Nov 1989, pp 321–359.
     - **SIGOPS: The Hall of Fame Award** The paper shows how to simulate coherent shared memory on a cluster, and also introduces directory-based distributed cache-coherence. It spawned a entire research area, and introduced cache coherence mechanisms that are widely used in industry.   
 1. [Transactional memory: architectural support for lock-free data structures](http://doi.acm.org/10.1145/165123.165164),Maurice Herlihy and J. Eliot B. Moss.,  ISCA 1993. 
     - **SIGOPS: The Hall of Fame Award**  This paper introduced transactional memory, an architectural concept intended to make lock-free synchronization as efficient and easy to use as conventional techniques based on mutual exclusion. This concept has found its way into commercial multicore processors, and has generated a large amount of follow-on work in software transactional memory. 
 1. [Machine-Independent Virtual Memory Management for Paged Uniprocessor and Multiprocessor Architectures](http://portal.acm.org/citation.cfm?id=36206.36181), Richard Rashid, Avadis Tevanian, Michael Young, David Golub, Robert Baron, David Black, William Bolosky, and Jonathan Chew, ASPLOS 1987.  
     - **SIGOPS: The Hall of Fame Award**   
 1. [WSClock - A Simple and Effective Algorithm for Virtual Memory Management](https://www.researchgate.net/publication/220909958_WSClock_-_A_Simple_and_Effective_Algorithm_for_Virtual_Memory_Management),ACM SIGOPS Operating Systems Review 15(5):87-95 · December 1981
 1. [Simple But Effective Techniques for NUMA Memory Management](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.380.3461&rank=1),SOSP 1989
 1. [TreadMarks: Distributed Shared Memory on Standard Workstations and Operating Systems](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.27.9177&rank=9),IN PROCEEDINGS OF THE 1994 WINTER USENIX CONFERENCE,1994
 1. [The Slab Allocator: An Object-Caching Kernel Memory Allocator](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.143.4374&rank=1), USENIX SUMMER TECHNICAL CONFERENCE , 1994
 1. [Mnemosyne: Lightweight Persistent Memory](http://research.cs.wisc.edu/sonar/papers/mnemosyne-asplos2011.pdf),ASPLOS2011
 1. [Process-in-Process: Techniques for Practical Address-Space Sharing](https://www.mcs.anl.gov/~balaji/pubs/2018/hpdc/hpdc18.pip.pdf), Atsushi Hori, HPDC 2018
     - Best Paper Award of HPDC 2018
     - The idea of sharing address space between multiple processes is not new. So why is a new model needed? The answer lies with advances in high-performance computing, notably many-core computers with more parallelism in a node and frequent communication  between processes. Unlike other models, PiP’s design is completely in user space.
     - [PiP project](https://github.com/RIKEN-SysSoft/PiP)

 
### Concurrency/Sync&Mutex
 1. [Experience with processes and monitors in Mesa](http://portal.acm.org/citation.cfm?doid=358818.358824), Butler W. Lampson and David D., SOSP 1979.
     - **SIGOPS: The Hall of Fame Award** When this paper was written, monitors had emerged as the synchronization method of choice. in programming languages conferences and operating systems textbooks. This paper was the first to look closely at the practical issues that monitors pose when used in a large production system. These issues remain contemporary, and indeed researchers working on transactional memory mechanisms would do well to reread this wonderful paper.
 1. [On optimistic methods for concurrency control](http://doi.acm.org/10.1145/319566.319567), H. T. Kung(孔祥重) and John T. Robinson., ACM Transactions on Database Systems (TODS) 6(2), June 1981, 213-226. 
     - **SIGOPS: The Hall of Fame Award**  This paper introduced the notion of optimistic concurrency control, proceeding with a transaction without locking the data items accessed, in the expectation that the transaction’s accesses will not conflict with those of other transactions. This idea, originally introduced in the context of conventional databases, has proven very powerful when transactions are applied to general-purpose systems.
 1. [Algorithms for Scalable Synchronization on Shared-Memory Multiprocessors](http://www.cs.rice.edu/~johnmc/scalable_synch/tocs91.pdf),ACM Transactions on Computer Systems, Feb. 1991.
 1. [Scalable Read-mostly Synchronization Using Passive Reader-Writer Locks.](http://ipads.se.sjtu.edu.cn/_media/publications/prwlock-atc14.pdf),Usenix ATC 2014
 1. [Non-scalable locks are dangerous](https://pdos.csail.mit.edu/papers/linux:lock.pdf) Linux Symposium 2012.
 1. [Tornado: Maximizing Locality and Concurrency in a Shared Memory Multiprocessor Operating System](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.53.2410&rep=rep1&type=pdf),OSDI1999
 1. [Performance of Multithreaded Chip Multiprocessors and Implications for Operating System Design](http://www.eecs.harvard.edu/margo/papers/usenix05/paper.pdf), USENIX 2005

### Distributed Systems
 1. [Time, Clocks, and the Ordering of Events in a Distributed System](http://portal.acm.org/citation.cfm?doid=359545.359563), Leslie Lamport, Communications of the ACM 21(7):558-565, July 1978. 
    - **SIGOPS: The Hall of Fame Award**  Perhaps the first true “distributed systems” paper, it introduced the concept of “causal ordering”, which turned out to be useful in many settings. The paper proposed the mechanism it called “logical clocks”, but everyone now calls these “Lamport clocks.”
 1. [Implementing Remote Procedure Calls](http://portal.acm.org/citation.cfm?id=2080.357392),ACM Transactions on Computer Systems 2(1):39-59, February 1984.
    - **SIGOPS: The Hall of Fame Award**  This is the paper on RPC, which has become the standard for remote communication in distributed systems and the Internet. The paper does an excellent job laying out the basic model for RPC and the implementation options.
 1. [Grapevine: An Exercise in Distributed Computing](http://portal.acm.org/citation.cfm?id=358468.358487), Andrew D. Birrell, Roy Levin, Roger M. Needham, and Michael D. Schroeder, SOSP 1981.
    - **SIGOPS: The Hall of Fame Award** 
 1. [Scale and Performance in a Distributed File System](http://portal.acm.org/citation.cfm?doid=35037.35059), John H. Howard, Michael L. Kazar, Sherri G. Menees, David A. Nichols, M. Satyanarayanan, Robert N. Sidebotham, and Michael J. West, SOSP 1987.
    - **SIGOPS: The Hall of Fame Award**  
 1. [VAXclusters: A Closely-Coupled Distributed System](http://portal.acm.org/citation.cfm?id=214419.214421), Nancy P. Kronenberg, Henry M. Levy, and William D. Strecker, SOSP 1985.
    - **SIGOPS: The Hall of Fame Award**  The VAX Clusters system was the first modern clustered system supporting such basic features as a distributed file system and a distributed locking service. The SOSP paper on VAX Clusters remains a classic today. VAXclusters was a huge commercial success, and set the stage for today.s massive data centers. 
 1. [Viewstamped Replication: A New Primary Copy Method to Support Highly-Available Distributed Systems](http://dl.acm.org/citation.cfm?id=62549),rian M. Oki, Barbara H. Liskov. PODC 1988.
    - **SIGOPS: The Hall of Fame Award** The paper introduces a replication protocol very similar to what is now known as Paxos. That protocol has become the standard for consistent, fault-tolerant state-machine replication, and is widely used in data centers to keep the state consistent despite failures and reconfiguration.
 1. [The Part Time Parliament](http://dl.acm.org/citation.cfm?id=279229),Leslie Lamport. ACM TOCS 16(2), May 1998, 133–169.
    - **SIGOPS: The Hall of Fame Award** The work (originally published in 1989) was independent and roughly concurrent with the Viewstamped Replication work also recognized this year. It describes the protocol in a more general setting, adds a correctness argument, and forms the basis for modern Paxos implementations.
 1. [Distributed Snapshots: Determining Global States of a Distributed System](http://dl.acm.org/citation.cfm?id=214456), K. Mani Chandy and Leslie Lamport.  ACM Transactions on Computer Systems 3(1), February 1985.
    - **SIGOPS: The Hall of Fame Award**  This paper takes the idea of consistency for distributed predicate evaluation, formalizes it, distinguishes between stable and dynamic predicates, and shows precise conditions for correct detection of stable conditions. The fundamental techniques in the paper are the secret sauce in many distributed algorithms for deadlock detection, termination detection, consistent checkpointing for fault tolerance, global predicate detection for debugging and monitoring, and distributed simulation.
 1. [Exploiting Virtual Synchrony in Distributed Systems](http://dl.acm.org/citation.cfm?id=37515), Kenneth P. Birman and Thomas A. Joseph. SOSP 1987.
    - **SIGOPS: The Hall of Fame Award**  This paper describes a methodology for building distributed applications comprised of multiple components, each realized by a group of replicated servers. It defines a number of group communication primitives and then ties fault notification into the fabric of group services by introducing the virtual synchrony principle, which orders communication and fault notifications consistently among group members and across multiple groups.
 1. [Managing update conflicts in Bayou, a weakly connected replicated storage system](http://doi.acm.org/10.1145/224057.224070),D. B. Terry, M. M. Theimer, Karin Petersen, A. J. Demers, M. J. Spreitzer, and C. H. Hauser., SOSP 1995. 
    - **SIGOPS: The Hall of Fame Award**  Bayou is a replicated storage system that anticipated the world of numerous small mobile devices executing collaborative applications over unreliable networks. The paper describes a client-server storage structure supporting eventual consistency, anti-entropy protocols, disconnected operation, log-based recovery, and an application-centered approach to detecting and resolving update conflicts to arrive at consistent replicas. These concepts were backed up by a prototype implementation, two applications, and a simple performance evaluation. Bayou is still relevant to the problems faced by, and the solutions employed by, a large number of today’s modern applications.
 1. [Chord: A scalable peer-to-peer lookup service for Internet applications](http://doi.acm.org/10.1145/383059.383071), Ion Stoica, Robert Morris, David Karger, M. Frans Kaashoek, and Hari Balakrishnan., SIGCOMM 2001.
    - **SIGOPS: The Hall of Fame Award** This paper introduced a novel protocol that enables efficient key lookup in a large-scale and dynamic environment; the paper shows how to utilize consistent hashing to achieve provable correctness and performance properties while maintaining a simplicity and elegance of design. The core ideas within this paper have had a tremendous impact both upon subsequent academic work as well as upon industry, where numerous popular key-value storage systems employ similar techniques. The ability to scale while gracefully handling node addition and deletion remains an essential property required by many systems today.  
 1. [MapReduce: simplified data processing on large clusters](http://research.google.com/archive/mapreduce.html), 
Jeffrey Dean and Sanjay Ghemawat, OSDI 2004.
    - **SIGOPS: The Hall of Fame Award** The paper proposed a simple yet highly effective approach for processing large data sets in a scalable and fault-tolerant manner. An impressive aspect of the design is its simplicity: it elegantly captures a common pattern that solves two critical problems faced by many developers today (scalability and fault tolerance), while still retaining a clean, easy-to-use interface that supports a wide range of applications. The impact of MapReduce has been huge. It is widely used in industry, with virtually every large company running MapReduce. As a sign of great system design, developers have adopted MapReduce in many use cases beyond its original goals and inspired many follow-on systems.
 1. [Bigtable: A Distributed Storage System for Structured Data](http://dl.acm.org/citation.cfm?id=1267323), Fay Chang, Jeffrey Dean, Sanjay Ghemawat, Wilson C. Hsieh, Deborah A. Wallach, Mike Burrows, Tushar Chandra, Andrew Fikes, and Robert E. Gruber., OSDI 2006.
    - **SIGOPS: The Hall of Fame Award**  
 1. [Dynamo: Amazon’s Highly Available Key-value Store](https://doi.org/10.1145/1294261.1294281), Giuseppe DeCandia, Deniz Hastorun, Madan Jampani, Gunavardhan Kakulapati, Avinash Lakshman, Alex Pilchin, Swaminathan Sivasubramanian, Peter Vosshall, and Werner Vogels., SOSP 2007.
    - **SIGOPS: The Hall of Fame Award** Dynamo is a scalable and highly reliable distributed key-value store. The paper describes how Dynamo manages the tradeoffs between availability, consistency, cost-effectiveness, and performance, and explains how the system combines a variety of techniques: consistent hashing, vector clocks, sloppy quorums, Merkle trees, and gossip-based membership and failure detection protocols. In particular, the paper emphasizes the value of supporting eventual consistency in order to provide high availability in a distributed system. Dynamo evolved within Amazon to become the basis of a popular cloud service, and also inspired open-source systems such as Cassandra. 
 1. [The Chubby lock service for loosely-coupled distributed systems](https://dl.acm.org/citation.cfm?id=1298487),Mike Burrows., OSDI 2006. 
    - **SIGOPS: The Hall of Fame Award**  The Chubby lock service provides coarse-grained locking and reliable, low-volume storage for a loosely-coupled distributed system, and is particularly useful for synchronizing activities between clients. Chubby uses Paxos internally, but exposes a lock-service API to its clients, intended to simplify its adoption by programmers. The paper was one of the first to discuss the challenges of engineering a high-availability service for use by a wide range of programmers in a globally-distributed environment. While Chubby itself is widely used only within Google, the paper inspired open-source implementations of similar services, such as Zookeeper, that provide similar functionality. 
### Virtual Machine Monitor
 1. [A virtual machine time-sharing system](http://dx.doi.org/10.1147/sj.93.0199),R. A. Meyer and L. H. Seawright. IBM Systems Journal 9(3), September 1970, 199-218. 
    - **SIGOPS: The Hall of Fame Award**  This paper described the second generation of the very first virtual machine system. It was originally built in 1966 for an IBM 360/40 with custom virtual memory hardware and then ported to a 360/67, which had virtual memory built in. In addition to a virtual machine monitor called CP, the system included a single user interactive system called CMS, heavily influenced by MIT’s CTSS; to support multiple users the system ran CMS in a separate VM for each user. Because of the clean architecture of the 360, CP could virtualize the hardware perfectly (except for timing dependencies and self-modifying channel programs) without binary translation, though it did have to translate the channel programs. It could run most of the existing IBM operating systems in virtual machines. CP/67 evolved into VM/370, which became the main time-sharing system for IBM mainframes.
 1. [Memory Resource Management in VMware ESX Server](http://dl.acm.org/citation.cfm?id=844146), Carl A. Waldspurger. , OSDI 2002. 
    - **SIGOPS: The Hall of Fame Award**  This paper introduced elegant and effective techniques of hypervisor memory management. Memory ballooning allows the hypervisor to reclaim memory from a virtual machine in accordance with the unmodified guest’s operating system policies. Transparent page sharing supports efficient memory use with small overhead. The combination of active memory estimation, idle memory tax, and proportional fair sharing, along with admission-controlled memory reservation,provides the basis for service level agreements and reasoned overcommitment. This paper has been highly influential; many of its techniques have been adopted by widely-used hypervisors. 
 1. [Virtual machine monitors: current technology and future trends](http://grid.hust.edu.cn/platform/resource/document/Virtual%20Machine%20Monitors%20Current%20Technology%20and%20Future%20Trends.pdf) ,IEEE Computer,vol38,issue 5, pp39-47, 2005
 1. [Diagnosing performance overheads in the xen virtual machine environment](https://www.usenix.org/events/vee05/full_papers/p13-menon.pdf), vee 2005
 1. [A comparison of software and hardware techniques for x86 virtualization](http://www.cs.columbia.edu/~junfeng/13fa-w4118/lectures/virtualization.pdf), asplos 2006
 1. [Live migration of virtual machines](http://www.cs.princeton.edu/courses/archive/fall08/cos597B/papers/vm-migration.pdf), nsdi 2005
 1. [Dune: Safe User-level Access to Privileged CPU Features](https://www.usenix.org/system/files/conference/osdi12/osdi12-final-117.pdf) OSDI 2012.
    - [dune project](http://dl.acm.org/citation.cfm?doid=2872362.2872389)
 1. [COLO: COarse-grained LOck-stepping Virtual Machines for Non-stop Service](https://www.cs.purdue.edu/homes/ma229/papers/socc13.pdf), socc13, 2013
 1. [Xen and the Art of Virtualization](http://www.cl.cam.ac.uk/research/srg/netos/papers/2003-xensosp.pdf),SOSP2003
 1. [My VM is Lighter (and Safer) than your Container](https://dl.acm.org/authorize?N47258) SOSP 2017

### Network
 1. [End-To-End Arguments in System Design](http://portal.acm.org/citation.cfm?id=357402), J. H. Saltzer, D. P. Reed, and D. D. Clark, ACM Transactions on Computer Systems 2(4):277-288, November 1984.
    -  **SIGOPS: The Hall of Fame Award**  This paper gave system designers, and especially Internet designers, an elegant framework for making sound decisions. A paper that launched a revolution and, ultimately, a religion.
 1. [The Click Modular Router](http://dl.acm.org/citation.cfm?id=354874), Eddie Kohler, Robert Morris, Benjie Chen, John Jannotti and Frans Kaashoek. ACM Transactions on Computer Systems (TOCS), 18(3), August 2000.
    -  **SIGOPS: The Hall of Fame Award**  Click defines a simple, modular, and efficient framework for constructing network routers with different services and properties. Since this paper’s publication, Click has been an essential tool for the networking and systems research communities with dozens and perhaps hundreds of systems and papers built on it, including several commercially successful systems.
 1. [The x-Kernel: An Architecture for Implementing Network Protocols](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.42.3620&rank=2),IEEE Transactions on Software Engineering,1991
 1. [MegaPipe: A New Programming Interface for Scalable Network I/O](http://www.eecs.berkeley.edu/~sylvia/papers/osdi2012_megapipe.pdf), OSDI 2012
 1. [Improving network connection locality on multicore systems](https://pdos.csail.mit.edu/papers/affinity-accept:eurosys12.pdf), EUROSYS 2012
 1. [ IX: A Protected Dataplane Operating System for High Throughput and Low Latency](http://courses.cs.washington.edu/courses/cse551/15sp/papers/ix-osdi14.pdf), OSDI 2014.
    - [IX project](https://github.com/ix-project/ix)
 1. [mTCP: a Highly Scalable User-level TCP Stack for Multicore Systems](http://www.ndsl.kaist.edu/~kyoungsoo/papers/mtcp.pdf), NSDI 2014
     - [mtcp project](http://shader.kaist.edu/mtcp/)
 1. [scalable Kernel TCP Design and Implementation for Short-Lived Connections](http://dl.acm.org/citation.cfm?doid=2872362.2872391), ASPLOS 2016
     - [fastsocket project](https://github.com/fastos/fastsocket)
 1. [ZygOS: Achieving Low Tail Latency for Microsecond-scale Networked Tasks](https://dl.acm.org/authorize?N47254) SOSP 2017
     

### File System
 1. [ All File Systems Are Not Created Equal: On the Complexity of Crafting Crash-Consistent Applications](http://courses.cs.washington.edu/courses/cse551/15sp/papers/alice-osdi14.pdf)OSDI 2014. 
 1. [Rethink the Sync](https://www.usenix.org/legacy/event/osdi06/tech/nightingale/nightingale.pdf), OSDI 2006.
 1. [Serverless Network File Systems](http://www.cs.columbia.edu/~nieh/teaching/e6118_s00/papers/p109-anderson.pdf),SOSP1995
 1. [The Design and Implementation of a Log-Structured File System](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.41.8933),Mendel Rosenblum, John K. Ousterhout. ACM TOCS 10(1), Feb 1992, pp 26–52.
    - **SIGOPS: The Hall of Fame Award**  The paper introduces log-structured file storage, where data is written sequentially to a log and continuously de-fragmented. The underlying ideas have influenced many modern file and storage systems like NetApp’s WAFL file systems, Facebook’s picture store, aspects of Google’s BigTable, and the Flash translation layers found in SSDs.
 1. [A Fast File System for UNIX](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.114.9535&rank=1&q=A%20Fast%20File%20System%20for%20UNIX&osm=&ossid=),Marshall K. McKusick, William N. Joy, Samuel J. Leffler, and Robert S. Fabry, ACM Transactions on Computer Systems (TOCS) 2(3), August 1984, 181-197. 
    - **SIGOPS: The Hall of Fame Award** This paper introduced techniques to make the file system “disk aware”, thus demonstrating the importance of understanding the interplay between hardware technology and file-system design. The structuring concept of the cylinder group, while simple, is found in some form in many current systems (including the widely-deployed Linux ext* family) and serves as an excellent example of the importance of locality in storage. The paper also introduced numerous functionality improvements, including symbolic links and atomic rename, which have since become commonplace features in modern file systems.
 1. [Disconnected operation in the Coda File System](http://doi.acm.org/10.1145/146941.146942),James J. Kistler and M. Satyanarayanan., ACM Transactions on Computer Systems (TOCS) 10(1), February 1992, 3-25.
    - **SIGOPS: The Hall of Fame Award**  This paper was the first to describe the use of caching to provide availability in addition to improved performance in a distributed setting where clients use files stored at remote file servers, leading to potential loss of service during disconnection. The Coda design provided a thoughtful and elegant approach to supporting continued service during disconnection. Disconnected clients continued to service user requests using locally cached content; however all potential modifications performed while disconnected were logged locally, and when service was restored the system attempted to reconcile the local modifications with the current server state. The Coda design inspired much follow-on research on distributed file systems and its techniques were adopted in other systems.
 1. [The Google File System](http://research.google.com/archive/gfs-sosp2003.pdf),Sanjay Ghemawat, Howard Gobioff, and Shun-Tak Leung.,SOSP 2003
    - **SIGOPS: The Hall of Fame Award**   This paper presented an effective design for a large-scale distributed file system that provided fault tolerance while running on inexpensive commodity hardware. It provided very large amounts of I/O bandwidth by having all data transfers happen directly between client processes and machines storing the actual data, handled automatic recovery from failed disks and machines, and retained the simplicity of managing file system metadata in a single centralized master. GFS formed the basis for the design for the open-source HDFS system, as well the backbone for the evolution of large-scale distributed file systems at Google and elsewhere.
 1. [Design Tradeoffs for SSD Performance](http://www.cs.wisc.edu/adsl/Publications/ssd-usenix08.pdf),USENIX 2008
 1. [A Study of Linux File System Evolution](https://www.usenix.org/system/files/conference/fast13/fast13-final75_0.pdf),FAST 2013
 1. [F2FS: A New File System for Flash Storage](https://www.usenix.org/conference/fast15/technical-sessions/presentation/lee),FAST 2015
 1. [Hare: a file system for non-cache-coherent multicores](https://pdos.csail.mit.edu/papers/hare.pdf),EUROSYS 2015

### Scalability
 1. [Corey: An Operating System for Many Cores](https://www.usenix.org/events/osdi08/tech/full_papers/boyd-wickizer/boyd_wickizer.pdf),OSDI 2008
 1. [An analysis of Linux scalability to many cores](https://pdos.csail.mit.edu/papers/linux:osdi10.pdf), OSDI 2010
 1. [Locating cache performance bottlenecks using data profiling](https://pdos.csail.mit.edu/papers/dprof:eurosys10.pdf), EUROSYS 2010
 1. [Non-scalable locks are dangerous](https://pdos.csail.mit.edu/papers/linux:lock.pdf) Linux Symposium 2012.
 1. [scalable Kernel TCP Design and Implementation for Short-Lived Connections](http://dl.acm.org/citation.cfm?doid=2872362.2872391), ASPLOS 2016
     - [fastsocket project](https://github.com/fastos/fastsocket)
 1. [Scalable Address Spaces Using RCU Balanced Trees](http://courses.cs.washington.edu/courses/cse551/15sp/papers/bonsai-asplos12.pdf), ASPLOS 2012
 1. [mTCP: a Highly Scalable User-level TCP Stack for Multicore Systems](http://www.ndsl.kaist.edu/~kyoungsoo/papers/mtcp.pdf), NSDI 2014
     - [mtcp project](http://shader.kaist.edu/mtcp/)
 1. [The Multikernel: A new OS architecture for scalable multicore systems](http://www.sigops.org/sosp/sosp09/papers/baumann-sosp09.pdf),SOSP2009
 1. [Disco: running commodity operating systems on scalable multiprocessors](http://research.cs.wisc.edu/areas/os/Qual/papers/disco.pdf),Edouard Bugnion, Scott Devine, and Mendel Rosenblum, SOSP 1997, ACM Transactions on Computer Systems,1997
     - **SIGOPS: The Hall of Fame Award**  
 1. [Scaling a file system to many cores using an operation log](https://dl.acm.org/authorize?N47149) SOSP 2017
 

### Bugs/Security/Fault-Tolerant/Recovery
 1. [Implementing Fault-Tolerant Services Using the State Machine Approach: a tutorial](http://portal.acm.org/citation.cfm?doid=98163.98167), Fred B. Schneider, ACM Computing Surveys 22(4):299-319, December 1990.
    - **SIGOPS: The Hall of Fame Award** The paper that explained how we should think about replication … a model that turns out to underlie Paxos, Virtual Synchrony, Byzantine replication, and even Transactional 1-Copy Serializability.
 1. [Leases: An Efficient Fault-Tolerant Mechanism for Distributed File Cache Consistency](http://portal.acm.org/citation.cfm?id=74850.74870), Cary G. Gray and David R. Cheriton, SOSP 1989.
     - **SIGOPS: The Hall of Fame Award** The Gray and Cheriton paper pioneered through its analysis of the Leases mechanism, which has become one of the most widely-used mechanisms for managing distributed caches. The paper is particularly striking for its careful analysis of the semantics of leases, its detailed experiments, and its thoughtful discussion of fault-tolerance issues.
 1. [Crash Recovery in a Distributed Data Storage System](http://dl.acm.org/citation.cfm?id=50214), Butler Lampson and Howard Sturgis, Technical report, Xerox Palo Alto Research Center, June 1979.
     - **SIGOPS: The Hall of Fame Award** 
 1. [The Recovery Manager of the System R Database Manager](http://portal.acm.org/citation.cfm?id=356847), Jim Gray, Paul McJones, Mike Blasgen, Bruce Lindsay, Raymond Lorie, Tom Price, Franco Putzolu, and Irving Traiger, ACM Computing Surveys, June 1981.
     - **SIGOPS: The Hall of Fame Award** 
 1. [Why Do Computers Stop And What Can Be Done About It?](http://www.hpl.hp.com/techreports/tandem/TR-85.7.pdf), Jim Gray, HP Labs Technical Report TR-85.7.
     - **SIGOPS: The Hall of Fame Award** The paper presents the first large scale quantitative study of computer failures in practice, of a system built using best practices at the time to achieve fault-tolerance. 
 1. [Reflections on Trusting Trust](http://dl.acm.org/citation.cfm?id=358210),Ken Thompson. Communications of the ACM, Volume 27 Issue 8, Aug 1984.   
     - **SIGOPS: The Hall of Fame Award**  The paper demonstrated that to have trust in a program, one cannot just rely on trust in the person who wrote it, or even on verifying the source code. One must also ensure that the entire tool chain used to produce and execute binaries is trustworthy.
 1. [A NonStop Kernel](http://dl.acm.org/citation.cfm?id=806587), Joel Bartlett, SOSP 1981.
     - **SIGOPS: The Hall of Fame Award** Tandem was the first commercial database to achieve fault tolerance. To accomplish this, the Tandem system had to bring together many techniques — including message-passing, mirroring, fast failure detection, and failover — into a practical design and implementation.  
 1. [Efficient software-based fault isolation](http://doi.acm.org/10.1145/168619.168635), Robert Wahbe, Steven Lucco, Thomas E. Anderson, and Susan L. Graham., SOSP 1993.
     - **SIGOPS: The Hall of Fame Award** This paper demonstrated that compiler or code-rewriting techniques could isolate untrusted code modules, preventing them from writing or jumping to addresses outside their “fault domain”, without the overhead of crossing hardware-enforced address space boundaries, and without much increase in execution time of code within a domain. The paper inspired substantial subsequent research, and the basic techniques have been implemented in widely-deployed software, such as Web browsers.
 1. [ReVirt: Enabling intrusion analysis through virtual-machine logging and replay](http://doi.acm.org/10.1145/844128.844148), George W. Dunlap, Samuel T. King, Sukru Cinar, Murtaza A. Basrai, and Peter M. Chen., OSDI 2002.
     - **SIGOPS: The Hall of Fame Award**  The paper demonstrated that the execution of an arbitrary program inside a virtual machine can be replayed deterministically and efficiently. Originally intended primarily as a tool for intrusion analysis, record-and-replay has been used subsequently for debugging, fault-tolerance, to audit program executions, and other virtual machine services. The work has directly influenced commercial products and sparked a research area that continues to this day.
 1. [An empirical study of operating systems errors](http://sosp.org/2001/papers/chou.pdf), SOSP 2003.
 1. [KLEE: Unassisted and Automatic Generation of High-Coverage Tests for Complex Systems Programs](http://courses.cs.washington.edu/courses/cse551/15sp/papers/klee-osdi08.pdf), OSDI 2008.
     - [KLEE project](http://klee.github.io/)
 1. [PF-Miner: A New Paired Functions Mining Method for Android Kernel in Error Paths](http://ieeexplore.ieee.org/xpl/login.jsp?tp=&arnumber=6899198&url=http%3A%2F%2Fieeexplore.ieee.org%2Fxpls%2Fabs_all.jsp%3Farnumber%3D6899198), COMPSAC 2014
 1. [RID: Finding Reference Count Bugs with Inconsistent Path Pair Checking](http://dl.acm.org/citation.cfm?doid=2872362.2872389), ASPLOS 2016
 1. [Learning from Mistakes A Comprehensive Study on Real World Concurrency Bug Characteristics](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.121.1203),ASPLOS2008
 1. [Triage: diagnosing production run failures at the user's site](http://dl.acm.org/authorize?N91454),SOSP2007
 1. [MUVI: automatically inferring multi-variable access correlations and detecting related semantic and concurrency bugs](http://dl.acm.org/authorize?N91453), SOSP 2007
 1. [Faults in linux: ten years later](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.220.8605),ASPLOS 2011
 1. [Linux kernel vulnerabilities: State-of-the-art defenses and open problems](http://pdos.csail.mit.edu/papers/chen-kbugs.pdf),APSYS 2011
 1. [Understanding and detecting real-world performance bugs](http://dl.acm.org/authorize?N91341), PLDI 2012
 1. [Production-run software failure diagnosis via hardware performance counters](http://dl.acm.org/authorize?N91349),ASPLOS 2013
 1. [Early Detection of Configuration Errors to Reduce Failure Damage](http://people.cs.uchicago.edu/~shanlu/paper/osdi16-final321-pcheck.pdf),OSDI 2016
 1. [Towards optimization-safe systems: Analyzing the impact of undefined behavior](http://pdos.csail.mit.edu/papers/stack:sosp13.pdf), SOSP 2013
 1. [Improving integer security for systems with Kint](http://pdos.csail.mit.edu/papers/kint:osdi12.pdf),OSDI 2012
 1. [DeepXplore: Automated Whitebox Testing of Deep Learning Systems](https://dl.acm.org/authorize?N47145) SOSP 2017
 1. [Log20: Fully Automated Optimal Placement of Log Printing Statements under Specified Overhead Threshold](https://dl.acm.org/authorize?N47278) SOSP 2017
 1. [kAFL: Hardware-Assisted Feedback Fuzzing for OS Kernels](https://www.usenix.org/system/files/conference/usenixsecurity17/sec17-schumilo.pdf) usenixsecurity17
     - [kAFL project](https://github.com/RUB-SysSec/kAFL)

### Encryption&Authentication
 1. [ Using Encryption for Authentication in Large Networks of Computers](http://portal.acm.org/citation.cfm?id=359659),Roger Needham and Michael Schroeder, Communications of the ACM, December 1978.
    - **SIGOPS: The Hall of Fame Award** 

### Interface Design (API/ABI/ Software-Hardware Interface...) 
 1. [Hints for Computer System Design](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/acrobat-17.pdf), Butler W. Lampson, SOSP 1983. 
    - **SIGOPS: The Hall of Fame Award** A classic study of experience building large systems, distilled into a cookbook of wisdom for the operating systems researcher. As time has passed, the value of these hints has only grown and the range of systems to which they apply enlarged.
 1. [A Critique of the Windows Application Programming Interface](http://www.spinellis.gr/pubs/jrnl/1997-CSI-WinApi/html/win.pdf),Computer Standards & Interfaces, 20:1–8, November 1998
 1. [Mars Code](http://dl.acm.org/citation.cfm?id=2556647.2560218) Magazine Communications of the ACM CACM Homepage archive
Volume 57 Issue 2, February 2014 Pages 64-73 
 1. [The Scalable Commutativity Rule: Designing Scalable Software for Multicore Processors](http://courses.cs.washington.edu/courses/cse551/15sp/papers/commutativity-sosp13.pdf), SOSP 2013.
     - [commuter project](https://github.com/aclements/commuter)
 1. [MegaPipe: A New Programming Interface for Scalable Network I/O](http://www.eecs.berkeley.edu/~sylvia/papers/osdi2012_megapipe.pdf), OSDI 2012.
 1. [Flexsc: Flexible System Call Scheduling with Exception-Less System Calls](https://www.cs.cmu.edu/~chensm/Big_Data_reading_group/papers/flexsc-osdi10.pdf),OSDI 2010
 1. [Light-Weight Contexts: An OS Abstraction for Safety and Performance](https://www.usenix.org/conference/osdi16/technical-sessions/presentation/litton),OSDI 2016

### Verification/Proof
 1. [Safe Kernel Extensions Without Run-Time Checking](http://www.usenix.org/publications/library/proceedings/osdi96/necula.html), George C. Necula and Peter Lee, SOSP 1996
    - **SIGOPS: The Hall of Fame Award** This paper introduced the notion of proof carrying code (PCC) and showed how it could be used for ensuring safe execution by kernel extensions without incurring run-time overhead. PCC turns out to be a general approach for relocating trust in a system; trust is gained in a component by trusting a proof checker (and using it to check a proof the component behaves as expected) rather than trusting the component per se. PCC has become one of the cornerstones of language-based security.
 1. [A Logic of Authentication](http://portal.acm.org/citation.cfm?id=77649), Michael Burrows, Martin Abadi, and Roger Needham, ACM Transactions on Computer Systems 8(1):18-36, February 1990.
    - **SIGOPS: The Hall of Fame Award** This paper introduced to the systems community a logic-based notation for authentication protocols to precisely describe certificates, delegations, etc. With this precise description a designer can easily reason whether a protocol is correct or not, and avoid the security flaws that have plagued protocols. “Speaks-for” and “says” are now standard tools for system designers.
 1. [seL4: Formal Verification of an OS Kernel](http://www.sigops.org/sosp/sosp09/papers/klein-sosp09.pdf), SOSP 2009.
     - [seL4 project](https://github.com/seL4)
 1. [Jitk: A Trustworthy In-Kernel Interpreter Infrastructure](https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-wang_xi.pdf) OSDI 2014.
     - [jitk project](http://css.csail.mit.edu/jitk/)
 1. [Using Crash Hoare Logic for certifying the FSCQ file system](https://pdos.csail.mit.edu/papers/fscq:sosp15.pdf) SOSP 2015
     - [Specifying crash safety for storage systems](https://pdos.csail.mit.edu/papers/fscq:hotos15.pdf) HotOS XV 2015
 1. [Push-Button Verification of File Systems via Crash Refinement.](http://locore.cs.washington.edu/papers/sigurbjarnarson-yggdrasil.pdf),OSDI 2016
 1. [Specifying and Checking File System Crash-Consistency Models](http://locore.cs.washington.edu/papers/bornholt-ferrite.pdf), ASPLOS 2016
 1. [An Empirical Study on the Correctness of Formally Verified Distributed Systems.](http://locore.cs.washington.edu/papers/fonseca-dsbugs.pdf),EUROSYS 2017
 1. [Hyperkernel: Push-Button Verification of an OS Kernel](https://dl.acm.org/citation.cfm?id=3132748), SOSP 2017
   - [hyperkernel project](http://locore.cs.washington.edu/hyperkernel/)
 1. [Verifying a high-performance crash-safe file system using a tree specification](https://dl.acm.org/authorize?N47251) SOSP 2017

### DEVICES
 1. [A Case for Redundant Arrays of Inexpensive Disks (RAID)](http://dl.acm.org/citation.cfm?id=50214), David A. Patterson, Garth Gibson, Randy H. Katz.Proceedings of the 1988 ACM SIGMOD International Conference on Management of Data.
    - **SIGOPS: The Hall of Fame Award**  The paper shows how to achieve efficient, fault tolerant and highly available storage using cheap, unreliable disk hardware components.
 1. [Improving the Reliability of Commodity Operating Systems](http://www.cs.wisc.edu/~swift/papers/nooks-sosp.pdf), SOSP 2003
 1. [Understanding modern device drivers](http://www.cs.wisc.edu/~swift/papers/asplos12_drivers.pdf),ASPLOS 2012
 1. [Tolerating Hardware Device Failures in Software.](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.154.5958&rank=1&q=Tolerating%20Hardware%20Device%20Failures%20in%20Software&osm=&ossid=),SOSP 2009
 1. [Gdev: First-Class GPU Resource Management in the Operating System](https://www.usenix.org/system/files/conference/atc12/atc12-final319.pdf),USENIX ATC 2012 
 1. [GPUvm: Why not virtualizing GPUs at the hypervisor?](https://www.usenix.org/sites/default/files/conference/protected-files/atc14_slides_suzuki.pdf),USENIX ATC 2014
