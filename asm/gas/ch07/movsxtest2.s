.section .bss
    
.section .data
    
.section .text
.globl _start
_start:
    movw $79,%cx
    xor %ebx,%ebx
    movw %cx,%bx
    movsx %cx,%eax
    
    int $0x80