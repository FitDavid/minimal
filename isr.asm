.global SVC_Handler
.global SysTick_Handler
.arch armv7e-m
.syntax unified
.thumb
.equ RETADDR, 6*4

SysTick_Handler:
	ldr	pc, [sp , #RETADDR]
SVC_Handler:
	ldr	pc, [sp , #RETADDR]

