.model small
.stack 100h

.data
a db 10,13, 'enter the three case : $'
b db 10,13, 'output : $'
c db '***** $'

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
    
    
    mov ah,1
    int 21h
    mov bh,al
    
    mov ah,1
    int 21h
    mov cl,al
    
    
    mov ah,9
    lea dx,b
    int 21h
    
    mov ah,9
    lea dx,c
    int 21h 
    
    mov ah,2
    mov dl,bl
    int 21h 
    
    mov ah,2
    mov dl,bh
    int 21h
    
    mov ah,2
    mov dl,cl
    int 21h
    
    mov ah,9
    lea dx,c
    int 21h 
    
    