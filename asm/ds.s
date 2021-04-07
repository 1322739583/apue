#cpuid.s Sample program to extract the processor Vendor ID
.section .data 
output:
  .ascii "The processor Vendor ID is 'xxxxxxxxxxxx'\n"
.section .text
.globl main
main:


  movl %esp, %ebp #for correct debugging
  movl $0,%eax
  cpuid 
  movl $output,%edi
  movl %ebx, 28(%edi)
  movl %edx, 32(%edi)
movl %ecx, 36(%edi)

movl $100, %ebx
movl %ebx, %ds
movl disp(%eax,2)

mov $4, %ax
add $1, %eax
add $-1, %eax
movl $1, %ebx
movl $output, %ecx
movl $42,%edx
int $0x80
movl $1, %eax
movl $0, %ebx
int $0x80