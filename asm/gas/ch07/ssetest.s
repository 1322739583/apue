.section .bss
    
.section .data
value1:
    .int 1,-1,0,135246
value2:
    .quad 1,-1
.section .text
.globl _start
_start:
    movdqu value1,%xmm0
    movdqu value2,%xmm1 #打印的两个寄存器的结果好像是不合理的，书上的也是
    int $0x80