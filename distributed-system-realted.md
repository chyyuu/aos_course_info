# A Distributed Systems Reading List

From https://dancres.github.io/Pages/

## Introduction



I often argue that the toughest thing about distributed systems is changing the way you think. The below is a collection of material I've found useful for motivating these changes.

## Thought Provokers

Ramblings that make you think about the way you design. Not everything can be solved with big servers, databases and transactions.

- [Harvest, Yield and Scalable Tolerant Systems](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.33.411) - Real world applications of CAP from Brewer et al
- 

- [On Designing and Deploying Internet Scale Services](http://mvdirona.com/jrh/talksAndPapers/JamesRH_Lisa.pdf) - James Hamilton
- [The Perils of Good Abstractions](http://www.addsimplicity.com/adding_simplicity_an_engi/2006/12/the_perils_of_g.html) - Building the perfect API/interface is difficult
- [Chaotic Perspectives](http://www.addsimplicity.com/adding_simplicity_an_engi/2007/05/chaotic_perspec.html) - Large scale systems are everything developers dislike - unpredictable, unordered and parallel
- [Data on the Outside versus Data on the Inside](http://www.cidrdb.org/cidr2005/papers/P12.pdf) - Pat Helland
- [Memories, Guesses and Apologies](http://blogs.msdn.com/pathelland/archive/2007/05/15/memories-guesses-and-apologies/) - Pat Helland
- [SOA and Newton's Universe](https://blogs.msdn.microsoft.com/pathelland/2007/05/20/soa-and-newtons-universe/) - Pat Helland
- [Building on Quicksand](http://arxiv.org/abs/0909.1788) - Pat Helland
- [Why Distributed Computing?](http://www.artima.com/weblogs/viewpost.jsp?thread=4247) - Jim Waldo
- [A Note on Distributed Computing](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.41.7628) - Waldo, Wollrath et al
- [Stevey's Google Platforms Rant](https://plus.google.com/112678702228711889851/posts/eVeouesvaVX) - Yegge's SOA platform experience

## Latency

- [Latency Exists, Cope!](http://www.addsimplicity.com/adding_simplicity_an_engi/2007/02/latency_exists_.html) - Commentary on coping with latency and it's architectural impacts
- [Latency - the new web performance bottleneck](http://www.igvita.com/2012/07/19/latency-the-new-web-performance-bottleneck/) - not at all new (see [Patterson](http://dl.acm.org/citation.cfm?id=1022596)), but noteworthy
- [The Tail At Scale](http://research.google.com/pubs/pub40801.html) - the latencychallenges inherent of dealing with latency in large scale systems

## Amazon

Somewhat about the technology but more interesting is the culture and organization they've created to work with it.

- [A Conversation with Werner Vogels](http://queue.acm.org/detail.cfm?id=1142065) - Coverage of Amazon's transition to a service-based architecture
- [Discipline and Focus](http://queue.acm.org/detail.cfm?id=1388773) - Additional coverage of Amazon's transition to a service-based architecture
- [Vogels on Scalability](http://www.itconversations.com/shows/detail1634.html)
- [SOA creates order out of chaos @ Amazon](http://searchwebservices.techtarget.com/originalContent/0,289142,sid26_gci1195702,00.html)

## Google

Current "rocket science" in distributed systems.

- [MapReduce](http://research.google.com/archive/mapreduce.html)
- [Chubby Lock Manager](http://research.google.com/archive/chubby.html)
- [Google File System](http://research.google.com/archive/gfs.html)
- [BigTable](http://research.google.com/archive/bigtable.html)
- [Data Management for Internet-Scale Single-Sign-On](http://www.usenix.org/event/worlds06/tech/prelim_papers/perl/perl.pdf)
- [Dremel: Interactive Analysis of Web-Scale Datasets](http://research.google.com/pubs/pub36632.html)
- [Large-scale Incremental Processing Using Distributed Transactions and Notifications](http://research.google.com/pubs/pub36726.html)
- [Megastore: Providing Scalable, Highly Available Storage for Interactive Services](http://www.cidrdb.org/cidr2011/Papers/CIDR11_Paper32.pdf) - Smart design for low latency Paxos implementation across datacentres.
- [Spanner](http://research.google.com/archive/spanner.html) - Google's scalable, multi-version, globally-distributed, and synchronously-replicated database.
- [Photon](http://research.google.com/pubs/pub41318.html) - Fault-tolerant and Scalable Joining of Continuous Data Streams. Joins are tough especially with time-skew, high availability and distribution.
- [Mesa: Geo-Replicated, Near Real-Time, Scalable Data Warehousing](http://research.google.com/pubs/pub42851.html) - Data warehousing system that stores critical measurement data related to Google's Internet advertising business.

## Consistency Models

Key to building systems that suit their environments is finding the right tradeoff between consistency and availability.

- [CAP Conjecture](http://www.glassbeam.com/sites/all/themes/glassbeam/images/blog/10.1.1.67.6951.pdf) - Consistency, Availability, Parition Tolerance cannot all be satisfied at once
- [Consistency, Availability, and Convergence](http://www.cs.utexas.edu/users/dahlin/papers/cac-tr.pdf) - Proves the upper bound for consistency possible in a typical system
- [CAP Twelve Years Later: How the "Rules" Have Changed](http://www.infoq.com/articles/cap-twelve-years-later-how-the-rules-have-changed) - Eric Brewer expands on the original tradeoff description
- [Consistency and Availability](http://www.infoq.com/news/2008/01/consistency-vs-availability) - Vogels
- [Eventual Consistency](http://www.allthingsdistributed.com/2007/12/eventually_consistent.html) - Vogels
- [Avoiding Two-Phase Commit](http://www.addsimplicity.com/adding_simplicity_an_engi/2006/12/avoiding_two_ph.html) - Two phase commit avoidance approaches
- [2PC or not 2PC, Wherefore Art Thou XA?](http://www.addsimplicity.com/adding_simplicity_an_engi/2006/12/2pc_or_not_2pc_.html) - Two phase commit isn't a silver bullet
- [Life Beyond Distributed Transactions](https://blogs.msdn.microsoft.com/pathelland/2007/05/16/link-to-quotlife-beyond-distributed-transactions-an-apostates-opinion/) - Helland
- [If you have too much data, then 'good enough' is good enough](http://queue.acm.org/detail.cfm?id=1988603) - NoSQL, Future of data theory - Pat Helland
- [Starbucks doesn't do two phase commit](http://www.enterpriseintegrationpatterns.com/docs/IEEE_Software_Design_2PC.pdf) - Asynchronous mechanisms at work
- [You Can't Sacrifice Partition Tolerance](http://codahale.com/you-cant-sacrifice-partition-tolerance/) - Additional CAP commentary
- [Optimistic Replication](http://www.hpl.hp.com/techreports/2002/HPL-2002-33.pdf) - Relaxed consistency approaches for data replication

## Theory

Papers that describe various important elements of distributed systems design.

- [Distributed Computing Economics](https://arxiv.org/pdf/cs/0403019.pdf) - Jim Gray
- [Rules of Thumb in Data Engineering](http://research.microsoft.com/pubs/68636/ms_tr_99_100_rules_of_thumb_in_data_engineering.pdf) - Jim Gray and Prashant Shenoy
- [Fallacies of Distributed Computing](http://en.wikipedia.org/wiki/Fallacies_of_Distributed_Computing) - Peter Deutsch
- [Impossibility of distributed consensus with one faulty process](http://doi.acm.org/10.1145/3149.214121) - also known as FLP [access requires account and/or payment, a free version can be found [here](http://groups.csail.mit.edu/tds/papers/Lynch/jacm85.pdf)]
- [Unreliable Failure Detectors for Reliable Distributed Systems.](http://citeseer.ist.psu.edu/356748.html) A method for handling the challenges of FLP
- [Lamport Clocks](http://research.microsoft.com/users/lamport/pubs/time-clocks.pdf) - How do you establish a global view of time when each computer's clock is independent
- [The Byzantine Generals Problem](http://research.microsoft.com/users/lamport/pubs/byz.pdf)
- [Lazy Replication: Exploiting the Semantics of Distributed Services](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.17.469)
- [Scalable Agreement - Towards Ordering as a Service](http://www.usenix.org/event/hotdep10/tech/full_papers/Kapritsos.pdf)
- [Scalable Eventually Consistent Counters over Unreliable Networks](http://arxiv.org/pdf/1307.3207v1.pdf) - Scalable counting is tough in an unreliable world

## Languages and Tools

Issues of distributed systems construction with specific technologies.

- [Programming Distributed Erlang Applications: Pitfalls and Recipes](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.137.9417&rep=rep1&type=pdf) - Building reliable distributed applications isn't as simple as merely choosing Erlang and OTP.

## Infrastructure

- [Principles of Robust Timing over the Internet](http://queue.acm.org/detail.cfm?id=1773943) - Managing clocks is essential for even basics such as debugging

## Storage

- [Consistent Hashing and Random Trees](http://www.akamai.com/dl/technical_publications/ConsistenHashingandRandomTreesDistributedCachingprotocolsforrelievingHotSpotsontheworldwideweb.pdf)
- [Amazon's Dynamo Storage Service](http://www.allthingsdistributed.com/2007/10/amazons_dynamo.html)

## Paxos Consensus

Understanding this algorithm is the challenge. I would suggest reading "Paxos Made Simple" before the other papers and again afterward.

- [The Part-Time Parliament](http://research.microsoft.com/users/lamport/pubs/lamport-paxos.pdf) - Leslie Lamport
- [Paxos Made Simple](http://research.microsoft.com/users/lamport/pubs/paxos-simple.pdf) - Leslie Lamport
- [Paxos Made Live - An Engineering Perspective](http://static.googleusercontent.com/media/research.google.com/en/us/archive/paxos_made_live.pdf) - Chandra et al
- [Revisiting the Paxos Algorithm](http://groups.csail.mit.edu/tds/paxos.html) - Lynch et al
- [How to build a highly available system with consensus](http://research.microsoft.com/lampson/58-Consensus/Acrobat.pdf) - Butler Lampson
- [Reconfiguring a State Machine](http://research.microsoft.com/en-us/um/people/lamport/pubs/reconfiguration-tutorial.pdf) - Lamport et al - changing cluster membership
- [Implementing Fault-Tolerant Services Using the State Machine Approach: a Tutorial](http://citeseer.ist.psu.edu/viewdoc/summary?doi=10.1.1.20.4762) - Fred Schneider

## Other Consensus Papers

- [Mencius: Building Efficient Replicated State Machines for WANs](http://www.usenix.org/event/osdi08/tech/full_papers/mao/mao_html/) - consensus algorithm for wide-area network
- [In Search of an Understandable Consensus Algorithm](https://raft.github.io/raft.pdf) - The extended version of the RAFT paper, an alternative to PAXOS.

## Gossip Protocols (Epidemic Behaviours)

- [How robust are gossip-based communication protocols?](http://infoscience.epfl.ch/record/109302?ln=en)
- [Astrolabe: A Robust and Scalable Technology For Distributed Systems Monitoring, Management, and Data Mining](http://www.cs.cornell.edu/home/rvr/papers/astrolabe.pdf)
- [Epidemic Computing at Cornell](http://www.allthingsdistributed.com/historical/archives/000456.html)
- [Fighting Fire With Fire: Using Randomized Gossip To Combat Stochastic Scalability Limits](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.5.4000)
- [Bi-Modal Multicast](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.17.7959)
- [ACM SIGOPS Operating Systems Review - Gossip-based computer networking](http://dl.acm.org/citation.cfm?id=1317379)
- [SWIM: Scalable Weakly-consistent Infection-style Process Group Membership Protocol](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.18.9737)

## P2P

- [Chord](http://pdos.csail.mit.edu/chord/papers/paper-ton.pdf): A Scalable Peer-to-peer Lookup Protocol for Internet Applications
- [Kademlia](https://pdos.csail.mit.edu/~petar/papers/maymounkov-kademlia-lncs.pdf): A Peer-to-peer Information System Based on the XOR Metric
- [Pastry](http://research.microsoft.com/en-us/um/people/antr/PAST/pastry.pdf): Scalable, decentralized object location and routing for large-scale peer-to-peer systems
- [PAST](http://research.microsoft.com/en-us/um/people/antr/PAST/hotos.pdf): A large-scale, persistent peer-to-peer storage utility - storage system atop Pastry
- [SCRIBE](http://research.microsoft.com/en-us/um/people/antr/PAST/jsac.pdf): A large-scale and decentralised application-level multicast infrastructure - wide area messaging atop Pastry
