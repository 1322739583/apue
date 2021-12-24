.section .data
output:
    .asciz "The largest value is %d\n"
values:
    .int 105,235,61,315,134,221,53,145,117,5
.section .bss
    
.section .text
.globl _start
_start:
    nop 
    movl values, %ebx
    nop
    int $0x80


