# Disabling Autoupgrade - General Tips and Some Specific Guidance

Autoupgrade is a feature in some operating systems and programs that automatically updates to the latest version available.
For archival purposes, it is often necessary to disable autoupgrade to prevent unwanted changes to the system.
Some of these features can even run automatically (e.g. browsers), and require disabling the feature altogether.

Example scenario:
1. You have a VM image that contains an old version of Firefox, to see how web pages looked in the past.
2. Once you connect Firefox to the Internet, it automatically updates to the latest version, thereby destroying the archival value of the image.

## Contents

- [Debian](./debian.md)
  - Disable autoupgrade on Debian systems
- [Ubuntu](./ubuntu.md)
  - Disable autoupgrade on Ubuntu systems
  - Disable GUI prompts for updates
- [Docker](./docker.md)
  - Prevent Docker images from being downloaded from the Internet

TODO: mark certain packages to not upgrade
