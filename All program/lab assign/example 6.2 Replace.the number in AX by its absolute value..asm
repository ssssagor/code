.model small
.stack 100h

.data
a db 'absulate value of -1 : $'

.code
main proc
    mov ax,@data
    mov ds,ax
    
    
    mov ah,9
    lea dx,a
    int 21h
    
    mov ax,-1
    
    cmp ax,0
    jge l1
    neg ax
    
    l1:
    
    mov ah,2 
    add ax,48
    mov dx,ax
    int 21h
    
    exit:
    mov ah,4ch
    int 21h
    
    
    
    
    
    
    
    
    