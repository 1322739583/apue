#测试文件大小
#内部提供的伪指令都是以.开头的
.section .text
.globl _start
_start:
    movl $1,%eax
    movl $0,%ebx
    int $0x80