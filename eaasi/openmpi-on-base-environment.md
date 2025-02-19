# Install OpenMPI on Base Environment

If you can enable Internet access on your EaaSI instance, you can install OpenMPI directly from the Ubuntu package repositories.
If you cannot enable Internet access, you can download the installation files on a separate machine and then transfer them to your EaaSI instance.

## Install OpenMPI from Ubuntu Package Repositories

1. Open a new Environment in EaaSI where you want to install OpenMPI
2. Run `sudo apt-get update` to update the package lists and URLs
3. Run `sudo apt-get install -y openmpi-bin libopenmpi-dev build-essential` to install OpenMPI and gcc
4. Verify they're installed by running `mpirun --version`

## Download the Installation Files

1. Start an Ubuntu virtual machine (outside of EaaSI)
2. Open a terminal window (Ctrl+Alt+T)
3. Run the following command to download the OpenMPI installation files:
```bash
sudo apt-get update # update package lists and urls
apt-get install -y --print-urls openmpi-bin libopenmpi-dev build-essential | cut -d\' -f2 | grep http://
```
4. Download the files listed above (e.g. if all URLs are in file `urls.txt`, run `wget -i urls.txt`)
5. Transfer the downloaded files to your EaaSI instance:
  - Follow the [Upload Software Resource to EaaSI Environment](./upload-software-resource.md) tutorial. You will most likely need to upload it as multiple floppies, as the total file size is quite large at ~76 MiB.
6. Once all the `.deb` files are in your EaaSI Environment, install them with `sudo dpkg -i *.deb`
7. Verify they're installed by running `mpirun --version`
