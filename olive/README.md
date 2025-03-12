# Olive Executable Archive

- pros
  - less components/software to maintain than EaaSI
    - required: a normal web server to host files (e.g. nginx or apache), and VMNetX client software only
  - OAI-PMH support is probably not that hard to implement
  - can download portions of the VM on demand

## Fork

Our fork of [VMNetX](https://github.com/cmusatyalab/vmnetx.git) is available here: https://github.com/gt-ospo/vmnetx.git

Current progress:
- can reproduce / run (the original) VMNetX's NXPK files

TODOs:
- 

## Comparison to EaaSI

| --- 
| Virtualization Method

## Olive/VMNetX Architecture

To reiterate:
- Olive is a website with a collection of VM images (e.g. Windows 95),
- while VMNetX is the client software that runs the VMs.
- Guest OS is the operating system running inside a virtual machine
- Host OS is the operating system running the virtual machine

The main architecture is as follows:
- KVM/QEMU runs the guest OS
  - 

![The VMNetX client provides a cache layer between an unmodified web server and the KVM/QEMU ](../tutorial_images/olive/architecture.png)

## Tutorial: Get Started with Olive/VMNetX


- what is olive - see glossary.md
- compare to eaasi
- quick architecurutal background 
  - vmnetx
- how to get started with it
  - not currently compatable so it needs to be updated (fork)
- key updates
- openMPI container tutorial 