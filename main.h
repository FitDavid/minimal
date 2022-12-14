typedef unsigned long uint32_t;
typedef unsigned char uint8_t;

#define FLASH_BASE  0x08000000ul
#define SRAM_BASE   0x20000000ul
#define PERIPH_BASE 0x40000000ul

#define SRAM_SIZE 128ul*1024ul
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
#define GPIOA_MODER ((uint32_t *)(GPIOA_BASE + 0x00ul))
#define GPIOA_ODR ((uint32_t *)(GPIOA_BASE + 0x14ul))

#define STACK_SIZE 512*4 // bytes
#define NTHREADS 2

struct stackframe_t
{
	uint32_t r0; // 0
	uint32_t r1; // 1
	uint32_t r2; // 2
	uint32_t r3; // 3
	uint32_t r12; // 4
	uint32_t r14; // LR, 5
	uint32_t* retaddr; // 6 return address
	uint32_t xpsr; // program status word
};

// this is for later use
struct thread_t
{
	uint32_t * sp;
};

// Type for the threadtable
struct threadtbl_t
{
	struct thread_t tbl[NTHREADS];
	uint32_t running; // holds the index of the currently running process
	uint32_t lock; // for future use
};

int main();
void ledon();
void ledoff();
extern void SVC_Handler();
extern void SysTick_Handler();
void delay(volatile uint32_t);
void _start();
