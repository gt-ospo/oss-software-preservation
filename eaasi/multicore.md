# Configure the number of CPU cores of an Environment

These instructions are only for Environments that use QEMU as the Emulator.

1. Navigate to the Environment's page
2. Enter Edit Mode by clicking the switch located between "Review Mode" and "Edit Mode" ([screenshot of switch](./environment-editMode.png))
3. If `-smp <n>` (where `<n>` is any positive integer) exists, replace it with `-smp <cores>` (`<cores>` is the number of cores) (e.g. `-smp 8` for 8 CPU cores). Else, add `-smp <cores>`.
4. Save the Environment ([screenshot](./environment-edit-save.png))
  - This will create a local (only for you) copy of the Environment.
  - Note that the "CPU" count will not be accurate in the Emulation Project view (but it will be dual-core).
