.section .data
 output:
    .asciz "This is section %d\n"   
.section .bss
    
.section .text
.globl main
main:
    pushl $1
    pushl $output
    call printf
    add $8,%esp #$1占用4个字节，$output也占用4个字节吗？
    call overhere
    pushl $3
    pushl $output
    call printf
    add $8,%esp
    pushl $0
    call exit
overhere:
    pushl %ebp
    movl %esp,%ebp
    pushl $2
    pushl $output
    call printf
    add $8,%esp
    movl %ebp,%esp
    popl %ebp
    ret
