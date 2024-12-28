.model small
.stack 100h

.data

.code
main proc
    mov ax,@data
    mov ds,ax
    
    
    mov ah,1
    int 21h   
    
    cmp al,'A'
    jnge exit
    
    cmp al,'Z'
    jnle exit
    
    mov ah,2
    mov dl,al
    int 21h
    
    exit:
    mov ah,4ch
    int 21h
    