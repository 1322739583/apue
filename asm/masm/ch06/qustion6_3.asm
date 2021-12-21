;题目:将01,02,03,04,05,06,07,08逆序

assume cs:code
code segment

    dw 01,02,03,04,05,06,07,08
    dw 0,0,0,0,0,0,0,0
    
start:
    mov ax,cs
    mov ss,ax
    mov sp,20h

    mov bx,0
    mov cx,8h
s:
    push cs:[bx]
    add bx,2
    loop s
    mov bx,0
    mov cx,8
s0:
    pop cs:[bx] 
    add bx,2
    loop s0   

    mov ax,4c00h
    int 21h
code ends
end start