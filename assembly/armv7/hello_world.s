.section .data
message: .ascii "Hello, World!\n"
length = . - message

.section .text
.global _start
_start:
	@ write (1, msg, len)
	mov r7, #4 @ número da syscall sys_write
	mov r0, #1 @ file descriptor (stdout)
	ldr r1, =message @ ponteiro para a string
	mov r2, #length
	swi 0

	mov r7, #1
	mov r0, #0
	swi 0
	
