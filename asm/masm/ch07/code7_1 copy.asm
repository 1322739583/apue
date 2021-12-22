;目的：将字符串大写转小写
assume cs:code,ds:data
data segment
	db 'I Love'
	db 'AssEmBly'
data ends

code segment

	start:
	      mov  ax,data
	      mov  ds,ax
	      mov  cx, 6
	      mov  bx,0
	s:    
	      mov  al,ds:[bx]
	      and  al,11011111B
	      mov  ds:[bx],al
          inc bx
	      loop s
          mov cx,8
	s0:   
          mov al,ds:[bx]
          or al,00100000B
          mov ds:[bx],al
          inc bx
          loop s0

	      mov  ax,4c00h
	      int  21h
code ends
end start