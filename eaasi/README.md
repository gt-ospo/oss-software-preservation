# EaaSI Documentation

This folder contains documentation and tutorials for using **EaaSI** (Emulation-as-a-Service Infrastructure), a web-based platform developed by Yale University for software preservation. EaaSI enables users to create, configure, and run emulated computing environments directly in the browser.

---

## Overview

EaaSI integrates emulators like QEMU into a client-server web framework. It allows for the preservation and re-use of legacy operating systems and applications by packaging them into shareable environments.

---

## Tutorials

- [What is EaaSI?](https://eaasi.gitlab.io/eaasi_user_handbook/overview/introduction.html)
- [Enable multicore support](./multicore.md)
- [Upload a small file (<2.6MB)](./uploading-small-files.md)
- [Upload a large file (>2.6MB)](./uploading-large-files.md)
- [Install OpenMPI](./openmpi-on-base-environment.md)
- [Run Docker containers on EaaSI](./oci.md)
- [Example: OpenMPI container guide](./mpi-container/README.md)
- [Ubuntu-based container examples](./oci-ubuntu/README.md)

---

## Use Cases

- Interactive access to legacy applications
- Scientific reproducibility (via preserved software environments)
- Teaching historical computing
- Archiving and accessing obsolete file formats

---

## OCI/Docker Support

EaaSI supports uploading and executing Docker containers, making it easy to preserve Linux command-line tools and scientific pipelines.

See: [OCI container support](./oci.md)

---

## Tips

- For Lubuntu-based environments, follow the small/large file upload guides
- Floppy disk format is currently the most reliable option for mounting files
- Make sure to **save** your emulation after file uploads to persist changes

---

