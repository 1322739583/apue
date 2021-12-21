nasm $1.asm -o $1.bin -l $1.lst
dd if=$1.bin of=asm.img bs=512 count=1 conv=notrunc
bochs -q  -f ~/.bochsrc -rc debug.cfg  
