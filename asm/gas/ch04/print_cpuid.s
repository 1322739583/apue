#打印CPUID
.section .data
#初始化代码
output:
    #12位CPUID
    .ascii "The processor Venfor ID is 'xxxxxxxxxxxx'\n"
.section .bss
#未初始化代码
.section .text
.globl _start
_start:
    movl %esp, %ebp #for correct debugging#主代码
    movl $0,%eax#this is an instruction
    cpuid#move the value output to edi
    movl $output,%edi
    movl %ebx,28(%edi)
    movl %edx,32(%edi)
    movl %ecx,36(%edi)
    movl $4,%eaxi
    movl $1,%ebx
    movl $output,%ecx
    movl $42,%edx
    int $0x80
    movl $1,%eax
    movl $0,%ebx
    int $0x80
