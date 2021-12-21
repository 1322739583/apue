assume cs:code
code segment

    mov al,01100011B
    ;and al,00111011B
    ;将有0的位置设为0
    and al,11110111B
    ;将有1的位置设为1
    or  al,00010000B
    

    mov ax,4c00h
    int 21h
code ends
end
