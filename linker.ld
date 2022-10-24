
MEMORY
{
		FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
		SRAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

ENTRY(main)

SECTIONS
{
		.text : ALIGN(4)
		{
				*(.isr_vector)
				*(.text)
				KEEP(*(.isr_vector))
		} >FLASH

		.data :
		{
				*(.data)
		} >SRAM
}
