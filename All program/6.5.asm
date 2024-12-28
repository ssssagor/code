org 100h
.data
m1 db 'Enter a number: $'
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
 
 mov al,bl
 cmp al, 49d
 je odd
 cmp al, 51d
 je odd
 
 cmp al, 50d
 je even
 cmp al, 52d
 je even
 
 odd:
 mov bl, 111d
 jmp display
 
 even:
 mov bl,101d
 jmp display
 
 display: 
 lea dx,m2
 mov ah, 09h
 int 21h
 
 mov dl,bl
 mov ah, 02h
 int 21h
 main endp
ret