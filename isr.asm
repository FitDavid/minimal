.global SysTick_Handler
.global SVC_Handler
.arch armv7e-m
.syntax unified
.thumb
.thumb_func
.fpu softvfp
.type SVC_Handler, %function
.global HardFault_Handler
.global BusFault_Handler
.global UsageFault_Handler
.arch armv7e-m
.syntax unified
.thumb
.equ GPIO_ODR, 0x40020014


SysTick_Handler:
	bx lr
BusFault_Handler:
HardFault_Handler:
UsageFault_Handler:
SVC_Handler:
	adr r0, .Lthreads
	msr psp,r0
	mov r1, 0xFFFD
	movt r1, 0xFFFF
	msr control, r1
	bx lr
.Lthreads:
	.word threads
