;assume cs:code,ds:data
data segment
    db 'unIX'
     db 'foRK'
   db 0,0,0,0,0,0,0,0
    
data ends
code segment
start:

    

    mov al,0
    mov ah,0

    mov ax,4c00h
    int 21h
code ends
end start

 