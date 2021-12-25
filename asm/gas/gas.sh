as -32  -gstabs -o $1.o $1.s
ld -m elf_i386  -o a.out  $1.o
gdb -q a.out                                                          
#as -32 -gstabs -o print_cpuid_c.o print_cpuid_c.s 
#gcc -m32 -o -g print_cpuid_c print_cpuid_c.s -fno-pie -no-pie  