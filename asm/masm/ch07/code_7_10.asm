assume cs:code,ds:data
data segment
    db '1. file         '
    db '2. edit         '
    db '3. search       '
    db '4. view         '
    db '5. option       '
    db '6. help         '
data ends
code segment
start:
    mov ax,data
    mov ds,ax
    mov bx,0
    mov cx,6
    ;用si定义一个变量，方便复用
    mov si,3
s:
    mov al,[bx+si]
    and al,11011111B
    mov [bx+si],al
    ;
    add bx,16
    loop s

    mov ax,4c00h
    int 21h
code ends
end start