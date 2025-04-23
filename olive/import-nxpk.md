# Import Olive Executable Archive VMs (NXPK files) to Caviar

## Overview

This guide explains how to import Olive Executable Archive VMs (NXPK files) to Caviar.

There are three main steps:
1. Convert the NXPK file to a Caviar-compatible format
2. Upload the converted files to a webserver
3. Run the `caviar-vmnetx` command to run the VM hosted on the webserver

## Prerequisites

- Linux shell environment with QEMU emulator
- `caviar` and `caviar-convert`, `caviar-vmnetx` installed
  - To install these programs, follow step 1 of the [Run and Explore Debian 12 using Caviar](./caviar-installation.md) tutorial
- NXPK file to import
- webserver to host the converted files
  - any mainstream webserver that can host files (e.g. Apache, nginx, caddy) will work (must support HTTP Range requests)

## Steps

1. Convert the NXPK file to a Caviar-compatible format. We will store the output files in a temporary directory, made using `mktemp --directory`.

`caviar-convert -nxpk <nxpk-file> -out $(mktemp --directory)`

Example using [Ubuntu 12.04](https://bulletin.nyiyui.ca/2025/03/ubuntu12.04.nxpk):
`caviar-convert -nxpk ubuntu12.04.nxpk -out $(mktemp --directory)`
```
2025/03/19 01:22:38 package: vmnetx.VMNetXImage{Name:"Demo Ubuntu 12.04", Domain:vmnetx.VMNetXFilePath{Path:"domain.xml"}, Disk:vmnetx.VMNetXFilePath{Path:"disk.img"}, Memory:vmnetx.VMNetXFilePath{Path:"memory.img"}}
2025/03/19 01:22:38 extracting disk.img into output directory /tmp/tmp.swHtNei2oI
2025/03/19 01:22:38 extracting memory.img into output directory /tmp/tmp.swHtNei2oI
2025/03/19 01:22:41 1. Copy the extracted files in /tmp/tmp.swHtNei2oI to a webserver, and configure caviar to use that webserver
2025/03/19 01:22:41 1.1. The files must be accessible as https://<webserver>/<filename>
2025/03/19 01:22:41 1.2. When running caviar, use the --urls flag to point to the webserver, e.g. --urls https://<webserver>/<filename> (multiple URLs are separated by spaces)
2025/03/19 01:22:41 2. Run using caviar-vmnetx to run the VM: caviar-vmnetx --package /caviar/c56617b6819182c4f1320e2d2a14b9cc7c172702d13dc5f019bfa0c6adb99adf
```

2. Upload the converted files to a webserver. If you do not have a webserver setup, you can follow [./webserver.md](this) tutorial. 

Example:
`scp -r /tmp/tmp.swHtNei2oI/* user@webserver:/path/to/webserver`

3. In this step, we will run the VM. Make sure `caviar` is running with `--urls` including the webserver you uploaded the files to. 

First, run `stat /caviar/<package-file>` to make sure the file you uploaded exists.

Example:
`stat /caviar/c56617b6819182c4f1320e2d2a14b9cc7c172702d13dc5f019bfa0c6adb99adf`
```
  File: /caviar/c56617b6819182c4f1320e2d2a14b9cc7c172702d13dc5f019bfa0c6adb99adf
  Size: 349             Blocks: 8          IO Block: 4096   regular file
Device: 0,126   Inode: 9223372036854776650  Links: 0
Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 1969-12-31 19:00:00.000000000 -0500
Modify: 1969-12-31 19:00:00.000000000 -0500
Change: 1969-12-31 19:00:00.000000000 -0500
 Birth: -
```

Next, run the VM using `caviar-vmnetx`: `caviar-vmnetx --package /caviar/<package-file>`

Example:
`caviar-vmnetx --package /caviar/c56617b6819182c4f1320e2d2a14b9cc7c172702d13dc5f019bfa0c6adb99adf`
```
2025/03/19 01:24:11 Package Name: Demo Ubuntu 12.04
2025/03/19 01:24:11 Domain Path: /caviar/68ad6c25482675cbec83b93090ad181483f2dd6ceb4cc3300f97242beb34ddbf
2025/03/19 01:24:11 Disk Path: /caviar/41927c0139cf618c83dd1e8706b0b9e93faf1be39edb8f54c6b1eefae43a92bf
2025/03/19 01:24:11 Memory Path: /caviar/459652a0a81ad48bf178c2f9efb64a9a9f997aea0d336a9bb1d48551fb07699a
2025/03/19 01:24:11 Temporary Directory: /tmp/caviar-vmnetx-Demo Ubuntu 12.04809543492
2025/03/19 01:24:12 Read-write Disk Path (ephemeral): /tmp/caviar-vmnetx-Demo Ubuntu 12.04809543492/disk.qcow2
2025/03/19 01:24:12 Libvirt Version: 10009000
2025/03/19 01:24:14 Defined domain: machine (5efaea07-88c7-4923-bfa2-8498b3a35a8f)
2025/03/19 01:24:14 Open virt-manager or run 'virsh list' to see the VM
2025/03/19 01:24:14 The name of the virtual machine (domain) is machine
2025/03/19 01:24:14 Opening VM console...
```

Once you see `Opening VM console...`, you should get a new window with the VM screen.
[Screenrecord on YouTube](https://youtu.be/PGK8W_vv3yE)
