assume cs:code
code segment

start:
    mov ax,0
    mov bx,1
    mov ax,[200];被解析为mov ax,200
    mov ax,[200+1];被解析为 mov ax,201
    mov ax,[bx]
    mov ax,[200+bx]
    mov ax,200[bx]
    mov ax,[bx].200

    mov ax,4c00h
    int 21h
code ends
end start