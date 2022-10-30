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
SVC_Handler: @ Enables SysTick and jumps to first task
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	mov r0, #0xFFFF
	movt r0, #0xFFFF
	mov r1, #0xE014
	movt r1, #0xE000
	str r0, [r1] @ SYST_RVR = 0xFFFF_FFFF (SysTick Reload Value Register)
	mov r0, #3
	mov r1, #0xE010
	movt r1, #0xE000
	str r0, [r1] @ SYST_CSR = 0x3 (SysTick Control and Status Register)
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

	.global	SysTick_Handler
	.arch armv7e-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	SysTick_Handler, %function
SysTick_Handler:
	ldr r0, Lthreads
	ldr r1, [r0, #8] @ r1 = threads.running
	add r1, #1
	ands r1, r1, #1
	ite eq
	ldreq r2, [r0]
	ldrne r2, [r0, #4]
	msr psp, r2
	bx lr
	.size SysTick_Handler, .-SysTick_Handler
