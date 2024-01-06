## Rust based OS/Hypervisor/VMM/Firmwire

### Research
#### OS
- [RedLeaf Operating System](https://github.com/mars-research/redleaf): RedLeaf is a research operating system developed from scratch in Rust to explore the impact of language safety on operating system organization.
- [Node Replicated Kernel](https://nrkernel.systems/) : The Node Replicated Kernel(NrOS) is an (experimental) research OS kernel for x86-64 (amd64) machines written in rust.
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

#### Hypervisor
- [shyper](https://gitee.com/openeuler/rust_shyper)

### Industry || Hacker
- [occlum](https://github.com/occlum/occlum): A memory-safe, multi-process library OS (LibOS) for Intel SGX. 
  - [ngo](https://github.com/occlum/ngo): Next-Gen Occlum, a work-in-progress fork of Occlum that is optimized for the next-generation of Intel SGX
- [drone](https://www.drone-os.com/) : an Embedded Operating System for writing real-time applications in Rust with async/await features
- [redox](https://www.redox-os.org/) : a Unix-like microernel Operating System written in Rust
- [KataOS](https://github.com/AmbiML/sparrow-kata-full)：a home-grown operating system named KataOS, that runs on top of seL4 and (ignoring the seL4 kernel) is written almost entirely in Rust
- [embassy os kernel](https://github.com/embassy-rs/embassy)：Embassy is the next-generation framework for embedded applications.
- [aero kernel](https://github.com/Andy-Python-Programmer/aero)：a new modern, experimental, unix-like operating system following the monolithic kernel design. 
- [Rust for Linux](https://github.com/Rust-for-Linux)
  - [Building an out-of-tree Rust Kernel Module part1](https://blog.rnstlr.ch/building-an-out-of-tree-rust-kernel-module.html)
  - [Building an out-of-tree Rust Kernel Module part2](https://blog.rnstlr.ch/building-an-out-of-tree-rust-kernel-module-part-two.html)

#### some user-land vmm components
- [google crosvm](https://chromium.googlesource.com/chromiumos/platform/crosvm/): crosvm - The Chrome OS Virtual Machine Monitor.
- [Huawei stratovirt](https://gitee.com/openeuler/stratovirt): stratovirt in openEuler linux distrbution.
- [AWS firecracker](https://github.com/firecracker-microvm/firecracker): The main component of Firecracker is a VMM that uses the Linux Kernel Virtual Machine (KVM) to create and run microVMs.
- [intel cloud-hypervisor](https://github.com/cloud-hypervisor/cloud-hypervisor): Cloud Hypervisor is an open source Virtual Machine Monitor (VMM) that runs on top of KVM and the MSHV hypervisors .
- [rust-vmm ORG's repos in github](https://github.com/orgs/rust-vmm/repositories): rust-vmm is an open-source project that empowers the community to build custom Virtual Machine Monitors (VMMs) and hypervisors.

### Education
#### OS
- [Blog OS](http://os.phil-opp.com/) : detail blogs about Writing an OS in Rust in x86-64
- [osblog on riscv](https://github.com/sgmarz/osblog) : The Adventures of OS: Making a RISC-V Operating System using Rust
- [rcore-tutorial](https://github.com/rcore-os/rCore-Tutorial-v3) : basic educational OS labs in riscv for OS course in Tsinghua Univ.
- [zcore-tutorial](https://github.com/rcore-os/zCore-Tutorial) : simplified  zcore educational labs in user-mode x86-64.
- [tiny os kernel component labs](https://github.com/chyyuu/os_kernel_lab) : a lot of tiny os kernel component labs
- [cs3210-2020 in Georgia Tech](https://tc.gts3.org/cs3210/2020/spring/info.html) : rust os labs in Raspberry Pi
- [eduOS-rs](https://github.com/RWTH-OS/eduOS-rs): A teaching operating system(Unix-like operating system based on a monolithic architecture in x86-64) written in Rust. 

#### Hypervisor
- [RVM Tutorial](https://github.com/rcore-os/RVM-Tutorial)
- [Hypervisor 101 in Rust](https://github.com/tandasat/Hypervisor-101-in-Rust)
- [RVirt](https://github.com/mit-pdos/RVirt): RVirt is an S-mode trap-and-emulate hypervisor for RISC-V. It is currently targeted at QEMU's virt machine type.
- [RVM type1 -- Rcore Virtual Machine x86-64](https://github.com/rcore-os/RVM) & [RVM type 1 -- Rcore Virtual Machine x86-64/rv64](https://github.com/rcore-riscv-hypervisor-dev/RVM) & (RVM type 1.5)[https://github.com/rcore-os/RVM1.5]: An experimental hypervisor library written in Rust to build both type-1 and type-2 hypervisors. Supported architecture: x86_64 (Intel VMX) and RISC-V

#### SBI
- [rustsbi firmware](https://github.com/rustsbi/rustsbi) : RISC-V Supervisor Binary Interface (SBI) implementation in Rust; runs on M-mode.

### Hobby
#### OS
- [Lateral](https://github.com/carterisonline/lateral)： Lateral is a work-in-progress multitasking monolithic kernel + OS meant as a fun summer project.
- [snakeos](https://github.com/trusch/snakeos) : This is the game snake, bootable on a x86_64 CPU followed by blogos
- [MOROS](https://github.com/vinc/moros) ：MOROS is a hobby operating system, targets computers with a x86-64 architecture and a BIOS.
- [bern RTOS](https://gitlab.com/bern-rtos/bern-rtos): A real-time operating system for microcontrollers written in Rust
   - [Bern RTOS site](https://bern-rtos.org/)
- [Real-Time Interrupt-driven Concurrency (RTIC)](https://github.com/rtic-rs): Real-Time Interrupt-driven Concurrency (RTIC) framework
  - [RTIC site](https://rtic.rs)
- [Rux -- microkernel written in Rust](https://source.that.world/source/rux/) 
  - [github repo](https://github.com/sorpaas/rux)
- [poplar -- microkernel and userspace written in rust](https://github.com/IsaacWoods/poplar)
  - [book of poplar](https://poplar.isaacwoods.dev/book/) 
- [D7 operating system -- microkernel written in Rust](https://github.com/Dentosal/rust_os)
- [kerla OS kernel](https://github.com/nuta/kerla)：Kerla is a monolithic operating system kernel written from scratch in Rust which aims to be compatible with the Linux ABI, that is, it runs Linux binaries without any modifications.
- [	HarSaRK_multi_rs: A Hard Real-time Kernel for Multi-core Microcontrollers in Rust Language](https://github.com/Autonomous-Cyber-Physical-Systems/harsark.rs)
   - [HarSaRK paper](https://autonomous-cyber-physical-systems.github.io/harsark.rs/HarSaRK-RS%20-%20WoRIE%2720.pdf)
- [Fomos:Experimental OS, built with Rust, gui, mouse, Exo-kernels, x86-64](https://github.com/Ruddle/Fomos)
#### Hypervisor
- [diosix](https://github.com/diodesign/diosix)
- [A toy Aarch64 hypervisor written in Rust.](https://github.com/stong/rustos-hv)  with [tech report](https://github.com/stong/rustos-hv/blob/master/report.pdf)
- [MilvusVisor is a thin hypervisor that runs on aarch64 CPUs.](https://github.com/RIKEN-RCCS/MilvusVisor)
- [rHyper](https://github.com/KarmaD7/rHyper)
- [hypocaust-2](https://github.com/KuangjuX/hypocaust-2)
