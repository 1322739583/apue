assume cs:code
code segment

    dw 01h,02h,03h,04h,05h,06h,07h,08h
start:
    ;mov dx,100h
   ; mov cs,dx
    mov ax,0
    mov bx,0
    mov cx,5
    ;这样不太好，因为前面已经执行一半了，而且ip都已经发生了变化
 
s:
    add ax,cs:[bx]
    add bx,2
    loop s

    mov ax,4c00h
    int 21h
code ends
end start