.global SVC_Handler
.global SysTick_Handler
.arch armv7e-m
.syntax unified
.thumb
.equ RETADDR, 6*4

SVC_Handler:
	bx lr

SysTick_Handler:
	bx lr
