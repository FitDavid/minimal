typedef unsigned long uint32_t;
typedef unsigned char uint8_t;

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

#define STACK_SIZE 512*4
#define NTHREADS 2

struct stackframe_t
{
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t r14; // LR
	uint32_t retaddr;
	uint32_t xpsr;
};

struct thread_t
{
	uint32_t * sp;
};

struct threadtbl_t
{
	struct thread_t tbl[NTHREADS];
	uint32_t lock;
	uint32_t running;
};

int main();
void ledon();
void ledoff();
void SVC_Handler();
void SysTick_Handler();
void delay(volatile uint32_t);
