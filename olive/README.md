# Olive Executable Archive

- pros
  - less components/software to maintain than EaaSI
    - required: a normal web server to host files (e.g. nginx or apache), and VMNetX client software only
  - OAI-PMH support is probably not that hard to implement
  - can download portions of the VM on demand

## Fork

Our fork of [VMNetX](https://github.com/cmusatyalab/vmnetx.git) (called Caviar) is available here: https://github.com/gt-ospo/vmnetx.git

Current progress:
- can reproduce / run (the original) VMNetX's NXPK files (with caveats, see TODOs section below)

TODOs:
- support NXPK files' memory images

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
  - Note that KVM/QEMU is just a standard virtual machine
- VMNetX provides access to the guest OS disk
  - In a non-VMNetX setting, this would usually be provided by a VM image (e.g. `.vmdk` or `.qcow2` file), which contains the disk of the guest OS
  - VMNetX downloads required parts of the OS image on-demand (just like how a YouTube video is streamed on-demand)
  - VMNetX can also set an initial memory image
    - We do not have to wait for the OS to boot up
    - We can document a VM along with its memory, making sure we store all necessary state for reproduction
- A standard web server provides the enttire guest OS disk

The below image provides a visual organization of the above.

![The VMNetX client provides a cache layer between an unmodified web server and the KVM/QEMU ](../tutorial_images/olive/architecture.png)

References:
- http://reports-archive.adm.cs.cmu.edu/anon/2015/abstracts/15-115.html

## Tutorial: Get Started with Olive/VMNetX

Note: we call our fork of VMNetX Caviar, to distinguish it from the original.

1. Download Caviar
  - Go to https://github.com/gt-ospo/vmnetx/actions/workflows/go.yml
  - Click the first green checkmark link ![View of GitHub Actions workflow runs - click the first one](../tutorial_images/olive/caviar-workflows.png)
  - Click the `build-caviar` artifact to download it
  ![artifact list](../tutorial_images/caviar-artifacts.png)
  - Unzip the file - it should contain an executable for your machine

- what is olive - see glossary.md
- compare to eaasi
- quick architecurutal background 
  - vmnetx
- how to get started with it
  - not currently compatable so it needs to be updated (fork)
- key updates
- openMPI container tutorial 