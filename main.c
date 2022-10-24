typedef unsigned long uint32_t;

#define FLASH_BASE  0x08000000
#define SRAM_BASE   0x20000000
#define PERIPH_BASE 0x40000000

#define SRAM_SIZE 128*1024
#define SRAM_END (SRAM_BASE + SRAM_SIZE)

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)

#define RCC_AHB1ENR ((uint32_t *)(RCC_BASE + 0x30UL))
#define GPIOA_MODER ((uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR ((uint32_t *)(GPIOA_BASE + 0x14))

int main();
void SVC_Handler();
void SysTick_Handler();
void delay(volatile uint32_t);

uint32_t *vtable[100] __attribute__((section(".isr_vector"))) =
{
		(uint32_t *)SRAM_END, // MSP
		(uint32_t *)main,
		[11] = (uint32_t *)SVC_Handler,
		[15] = (uint32_t *)SysTick_Handler
};


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


void SysTick_Handler()
{

}

void SVC_Handler()
{

}

void delay(volatile uint32_t count)
{
		while(count--);
}
