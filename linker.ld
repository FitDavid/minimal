MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

ENTRY(_start)
_sidata = LOADADDR(.data);

SECTIONS
{
	.text : ALIGN(4)
	{
		*(.isr_vector)
		*(.text)
		KEEP(*(.isr_vector))
	} >FLASH

	.data : ALIGN(4)
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	} >SRAM AT>FLASH

	.bss (NOLOAD) : ALIGN(4)
	{
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	} >SRAM

	.rodata : ALIGN(4)
	{
		*(.rodata)
	} >FLASH
}
