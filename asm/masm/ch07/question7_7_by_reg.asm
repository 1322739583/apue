assume cs:code,ds:data
data segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
    db 'sun             '
data ends
code segment
start:
    mov ax,data
    mov ds,ax
    mov bx,0
    ;定义外循环的次数
    mov cx,5
s0:
     mov dx,cx
     ;内循环的次数
     mov cx,3
s:
    mov al,[bx]
    and al,11011111B
    mov [bx],al
    inc bx
    loop s

    ;这种是可行的
    add bx,13
    loop s0
   

    mov ax,4c00h
    int 21h
code ends
end start