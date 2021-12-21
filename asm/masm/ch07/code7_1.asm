;目的：将字符串大写转小写
assume cs:code,ds:data
data segment
    ;需要转成小写的字符串
    db 'BaSiC'
    db 'iNforMatiOn'
data ends

code segment

start: mov ax,data
    ;可以查看到data段的地址
   
    ;现在可以通过ds操作了
    mov ds,ax
    mov bx,0
    ;先循环BaSic，有5个字符
    mov cx,5
;第一个循环，用来循环iNforMatiOn
s: mov al,[bx]
    
    and al,11011111B
    mov [bx],al
    inc bx
    loop s
    
    ;移动5个位置
    mov bx,5

    ;循环iNforMatiOn需要11次
    mov cx,11
;第二个循环，用来循环BaSic
s0:  mov al,[bx]
   
    or al,00010000B
    mov [bx],al
    inc bx
    loop s0

    mov ax,4c00h
    int 21h
code ends
end