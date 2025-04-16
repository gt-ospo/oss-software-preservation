# Docker

## Disable `docker pull` command (used to import images from the Internet)

There may be some scripts in archived systems that try to automatically update Docker images.
To prevent this, you can either disable that script, or even disable `docker pull` altogether, which prevents most automated scripts from downloading new Docker images.

Downloading new Docker images is a necessary step for upgrading old Docker images to new ones.
By disabling this crucial step, you can help preserve the system in its original state.

TODO
