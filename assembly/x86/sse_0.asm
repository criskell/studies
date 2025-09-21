global _start

section .data
vec1: db 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0
vec2: db 1, 2, 3, 4, 5, 9, 8, 7, 6, 0, 0, 0, 0, 0, 0, 0
result: times 16 db 0

section .text
_start:
  movdqu xmm0, [vec1]
  movdqu xmm1, [vec2]

  pcmpeqb xmm0, xmm1

  movdqu [result], xmm0

  mov rax, 60
  xor rdi, rdi
  syscall