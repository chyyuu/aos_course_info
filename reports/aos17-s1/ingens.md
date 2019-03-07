# Report for the paper: Coordinated and Efficient Huge Page Management with Ingens
[OSDI2016](https://www.usenix.org/conference/osdi16/technical-sessions/presentation/kwon)
## Summary of major innovations
本文提出了一个关于huge page支持的framework，基于：
1. contiguity
2. track utilizations and access frequency of memory pages

Based on ideas above, Ingens achieve in general:
1. acceptable overhead
2. reduction memory bloat from 69% to 1%
3. tail-latency reduction 41%
4. performance 18% up
5. fairness for the promotion of huge pages, so fair performance

## Problems this paper mentioned
随着内存的变大，TLB从虚拟地址到物理地址的转换对程序的影响变大。huge page意味着更大的TLB coverage, 更小的miss，更快的地址翻译。同时huge page也给系统带来更大的internal fragmentation and external fragmentation.当下，Windows and OS X通过单独为huge page的分配提供单独的接口，Linux则通过transparent huge page suport管理huge page。
In general, Linux's Transparent huge page support is as following:
1. Greedy: promotes huge page in page fault handler
2. Aggressive: always try to promote as long as the system has a huge page

当下，Linux's Transparent huge page在给应用程序带来性能提升的同事，存在以下问题：
1. page fault cost.在Page fault中，如果内存碎片允许分配huge page时，需要对huge page进行清零(memset, clear for security)。否则，需要对内存进行compaction。这些操作对于page fault handler是同步的。从而，pgae fault开销更大。
2. memory bloat.对于sparsely allocated memory, Linux都分配huge page。这会产生很大的内部碎片。实验显示Redis造成69%的bloat。
3. increase fragmentation. 
4. Unfair performance: Linux内部在promote时候，异步地扫描进程，首先分配huge page给一个进程，处理完该进程之后才会考虑下一进程。所以说Linux huge page is unfair.
5. 为了降低内存使用，不同进程共享物理页时，Linux会demote包含共享页的huge page。因此会降低应用程序的性能。另一种方法是当base page包含在huge page时，不允许共享base page，只允许共享huge page。

Compared to FreeBSD: FreeBSD is more conservative. FreeBSD只有当一个huge page(2MB)内所有base page(4KB)都被使用时，才会promote. So FreeBSD will reduce memory bloating, but slower performance.

## Related work
The topic of huge page and TLB is verty hot ref[2] in the past and now.

## Some intriguing points

### Monitoring space and time
1. utilization of huge-page sized regions(space): Util bitvector
2. how frequently huge-page sized regions are accessed(time): Access bitvector

### Fast page faults
1. only alloc base pages
2. page fault handler signals a background thread(Promote-kth) to protmote asynchronously.

### Utilization-based promotion
1. 只有当一个huge page内使用率在90%以上才会promote
2. 当一个base page free的时候，如果huge page使用率较高的话，则不demote，而是仅仅更新Util bitvector

### Proactive batched compaction
很多时候需要使用huge page: promotion, DMA, etc.
因此，提前预留足够大的物理内存空间会很有意义，在需要分配huge page的时候，可以直接响应。这里需要设置扫描的粒度，否则会过多占用资源而影响程序性能。在compact的时候，不移动使用频繁的page，因为移动的话需要清空TLB。从而伤害程序性能。

### Balance page sharing with performance
在share base page的时候，如果包含base page的huge Page的access frequency较高的话，不允许share page，不能demote huge page。

### Proportional promotion manages contiguity
Ingens根据每个进程或者虚拟机的当前huge page使用情况对他们进行平衡，对于分配较多的huge page，更小的概率获得新的huge page。对于访问较少的huge page的进程，获得新的huge page的概率更小。以此定义进程或者虚拟机huge page 优先级: M = S / (H * (f + t * (1-f))). 其中，S是常数，H是进程获得的huge page的数量，f是当前进程访问较少的huge page占分配给该进程的总的huge Page的占比。

### Fair promotion
Ingens根据进程的huge page的优先级进行分配huge Page，从而保证了一定的fairness。

## How can the research be improved?

## Survey paper list
1. [TLB](https://en.wikipedia.org/wiki/Translation_lookaside_buffer)
2. [A Survey of Techniques for Architecting TLBs](https://www.academia.edu/29585076/A_Survey_of_Techniques_for_Architecting_TLBs), Concurrency and Computation: Practice and Experience, 2016.
3. [Cache](https://en.wikipedia.org/wiki/CPU_cache#cite_note-4)
4. Navarro J, Iyer S, Druschel P, Cox A. Practical, transparent operating system support for superpages. ACM SIGOPS Operating Systems Review 2002; 36(SI):89–104.
