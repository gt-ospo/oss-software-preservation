# Glossary

- Olive
  - A collection of VM images and metadata incl. e.g. Windows 95, etc
  - Also hosts a special web service which runs VMs on the cloud (the Windows and Android VMNetX clients use this)
- VMNetX (app)
  - A GUI app that can stream a VM (like a YouTube video; download parts of the disk as required)
- VMNetFS (`vmnetfs`)
  - [FUSE](https://www.kernel.org/doc/html/next/filesystems/fuse.html) filesystem used for VMNetX for disk streaming
  - Like OneDrive, files are downloaded on demand; if of a 20GiB disk, only e.g. 3GiB is used for startup, we save 17GiB of network bandwidth
