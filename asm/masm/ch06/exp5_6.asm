assume  cs:code 


a segment
    dw 0,1,2,3,4,5,6,7
    dw 8,9,0ah,0bh,0ch,0dh,0eh,0fh
a ends

b segment
    dw 0,0,0,0,0,0,0,0
b ends


code segment
main:
    
    mov ax,b
    mov ss,ax
    mov sp,16

    mov ax,a
    mov ds,ax
    mov bx,0
    mov cx,8
s:
    push ds:[bx]
    add bx,2
    loop s

    mov cx,8
    mov bx,0 
s0:
    pop ds:[bx]
    add bx,2
    loop s0

    mov ax,4c00h
    int 21h
code ends

 
end main