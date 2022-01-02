.section .data
output:
    .asciz "The result is %d\n"
.section .bss

.section .text
.globl main
main:
    movl $-1590876934,%ebx
    movl $-1259230143,%eax
    addl %eax,%ebx
    jo over
    pushl %ebx
    push $output
    call printf
    addl $8,%esp#书上并没有用addl
    pushl $0
    call exit
over:
    pushl $0
    pushl $output
    call printf
    addl $8,%esp
    pushl $0
    call exit
