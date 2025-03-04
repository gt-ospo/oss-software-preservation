# Other Software Preservation Platforms
This file contains a comprehensive list of all other currently known tools for software preservation, excluding EaaSi and Olive.  

## Table of Contents
- [KEEP Emulation Framework](#KEEP-Emulation-Framework)
- [Dioscuri Emulator​](#Dioscuri-Emulator​)

## KEEP Emulation Framework

Overview: 
- Last release version: April 2012, no longer actively maintained​
- Main purpose was to provide on-demand emulation services through an automated framework.


Architecture: 
- Java-based​
- Multiple emulators (such as `QEMU`, `DOSBox`, and `MAME`)​
- Emulation Registry: A metadata database that maps digital file formats to the necessary execution environment.​
- Web-based UI​
- Host OS: `Windows`, `Linux`, `macOS` (requires JRE)​
- Emulated Platforms: `x86` (`DOS`/`Windows`), `Commodore 64/128`, `Amiga`, `Amstrad CPC`, `BBC Micro`, `Thomson`.


Unique Features: 
- Fully automated selection: Identifies file format and launches the appropriate emulator + OS.​
- New emulator modules can be integrated / added in. ​
- When a digital object (such as a disk image, software executable, or document) is uploaded or linked from a digital archive, KEEP analyzes its format.​
- Allows users to open legacy software from digital library catalogs by automatically choosing the right emulator and OS based on metadata.


Links: 
- [User Guide](https://emuframework.sourceforge.net/docs/System-User-Guide_2.0.pdf​)
- [Website + Download](https://emuframework.sourceforge.net/users.html#:~:text=from%20small%20departmental%20servers%20to,vast%20silos)


## Dioscuri Emulator​
