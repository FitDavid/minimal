This is a minimal example of how to do task swithing on a Cortex-M3 or Cortex-M4. Tested on Nucleo-F446RE evaluation board. Step 0 for a (real time) operating system.

# Installation
## Prerequisites
On linux, you'll need some kind of driver to upload to the evaluation board.
In case of Nucleo-F446RE, you'll need to install STM32CubeIDE and STM32Cube Programmer which include the necessary drivers.
You'll also need a cross-compiler e.g. gcc-arm-none-eabi. Once this is done, enter this on the command line:

## Compilation
1. Make a directory for the object files `mkdir obj`
2. Compile it with `make`

## Upload
3. Upload obj/minimal.elf with STM32Cube Programmer to the MCU 
