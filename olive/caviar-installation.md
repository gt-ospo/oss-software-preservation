# Caviar Installation Tutorial

## System Requirements For Caviar
- Linux based host OS (within past 5 years)
  - A good choice/example is Ubuntu 24.04.
- QEMU (KVM is more performant, but `qemu-system-x86_64` is ok as well)
  - [QEMU's download webpage](https://www.qemu.org/download/)

## Run and Explore Debian 12 using Caviar

Note: In order to distinguish our fork, we have renamed VMNetX to Caviar.

1. The first step is to download Caviar. 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=5) Go to https://github.com/gt-ospo/vmnetx/actions/workflows/go.yml 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=19) Click the first green checkmark link
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=24) Click the `build-caviar` artifact to download it
2. Next, preform the following setup:
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=38) Unzip the downloaded file (`build-caviar.zip`) - it should contain an executable called `caviar` for your machine. 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=67) Ensure that the `caviar` binary you downloaded from the previous step is executable with the `chmod +x caviar` command. 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=85) Make a `/caviar` directory with `sudo mkdir /caviar` 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=98) Ensure that the new `/caviar` directory has both read and write permissions by running `sudo chmod ugo+rwX /caviar`
3. In this step, we will Run Caviar - it will mount a [FUSE](./glossary.md) filesystem
  - `cd` to the directory containing your unzipped `caviar` download from step 2. 
  - [Watch Step](https://youtu.be/uRjmTm59spk&t=112) Run the binary with `./caviar -mount /caviar`. This will mount the Caviar virtual filesystem to `/caviar`; this command should keep running in the terminal. 
  - Now, remote disk images will be accessible in your local `/caviar` directory. 
    - The remote disk images are currently hosted at https://bulletin.nyiyui.ca/2025/03/caviar-store/


Our setup is done - now we can make a new VM and run it. In this tutorial we will be making a Debian 12 virtual machine.

1. [Watch Step](https://youtu.be/uRjmTm59spk&t=132) Create a directory for your VM files - `mkdir run-debian-12 && cd run-debian-12`
2. [Watch Step](https://youtu.be/uRjmTm59spk&t=150) Create your VM image - `qemu-img create -f qcow2 -F qcow2 -b /caviar/6b7a1d0cfeaf2d406d05bf174885b8d2edd7866b733a9aaea79fbddf0466741b debian-12.qcow2`
  - Explanation of argument options
    - `qemu-img create` QEMU's utility program for making VM images
    - `-f qcow2 -F qcow2` specify we are using [QCOW2 format](https://www.linux-kvm.org/page/Qcow2) for our VM images - this is required by Caviar
    - `-b /caviar/...` specify the "backing file" of the new VM image we are making; this makes sure we can make edits to our VM disk (as naturally happens when you run an OS), while keeping the disk accessed on-demand
      - `/caviar/...` is the remote VM image we mounted in our setup step 3 - the file does not actually exist on your disk, but is read on-demand as necessary
    - `debian-12.qcow2` the filename of our new VM image

We have created a new VM image based on Debian 12. Let's check the file size. Now, we can run it:

3. [Watch Step](https://youtu.be/uRjmTm59spk&t=158) qemu-kvm -m 4096 debian-12.qcow2
This runs the VM with 4 GiB of RAM. The VM will run while only part of the full image is downloaded.
