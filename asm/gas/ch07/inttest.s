.section .data
data:
    .int -45
.section .bss
    
.section .text
.globl _start
_start:
    movl $-345,%ecx
    #可以使用print $dx而不是print $edx就可以正确显示了
    movw $0xffb1,%dx#写成0xffffffb1,%edx就会正确显示结果-79
    movl data,%ebx
    movl $1,%eax
    int $0x80