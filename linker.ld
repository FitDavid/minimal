MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K /* for stm32f446 */
}

ENTRY(_start) /* entry point of program */

SECTIONS
{
	.text : ALIGN(4)
	{
		/* keep it even if not referenced */
		KEEP(*(.isr_vector)) 
		*(.text) /* .text section from all files */
		*(.text*) /* every .text section from all files */
	} >FLASH

	_sidata = LOADADDR(.data); /* load address and virtual address will be different */
	.data : ALIGN(4)
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} >SRAM AT>FLASH

	.bss : ALIGN(4)
	{
		_sbss = .;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	} >SRAM

	.rodata : ALIGN(4)
	{
		*(.rodata)
	} >FLASH
}
