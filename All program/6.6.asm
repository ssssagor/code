org 100h
.data
m1 db 'Enter a character: $'
m2 db 'Result: $'
.code
main proc
 
 lea dx,m1
 mov ah, 09h
 int 21h
 
 mov ah,01h
 int 21h
 mov bl,al
 
 mov dl, 10
 mov ah,02h
 int 21h
 mov dl, 13
 mov ah,02h
 int 21h
 
 cmp bl,65
 jnge end_
 cmp bl, 90
 jnle end_
 jmp display 
 
 display: 
 lea dx,m2
 mov ah, 09h
 int 21h
 
 mov dl,bl
 mov ah, 02h
 int 21h
 
 end_:
 main endp
ret