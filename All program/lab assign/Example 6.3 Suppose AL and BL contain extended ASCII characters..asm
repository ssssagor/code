.model small
.stack 100h
.data
a db 'output : $'
.code

main proc
    mov ax,@data
    mov ds,ax
    
    mov al,90h
    mov bl,82h
    
    compare:
    cmp al,bl
    jb l1
    jmp l2
    
    l2:
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,2
    mov dl,bl
    int 21h
    jmp exit
    
    l1: 
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,2
    mov dl,al
    int 21h
    
    exit:
    mov ah,4ch
    int 21h