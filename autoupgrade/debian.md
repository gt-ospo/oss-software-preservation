# Debian - Unattended Upgrades

`unattended-upgrades` is a package that automatically installs updates from the same APT repository as the system.
It is not used to perform major upgrades (e.g. Debian 11 to 12).

To disable unattended upgrades, you can use the following command:
```bash
sudo apt remove unattended-upgrades
```

This will remove the package and prevent it from automatically installing updates.

*Alternative to above.*
If the above method does not work (e.g. causes other packages to be removed as well), try the following:
Edit the `/etc/apt/apt.conf.d/20auto-upgrades` file (this file configures the unattended-upgrades package) and set the following options:
```bash
APT::Periodic::Update-Package-Lists "0";
APT::Periodic::Unattended-Upgrade "0";
```
The first line disables updating package lists (usually done by `apt update`).
The second line disables unattended upgrades (usually done by `apt upgrade`).

Make sure to check the changes have been applied by running the following:
```bash
apt-config dump APT::Periodic::Update-Package-Lists
apt-config dump APT::Periodic::Unattended-Upgrade
```
Running the two commands should return the following:
```
APT::Periodic::Update-Package-Lists "0";
APT::Periodic::Unattended-Upgrade "0";
```
