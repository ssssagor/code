.model small
.stack 100h


.code
main proc
    
    mov ah,1
    int 21h
    
    
    mov bl,al
    
    xor bl,20h
    
    mov cl,5
    
    top:
    
    inc bl
    
    mov dl,bl
    mov ah,2
    int 21h
    loop top
    ret