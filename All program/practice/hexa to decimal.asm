.model small
.stack 100h

.data
a db 'enter the hex: $' 
b db '1$'
c db ,10,13, 'decimal value : $'

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
    lea dx,c
    int 21h 
    ; print 1 at first,,,,,,,,,,
    mov ah,9
    lea dx,b
    int 21h
    ;17 minus,,,,,,,,,,, 
    sub bl,17d
     
    mov ah,2
    mov dl,bl
    int 21h
    
    
    
    
    
    
    