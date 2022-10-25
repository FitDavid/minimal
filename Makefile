
CFLAGS = -Wall -mcpu=cortex-m4 -mthumb -c 
LFLAGS = -T linker.ld 

link: isr main
	arm-none-eabi-ld $(LFLAGS) -o obj/minimal.elf obj/main.o obj/isr.o

isr: isr.asm
	arm-none-eabi-as $(CFLAGS) -o 'obj/isr.o' isr.asm

main: main.c main.h
	arm-none-eabi-gcc $(CFLAGS) -nostartfiles -o 'obj/main.o' main.c

asm: main.c
	arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mthumb -S main.c

clean:
	rm obj/* *.s a.out
