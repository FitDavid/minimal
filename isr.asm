.global SysTick_Handler
.global HardFault_Handler
.global BusFault_Handler
.global UsageFault_Handler
.global SVCall
.arch armv7e-m
.syntax unified
.thumb
.equ RETADDR, 6*4
.equ GPIO_ODR, 0x40020014

SVCall:
	svc 0
	bx lr

SysTick_Handler:
	bx lr
BusFault_Handler:
HardFault_Handler:
UsageFault_Handler:
SVC_Handler:
	mov r0, 0x14
	movt r0,0x4002
	mov r1, 0x20
	str r1, [r0]
	bx lr
