.section .data
    value:
        .int 3 ,5 ,6
.section .bss
    
.section .text
.globl _start
_start:
    #这里的value表示第一个值3
    movl value,%ecx
    movl $1,%eax
    movl $0,%ebx
    int $0x80