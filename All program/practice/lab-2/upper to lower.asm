.model small
.stack 100h


.data
a db 10,13, 'enter the upper case : $'
b db 10,13, ' the lower case : $'

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,1
    int 21h
    mov bl,al
    
    mov ah,9
    lea dx,b
    int 21h
           
    mov ah,2
    add bl,32
    mov dl,bl
    int 21h