mov ax,123
mov cx,236-1

s:
    add ax,123
    loop s

    mov ax,4c00h
    int 21h