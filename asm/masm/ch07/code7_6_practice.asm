assume cs:code,ds:data
data segment
    db 'AbCDe'
    db 'fgHij'
data ends
code segment
start:
    ;第一步 定位和初始化
    mov ax,data
    mov ds,ax
    mov bx,0
    mov cx,5
    ;第二步 获取数据，处理数据
s:
    mov al,[bx]
    and al,11011111B
    mov [bx],al

    mov al,5[bx]
    or al,00100000B
    mov 5[bx],al
    
    inc bx
    loop s

    mov ax,4c00h
    int 21h
code ends
end start