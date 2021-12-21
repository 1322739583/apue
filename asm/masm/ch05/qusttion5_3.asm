assume cs:code
code segment

    mov ax,0ffffh
    mov ds,ax
    mov ah,0
    ;mov bx,6
    ; 这个和写[6]是不一样的
    ;会被当作6传给al 调试的时候代码是mov al，06
    mov al,ds:[6]
 
    mov cx,2
s:
    add al,ds:[6]
    loop s
    mov ds,ax

    mov ax,4c00h
    int 21h
code ends
end