org 100h
.data
m db 'Number of character is: $'
.code
main proc
 mov dx,0
 mov ah, 01h
 int 21h
 while_:
 cmp al,0dh
 je end_while
 inc dx
 int 21h
 jmp while_
 
 end_while: 
 mov bx,dx 
 add bx,48d 
 
 mov dl,10
 mov ah,02h
 int 21h
 mov dl,13
 mov ah,02h
 int 21h
 lea dx,m
 mov ah, 09h
 int 21h
 
 
 
 mov dx,bx
 mov ah,02h
 int 21h
 main endp
ret