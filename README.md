This is a minimal example of how to do task swithing on a Cortex-M3 or Cortex-M4. Tested on Nucleo-F446RE evaluation board. It is interesting for students of computer science who want to know what the core of a (real time) operating system does, but doesn't want to go through many 1000s of lines of code deep down in the kernel.

# Installation
## Prerequisites
On linux, you'll need some kind of driver to upload to the evaluation board.
In case of Nucleo-F446RE, you'll need to install STM32CubeIDE and STM32Cube Programmer which include the necessary drivers.
You'll also need a cross-compiler. Install gcc-arm-none-eabi. Once this is done, enter this on the command line:

## Compilation
1. Make a directory for the object files `mkdir obj`
2. Compile it with `make`

## Upload
3. Upload obj/minimal.elf with STM32Cube Programmer to the MCU 
