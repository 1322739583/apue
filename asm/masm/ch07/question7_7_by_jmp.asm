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
    mov cx,3
s:
    mov al,[bx]
    and al,11011111B
    mov [bx],al
    inc bx
    loop s

    ;这种是可行的
    add bx,13
    mov cx,3
    jmp s

    mov ax,4c00h
    int 21h
code ends
end start