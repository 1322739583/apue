start:
mov ax, 65535 ;商保存在ax
xor dx,dx  ;相对于mov dx,0  异或相同的数，结果为0
mov bx,10
div bx ;余数保存在dx

add dl,0x30 ;十进制48，在ascii中0的位置是48，加上0x30就是转化成ascii编码

mov cx,0
mov ds,cx
;将余数保存到我们对应的5个buffer单位中
mov [0x7c00+buffer],dl

xor dx,dx
div bx
add dl,0x30
mov [0x7c00+buffer+1],dl

xor dx,dx
div bx
add dl,0x30
mov [0x7c00+buffer+2],dl

xor dx,dx
div bx
add dl,0x30
mov [0x7c00+buffer+3],dl

xor dx,dx
div bx
add dl,0x30
mov [0x7c00+buffer+4],dl

mov cx,0xb800
mov es,cx

mov al,[0x7c00+buffer+4]
mov [es:0x00],al
mov byte[es:0x01],0x2f

mov al,[0x7c00+buffer+3]
mov [es:0x02],al
mov byte[es:0x03],0x2f

mov al,[0x7c00+buffer+2]
mov [es:0x04],al
mov byte[es:0x05],0x2f

mov al,[0x7c00+buffer+1]
mov [es:0x06],al
mov byte[es:0x07],0x2f

mov al,[0x7c00+buffer]
mov [es:0x08],al
mov byte[es:0x09],0x2f


buffer db 0,0,0,0,0

;jmp start

current:
times 510-(current-start) db 0
db 0x55,0xaa
