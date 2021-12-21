start:
mov ax,65535
mov bx,65535
xor dx,dx
div bx

;56666/10  商存放在ax(5666),余数存放在dx
;100/10    商存放在al(10),

current:
times 510-(current-start) db 0
db 0x55,0xaa
