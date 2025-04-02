# Archive Software that uses OpenMPI

## Overview

In this tutorial, we will archive software that uses OpenMPI.
We will use an image with OpenMPI and a compiler suite preinstalled, and then use it to compile and run a simple OpenMPI program.

## Requirements

This tutorial assumes that the user has a working installation of caviar ready. If this is not the case, follow [this](https://github.com/gt-ospo/oss-software-preservation/blob/main/olive/README.md) tutorial to learn how to mount the remote file directory. 

## Setup our system

We will be using a Debian 12 image with OpenMPI, a compiler suite, and a SSH server preinstalled.

The path is `/caviar/21491a518580df55daa3a2de01d2374d4ecb67b39e605ff90be051d3304d0926`.

The user is `pwischangeme` and the password for both the user and root is `changeme`.
(You do not, in fact, have to change the password :D - this VM isn't meant to be secure.)

Make a new image with the following command:

```bash
qemu-img create -f qcow2 -F qcow2 -b /caviar/21491a518580df55daa3a2de01d2374d4ecb67b39e605ff90be051d3304d0926 debian-12-openmpi.qcow2
```

Now, run the image with the following command:

```bash
qemu-kvm -m 4096 -smp 4 -netdev user,id=net0,hostfwd=tcp::8022-:22 -device virtio-net-pci,netdev=net0 debian-12-openmpi.qcow2
```
- `-m 4096` specifies that the VM should have 4 GiB of RAM. Use more RAM if necessary and available.
- `-smp 4` specifies that the VM should have 4 virtual CPUs. Use more CPUs if necessary and available.
- `-netdev user,id=net0,hostfwd=tcp::8022-:22 -device virtio-net-pci,netdev=net0` sets up a network connection between the VM and the host. This allows us to SSH into the VM.
  - Additionally we forward port 22 on the VM to port 8022 on the host. This allows us to SSH into the VM using `ssh -p 8022 pwischangeme@localhost`.
- `debian-12-openmpi.qcow2` tells QEMU to use the image we just created.

## Compile and run a simple OpenMPI program

Start the VM.
Once it is running, verify you can SSH into it with `ssh -p 8022 pwischangeme@localhost`.

In this example, we will use `ringshift.c` from the `mpi-ringshift` directory.

Copy over the necessary source files from your computer to the VM.
```bash
scp -P 8022 -r /path/to/mpi-ringshift pwischangeme@localhost:/home/pwischangeme
```

Now, SSH into the VM and compile the program.
```bash
cd mpi-ringshift
mpicc -o ringshift ringshift.c
mpirun -n 4 ./ringshift
```

You should see something like the following output:
```
pwischangeme@debian:~/mpi-ringshift$ mpirun -n 8 ringshift
N = 8
--------------------------------------- Message Size: 2 bytes, Time: 6.668720e-06 s ---------------------------------------
Message Size: 2 bytes, Time: 6.668720e-06 s
6.668720e-06, --------------------------------------- Message Size: 4 bytes, Time: 6.304700e-07 s ---------------------------------------
Message Size: 4 bytes, Time: 6.304700e-07 s
6.304700e-07, --------------------------------------- Message Size: 8 bytes, Time: 5.281500e-07 s ---------------------------------------
Message Size: 8 bytes, Time: 5.281500e-07 s
5.281500e-07, --------------------------------------- Message Size: 16 bytes, Time: 4.314500e-07 s ---------------------------------------
Message Size: 16 bytes, Time: 4.314500e-07 s
4.314500e-07, --------------------------------------- Message Size: 32 bytes, Time: 9.411200e-07 s ---------------------------------------
Message Size: 32 bytes, Time: 9.411200e-07 s
9.411200e-07, --------------------------------------- Message Size: 64 bytes, Time: 1.076100e-06 s ---------------------------------------
Message Size: 64 bytes, Time: 1.076100e-06 s
1.076100e-06, --------------------------------------- Message Size: 128 bytes, Time: 1.702670e-06 s ---------------------------------------
Message Size: 128 bytes, Time: 1.702670e-06 s
1.702670e-06, --------------------------------------- Message Size: 256 bytes, Time: 1.505150e-06 s ---------------------------------------
Message Size: 256 bytes, Time: 1.505150e-06 s
1.505150e-06, --------------------------------------- Message Size: 512 bytes, Time: 1.316400e-06 s ---------------------------------------
Message Size: 512 bytes, Time: 1.316400e-06 s
1.316400e-06, --------------------------------------- Message Size: 1024 bytes, Time: 9.511700e-07 s ---------------------------------------
Message Size: 1024 bytes, Time: 9.511700e-07 s
9.511700e-07, --------------------------------------- Message Size: 2048 bytes, Time: 1.169490e-06 s ---------------------------------------
Message Size: 2048 bytes, Time: 1.169490e-06 s
1.169490e-06, --------------------------------------- Message Size: 4096 bytes, Time: 5.429110e-06 s ---------------------------------------
Message Size: 4096 bytes, Time: 5.429110e-06 s
5.429110e-06, --------------------------------------- Message Size: 8192 bytes, Time: 5.970880e-06 s ---------------------------------------
Message Size: 8192 bytes, Time: 5.970880e-06 s
5.970880e-06, --------------------------------------- Message Size: 16384 bytes, Time: 1.415683e-05 s ---------------------------------------
Message Size: 16384 bytes, Time: 1.415683e-05 s
1.415683e-05, --------------------------------------- Message Size: 32768 bytes, Time: 1.240145e-05 s ---------------------------------------
Message Size: 32768 bytes, Time: 1.240145e-05 s
1.240145e-05, --------------------------------------- Message Size: 65536 bytes, Time: 1.676668e-05 s ---------------------------------------
Message Size: 65536 bytes, Time: 1.676668e-05 s
1.676668e-05, --------------------------------------- Message Size: 131072 bytes, Time: 3.092813e-05 s ---------------------------------------
Message Size: 131072 bytes, Time: 3.092813e-05 s
3.092813e-05, --------------------------------------- Message Size: 262144 bytes, Time: 3.979025e-05 s ---------------------------------------
Message Size: 262144 bytes, Time: 3.979025e-05 s
3.979025e-05, --------------------------------------- Message Size: 524288 bytes, Time: 1.081836e-04 s ---------------------------------------
Message Size: 524288 bytes, Time: 1.081836e-04 s
1.081836e-04,
```

## Saving the VM Image

Now you have archived a piece of software that uses OpenMPI to a VM.
You can save the VM image for future use by just keeping a read-only copy.

Otherwise, you can upload it to a webserver so other people using Caviar can use the image on-demand as well.
To do this, follow step 2 of the [Import NXPK files to Caviar](./import-nxpk.md) tutorial.

## Conclusion

In this tutorial, we archived software that uses OpenMPI to a VM.
We compiled and ran a simple OpenMPI program to verify that the software works as expected.
You can now save the VM image for future use or upload it to a webserver for others to use.
