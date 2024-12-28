.model small
.stack 100h
 
.data

.code
main proc
    
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
   
    
    cmp al,'Y'
    je l1
    
    cmp al,'y'
    je l1
    
    jmp exit
    
    l1:
    mov ah,2
    mov dl,al
    int 21
    
    
    
    exit:
    mov ah,4ch
    int 21h