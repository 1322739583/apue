assume  cs:code 


a segment
    db 1,2,3,4,5,6,7,8
a ends

b segment
    db 1,2,3,4,5,6,7,8
b ends

d segment
    db 0,0,0,0,0,0,0,0
d ends


code segment
main:
    
   mov ax,a 
   mov ds,ax
   mov bx,0
   mov cx,8
   
s:
    mov dx,0
    add dx,ds:[bx]
    add dx,ds:[bx+16]
    mov ds:[bx+32],dx
    inc bx
    loop s 

    mov ax,4c00h
    int 21h
code ends

 
end main