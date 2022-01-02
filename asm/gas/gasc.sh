# as -32  -gstabs -o $1.o $1.s
# ld -m elf_i386  -o a.out  $1.o
# gdb -q a.out                                                          
as -32 -gstabs -o $1.o $1.s 
gcc -m32 -g -o  a.out $1.s -fno-pie -no-pie
gdb -q a.out -x ~/.gdbinitc