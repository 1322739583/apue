.section .bss
    
.section .data
    
.section .text
.globl _start
_start:
    movw $-79,%cx#声明一个负数到cx
    movl $0,%ebx
    movw %cx,%bx#ebx高16位为0
    movsx %cx,%eax#因为eax高位不是1，所以会解析成正数
    #movl $1,%eax
    #movl $0,%ebx
    int $0x80