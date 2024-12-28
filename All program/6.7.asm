org 100h
.data
m1 db 'Enter 'y' or 'Y': $'
m2 db 10,13, 'You entered: $'
.code
main proc
 
 lea dx,m1
 mov ah, 09h
 int 21h
 
 mov ah,01h
 int 21h
 mov bl,al
 
 
 cmp bl,89d
 je display
 cmp bl, 121d
 je display 
 
 jmp end_
 
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