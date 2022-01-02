.section .data
data1:
    .int 222
data2:
    .int 333
output:
    .asciz "This is the result %d\n"
.section .bss

.section .text
.globl main
main:
    movl data1,%eax
    movl data2,%ebx
    adcl %eax,%ebx
    pushl %eax
    pushl %ebx
    pushl $output
    call printf
    addl $8,%esp
    pushl $0
    call exit