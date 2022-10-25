#include "main.h"

uint32_t *vtable[100] __attribute__((section(".isr_vector"))) =
{
		(uint32_t *)SRAM_END, // MSP
		(uint32_t *)main,
		[11] = (uint32_t *)SVC_Handler,
		[15] = (uint32_t *)SysTick_Handler
};

uint8_t minsp1[STACK_SIZE] __attribute__ ((aligned(8))); // pointer to minimal sp
uint8_t minsp2[STACK_SIZE] __attribute__ ((aligned(8))); // aligned to 8 byte boundary

uint32_t running = 0; // index of currently running thread

int main()
{
		*RCC_AHB1ENR = 0x1;
		*GPIOA_MODER |= 0x400;

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

	}
}

void ledoff()
{
	while(1)
	{

	}
}

void delay(volatile uint32_t count)
{
		while(count--);
}


void SysTick_Handler()
{

}

void SVC_Handler()
{

}


