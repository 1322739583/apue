assume cs:code,ss:stack, ds:data

stack segment
    dw 0,0,0,0,0,0,0,0
stack ends
data segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
data ends

a segment
    
a end

code segment
main:
    
    mov ax,stack
    mov ss,ax
    mov sp,16

    mov ax,data
    mov ds,ax

    push ds:[0]
    push ds:[2]
    pop ds:[2]
    pop ds:[0]
    

    mov ax,4c00h
    int 21h
code ends
end main