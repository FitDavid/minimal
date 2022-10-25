.global SVC_Handler
.global SysTick_Handler
.arch armv7e-m
.syntax unified
.thumb

SVC_Handler:
mov pc, lr

SysTick_Handler:
mov pc, lr
