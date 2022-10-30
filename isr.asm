	.cpu cortex-m4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"isr.c"
	.text
	.align	1
	.global	SVC_Handler
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	SVC_Handler, %function
SVC_Handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr r0, Lthreads
	ldr r1, [r0]
	msr psp, r1
	ldr r2, Llr
	mov lr, r2
	bx	lr
Lthreads:
	.word threads
Llr:
	.word 0xFFFFFFFD
	.size	SVC_Handler, .-SVC_Handler
