# OSS Software Preservation

This repository documents various platforms and strategies for preserving legacy software. As software ages, the systems required to run it often become obsolete. Software preservation ensures that important digital artifacts such as scientific tools, historical applications, vintage games, and cultural content, remain accessible in the future.

This work explores a range of open-source tools and systems that support software emulation, virtualization, and reproducibility. It compares their architectures, features, and use cases, and provides hands-on guides for setup and usage.

---

## Purpose

Digital content becomes unusable when the software or systems needed to run it are no longer supported. The goal of this project is to preserve both the software and its environment (operating systems, dependencies, configurations) in a reusable and shareable way.

This repository focuses on:

- Emulation platforms (e.g., QEMU, VMNetX, Docker)
- Tools for archiving runnable software environments
- Tutorials for capturing, modifying, and re-executing legacy software
- Comparisons between major software preservation systems (e.g., EaaSI vs Olive)

---

## Platforms and Tools

### EaaSI (Emulation-as-a-Service Infrastructure)
EaaSI is a Yale-led platform designed to allow users to create and share emulated computing environments through a web interface.

- [EaaSI Docs and Tutorials](./eaasi)
  - [What is EaaSI?](https://eaasi.gitlab.io/eaasi_user_handbook/overview/introduction.html)
  - [Upload files to EaaSI Environments](./eaasi/uploading-small-files.md)
  - [Run OpenMPI on EaaSI](./eaasi/mpi-container/README.md)
  - [Use Docker containers on EaaSI](./eaasi/oci.md)

### Olive Archive
Olive (developed by Carnegie Mellon) focuses on preserving software by delivering full virtual machines over the web. It uses VMNetX to stream only the parts of a VM that are needed.

- [Olive Docs and Setup](./olive)
  - [Caviar (Fork of VMNetX)](./olive/caviar-installation.md)
  - [Import and run NXPK files](./olive/import-nxpk.md)
  - [Run OpenMPI on Olive](./olive/openmpi.md)

### 🛠Other Platforms
- [KEEP Emulation Framework](./other-platforms/KEEP.md)
- [Dioscuri](./other-platforms/Dioscuri.md)
- [Emularity (used by Internet Archive)](./other-platforms/Emularity.md)
- [Recompute](./other-platforms/Recompute.md)

---

## Platform Comparisons

In-depth [comparison of EaaSI and Olive Archive](./other-platforms/eaasi_olive_comparison.md) across architecture, usability, scalability, and accessibility.

---

## Getting Started

1. Choose a platform: [EaaSI](./eaasi), [Olive](./olive), or [Other Tools](./other-platforms)
2. Follow the linked tutorials to create or reuse software environments
3. Archive and share virtual machines or containers
4. Use emulators or VM streaming tools to run preserved software

---
