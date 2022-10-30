#include "main.h"

uint32_t *vtable[100] __attribute__((section(".isr_vector"))) =
{
		[0] = (uint32_t *)SRAM_END, // MSP
		[1] = (uint32_t *)main,
		[11] = (uint32_t *)SVC_Handler,
		[15] = (uint32_t *)SysTick_Handler
};

uint8_t minsp1[STACK_SIZE] __attribute__ ((aligned(8))); // pointer to minimal sp
uint8_t minsp2[STACK_SIZE] __attribute__ ((aligned(8))); // aligned to 8 byte boundary

struct threadtbl_t threads;

int main()
{
		struct stackframe_t * sp1 = (struct stackframe_t*)(minsp1 + STACK_SIZE - sizeof(struct stackframe_t));
		struct stackframe_t  * sp2 = (struct stackframe_t*)(minsp2 + STACK_SIZE - sizeof(struct stackframe_t));
		sp1->retaddr = (uint32_t*)ledon; //
		sp1->xpsr = 1ul << 24ul;
		sp2->retaddr = (uint32_t*)ledoff; //
		sp2->xpsr = 1ul << 24ul;
		threads.tbl[0].sp = (uint32_t*) sp1;
		threads.tbl[1].sp = (uint32_t*) sp2;
		*RCC_AHB1ENR = 0x1;
		*GPIOA_MODER |= 0x400;
		asm("svc 0 \n\t");
		while(1)
		{
				*GPIOA_ODR = 0x20;
				delay(2000000);
				*GPIOA_ODR = 0x0;
				delay(2000000);
		}
}

void ledon()
{
		while(1)
		{
				//*GPIOA_ODR = 0x20;
		}
}

void ledoff()
{
		while(1)
		{
				*GPIOA_ODR = 0x0;
		}
}

void delay(volatile uint32_t count)
{
		while(count--);
}

