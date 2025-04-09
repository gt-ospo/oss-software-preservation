# Disabling Autoupgrade - General Tips and Some Specific Guidance

Autoupgrade is a feature in some operating systems and programs that automatically updates to the latest version available.
For archival purposes, it is often necessary to disable autoupgrade to prevent unwanted changes to the system.
Some of these features can even run automatically (e.g. browsers), and require disabling the feature altogether.

## Debian - Unattended Upgrades

Unattended upgrades is a package that automatically installs updates from the same APT repository as the system.
It is not used to perform major upgrades (e.g. Debian 11 to 12).

To disable unattended upgrades, you can use the following command:
```bash
sudo apt remove unattended-upgrades
```

This will remove the package and prevent it from automatically installing updates.
