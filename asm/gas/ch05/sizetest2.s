#测试文件大小
#内部提供的伪指令都是以.开头的
.section .bss
    .lcomm buffer,10000#这个名字是自己随便取的
.section .text
.globl _start
_start:
    movl $1,%eax
    movl $0,%ebx
    int $0x80