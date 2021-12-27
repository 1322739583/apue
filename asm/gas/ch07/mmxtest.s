.section .bss
    
.section .data
value1:
    .int 1,-1
value2:
    .byte 0x10,0x05,0xff,0x32,0x47,0xe4,0x00,0x01
.section .text
.globl _start
_start:
    movq value1,%mm0#不同位数的数值会从64位到8位不断对半拆分
    movq value2,%mm1

    int $0x80