## Rust based OS/Hypervisor/VMM/Firmwire

### Research
- [RedLeaf Operating System](https://github.com/mars-research/redleaf): RedLeaf is a research operating system developed from scratch in Rust to explore the impact of language safety on operating system organization.
- [Node Replicated Kernel](https://nrkernel.systems/) : The Node Replicated Kernel is an (experimental) research OS kernel for x86-64 (amd64) machines written in rust.
- [Theseus](https://github.com/theseus-os/Theseus) : Theseus is a new OS written from scratch in Rust to experiment with novel OS structure, better state management, and how to leverage intralingual design principles to shift OS responsibilities like resource management into the compiler.
- [tock](https://www.tockos.org/) : an embedded operating system designed for running multiple concurrent, mutually distrustful applications on low-memory and low-power microcontrollers
- [hermitcore](https://hermitcore.org/) : HermitCore is a novel unikernel operating system targeting a scalable and predictable runtime behavior for HPC and cloud environments.
  - [rustyhermit unikernel](https://github.com/hermitcore/rusty-hermit)
  - [uhyve hypervisor](https://github.com/hermitcore/uhyve) 
- [zcore](https://github.com/rcore-os/zCore) : Reimplement Some parts of Zircon microkernel & Linux kernel in safe Rust as a userspace program!
- [aero  OS running in Qemu x8-64 smp](https://github.com/Andy-Python-Programmer/aero)
- [Manticore](https://manticoreos.io/): kernel with the aim of exploring the parakernel OS architecture.
   - [parakernel hotos19](http://penberg.org/parakernel-hotos19.pdf)
   - [manticore srouce code](https://github.com/manticoreos/manticore)

### Industry || Hacker
- [occlum](https://github.com/occlum/occlum): A memory-safe, multi-process library OS (LibOS) for Intel SGX. 
  - [ngo](https://github.com/occlum/ngo): Next-Gen Occlum, a work-in-progress fork of Occlum that is optimized for the next-generation of Intel SGX
- [drone](https://www.drone-os.com/) : an Embedded Operating System for writing real-time applications in Rust with async/await features
- [redox](https://www.redox-os.org/) : a Unix-like Micro-Kernel Operating System written in Rust
- [KataOS](https://github.com/AmbiML/sparrow-kata-full)：a home-grown operating system named KataOS, that runs on top of seL4 and (ignoring the seL4 kernel) is written almost entirely in Rust
- [embassy os kernel](https://github.com/embassy-rs/embassy)：Embassy is the next-generation framework for embedded applications.
- [aero kernel](https://github.com/Andy-Python-Programmer/aero)：a new modern, experimental, unix-like operating system following the monolithic kernel design. 

#### some user-land vmm components
- [google crosvm](https://chromium.googlesource.com/chromiumos/platform/crosvm/): crosvm - The Chrome OS Virtual Machine Monitor.
- [Huawei stratovirt](https://gitee.com/openeuler/stratovirt): stratovirt in openEuler linux distrbution.
- [AWS firecracker](https://github.com/firecracker-microvm/firecracker): The main component of Firecracker is a VMM that uses the Linux Kernel Virtual Machine (KVM) to create and run microVMs.
- [intel cloud-hypervisor](https://github.com/cloud-hypervisor/cloud-hypervisor): Cloud Hypervisor is an open source Virtual Machine Monitor (VMM) that runs on top of KVM and the MSHV hypervisors .
- [rust-vmm ORG's repos in github](https://github.com/orgs/rust-vmm/repositories): rust-vmm is an open-source project that empowers the community to build custom Virtual Machine Monitors (VMMs) and hypervisors.

### Education
- [Blog OS](http://os.phil-opp.com/) : detail blogs about Writing an OS in Rust in x86-64
- [osblog on riscv](https://github.com/sgmarz/osblog) : The Adventures of OS: Making a RISC-V Operating System using Rust
- [rcore-tutorial](https://github.com/rcore-os/rCore-Tutorial-v3) : basic educational OS labs in riscv for OS course in Tsinghua Univ.
- [zcore-tutorial](https://github.com/rcore-os/zCore-Tutorial) : simplified  zcore educational labs in user-mode x86-64.
- [tiny os kernel component labs](https://github.com/chyyuu/os_kernel_lab) : a lot of tiny os kernel component labs
- [rustsbi firmware](https://github.com/rustsbi/rustsbi) : RISC-V Supervisor Binary Interface (SBI) implementation in Rust; runs on M-mode.
- [RVirt](https://github.com/mit-pdos/RVirt): RVirt is an S-mode trap-and-emulate hypervisor for RISC-V. It is currently targeted at QEMU's virt machine type.
- [RVM -- Rcore Virtual Machine](https://github.com/rcore-os/RVM) : An experimental hypervisor library written in Rust to build both type-1 and type-2 hypervisors. Supported architecture: x86_64 (Intel VMX) and RISC-V
- [	HarSaRK_multi_rs: A Hard Real-time Kernel for Multi-core Microcontrollers in Rust Language](https://github.com/Autonomous-Cyber-Physical-Systems/harsark.rs)
   - [HarSaRK paper](https://autonomous-cyber-physical-systems.github.io/harsark.rs/HarSaRK-RS%20-%20WoRIE%2720.pdf)
### Hobby
- [Lateral](https://github.com/carterisonline/lateral)： Lateral is a work-in-progress multitasking monolithic kernel + OS meant as a fun summer project.
- [snakeos](https://github.com/trusch/snakeos) : This is the game snake, bootable on a x86_64 CPU followed by blogos
- [MOROS](https://github.com/vinc/moros) ：MOROS is a hobby operating system, targets computers with a x86-64 architecture and a BIOS.
- [bern RTOS](https://gitlab.com/bern-rtos/bern-rtos): A real-time operating system for microcontrollers written in Rust
   - [Bern RTOS site](https://bern-rtos.org/)
- [Real-Time Interrupt-driven Concurrency (RTIC)](https://github.com/rtic-rs): Real-Time Interrupt-driven Concurrency (RTIC) framework
  - [RTIC site](https://rtic.rs)
