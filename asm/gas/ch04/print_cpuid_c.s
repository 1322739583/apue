#打印CPUID
.section .data
#初始化代码
output:
    #12位CPUID
    .asciz "The processor Venfor ID is '%s'\n"
.section .bss
#未初始化代码
    .lcomm buffer,12
.section .text
.globl main
main:
    nop
    movl $0,%eax#this is an instruction
    cpuid#move the value output to edi
    movl $buffer,%edi
    movl %ebx,(%edi)
    movl %edx,4(%edi)
    movl %ecx,8(%edi)
    pushl $buffer
    pushl $output
    call printf
    addl $8,%esp
    pushl $0
    call exit
