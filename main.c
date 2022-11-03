#include "main.h"

// Vector table. Will be at address 0x0800_0000
uint32_t *vtable[100] __attribute__((section(".isr_vector"))) =
{
		[0] = (uint32_t *)SRAM_END, // MSP
		[1] = (uint32_t *)_start,
		[11] = (uint32_t *)SVC_Handler,
		[15] = (uint32_t *)SysTick_Handler
};

// There will be 2 threads. Stack is allocated for them here.
uint8_t minsp1[STACK_SIZE] __attribute__ ((aligned(8))); // pointer to minimal sp
uint8_t minsp2[STACK_SIZE] __attribute__ ((aligned(8))); // aligned to 8 byte boundary (padding)

// The threadtable. More accurate name than processtable, because they share memory.
struct threadtbl_t threads;

int main()
{
		// will put a stackframe on top of the stackspace. 
		//Bottom of stackspace marked by minsp. Top is minsp + STACK_SIZE
		struct stackframe_t * sp1 = (struct stackframe_t*)(minsp1 + STACK_SIZE - sizeof(struct stackframe_t));
		struct stackframe_t  * sp2 = (struct stackframe_t*)(minsp2 + STACK_SIZE - sizeof(struct stackframe_t));
		// stackframes are set up. 
		sp1->retaddr = (uint32_t*)ledon; //
		sp1->xpsr = 1ul << 24ul;
		sp2->retaddr = (uint32_t*)ledoff; //
		sp2->xpsr = 1ul << 24ul;
		threads.tbl[0].sp = (uint32_t*) sp1;
		threads.tbl[1].sp = (uint32_t*) sp2;
		*RCC_AHB1ENR = 0x1;
		*GPIOA_MODER |= 0x400;
		asm("svc 0 \n\t");
}

// This will be thread 0 
void ledon()
{
		while(1)
		{
				*GPIOA_ODR = 0x20;
		}
}

// This will be thread 1
void ledoff()
{
		while(1)
		{
				*GPIOA_ODR = 0x0;
		}
}

// used for testing
void delay(volatile uint32_t count)
{
		while(count--);
}

/*-----------Init routine------------*/

	/* Copies values of initialized globals from flash to SRAM (.data section).  
	Zeros out uninitialized variables (.bss section). */

/*----linker defined variables----*/
extern uint32_t _sidata, _sdata, _edata;
extern uint32_t _sbss, _ebss;


void _init_data(uint32_t* sidata, uint32_t* sdata, uint32_t* edata)
{
		while(sdata < edata)
		{
				*sdata++ = *sidata++;
		}
}

void _init_bss(uint32_t* sbss, uint32_t* ebss)
{
		while(sbss < ebss)
		{
				*sbss++ = 0;
		}
}

// entry point
void _start()
{
		_init_data(&_sidata, &_sdata, &_edata);
		_init_bss(&_sbss, &_ebss);
		main();
}
