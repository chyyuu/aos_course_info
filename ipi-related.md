Intra-process isolation:
## Introduction
Why we want's Intra-process isolation?
1. Security reason.

  - Code/Data may have security level in legency: 
    - a. RSA and session keys in webserver.
    - b. Code pointers: may be hijacked.(Code pointer integrity)
    - c. Sensitive data: if ( task\_struct-\>is\_root)

2. Performance reason.
  - Why we want put multipule task into one domain:  
  [Process-in-process: techniques for practical address-space sharing](http://people.cs.pitt.edu/~jacklange/teaching/cs3510-f19/papers/hpdc18.pip.pdf) (HPDC '18)
  Despite architecture gain, putting multitask into one address space are mainly for fast IPC.  
  - But, how fast we can achieve with different address space for IPC?   
  [SkyBridge: Fast and Secure IPC for Microkernels](https://ipads.se.sjtu.edu.cn/_media/publications/skybridge-eurosys19.pdf) (EuroSys '19)  
  [XPC: architectural support for secure and efficient cross process call](https://ipads.se.sjtu.edu.cn/_media/publications/duisca19.pdf) (ISCA '19)

    Despite of limitation of these methods, even with the performance improvment on IPC, the key problem is that the number of IPC is still high, which disallow the performance to achieve as one address space method.

3. The root cause of isolation: memory bugs:  
[SoK: Eternal War in Memory](https://people.eecs.berkeley.edu/~dawnsong/papers/Oakland13-SoK-CR.pdf)  (S&P '13)  
So, a memory safty domain is also isolated from the rest part of the system.

How to achieve efficient, flexible, and compatible intra-process isolation, I think, it's a building block in computer security area.

An overview about isolation in one address space, how many methods we have and how to compare them:  
[No Need to Hide: Protecting Safe Regions on Commodity Hardware](https://www.cs.vu.nl/~giuffrida/papers/memsentry_eurosys17.pdf) (Eurosys '17)

## Dive deeper
1. Hardware methods
  - x86 memory segment
[Native Client: A Sandbox for Portable, Untrusted x86 Native Code](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/34913.pdf) (S&P '09)

  - Page table permission extension:
    - Intel MPK (only usable in user space.)  
    Can we use MPK without CFI:  
    [ERIM: Secure, Efficient in-process Isolation with Memory Protection Keys](https://www.usenix.org/system/files/sec19-vahldiek-oberwagner_0.pdf) (Sec’19)  

      Can we use MPK in kernel space:  
    [IskiOS: Lightweight defense against kernel-level code-reuse attacks](https://arxiv.org/pdf/1903.04654) (Arxiv '2019)


    - optional:  
      [Hodor: Intra-process isolation for high-throughput data plane libraries](https://www.usenix.org/system/files/atc19-hedayati-hodor.pdf) (ATC’19)
      
      ARM DARC(deprecated on AArch64):   
      [Domain Isolated Kernel: A lightweight sandbox for untrusted kernel extensions](https://daehee87.github.io/data/dikernel.pdf) (C&P’18)

  - Memory tagging

    [Pointer Tagging for Memory Safety](https://www.microsoft.com/en-us/research/uploads/prod/2019/07/Pointer-Tagging-for-Memory-Safety.pdf)

  - Trust Execution enviroment  
  
    [Secured Routines: Language-based Construction of Trusted Execution Environments](https://www.usenix.org/system/files/atc19-ghosn_0.pdf) (ATC '19): 


1. Langage based methods
  - SFI
    - Masking:   
    [Evaluating SFI for a CISC Architecture](https://www.usenix.org/event/sec06/tech/mccamant/mccamant.pdf) (Security '06)  
    [Adapting Software Fault Isolation to Contemporary CPU Architectures](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/35649.pdf) (Security '10).
    - Access check list: [Software fault isolation with API integrity and multi-principal modules](https://dspace.mit.edu/bitstream/handle/1721.1/72580/Kaashoek_Software%20fault.pdf?sequence=1&isAllowed=y) 
      - optional  
      [XFI: Software guards for system address spaces](https://www.usenix.org/legacy/event/osdi06/tech/full_papers/erlingsson/erlingsson.pdf) (OSDI '06)  
      [Fast byte-granularity software fault isolation](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/BGI-SOSP.pdf) (SOSP '09)
    - SFI+MPX
      - [Occlum: Secure and Efficient Multitasking Inside a Single Enclave of Intel SGX](https://arxiv.org/abs/2001.07450)(ASPLOS’20).
      - optional: [ConfLLVM: A Compiler for Enforcing Data Confidentiality in Low-Level Code](https://people.mpi-sws.org/~dg/papers/eurosys19.pdf)(Eurosys’19)
  - Safe language
    - Rust: [NetBricks: Taking the V out of NFV](https://www.usenix.org/system/files/conference/osdi16/osdi16-panda.pdf)(OSDI’16)
    - WebAssembly: [Not So Fast: Analyzing the Performance of WebAssembly vs. Native Code](https://arxiv.org/pdf/1901.09056.pdf) (ATC '19)
    - [Singularity: Rethinking the Software Stack](https://courses.cs.washington.edu/courses/cse551/15sp/papers/singularity-osr07.pdf) (OSR '07)

## Think further
But,byond the memory isolation, is it enough?  
[Time protection: the missing OS abstraction](http://echronos.systems/publications/csiro_full_text/Ge_YCH_19.pdf) (Eurosys '19)
