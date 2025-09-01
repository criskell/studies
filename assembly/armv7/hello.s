.global _start

.section .text
_start:
	mov r0, #42
	mov r7, #1
	swi 0
