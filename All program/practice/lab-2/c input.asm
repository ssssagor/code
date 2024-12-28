.org 100h

.code

main proc
    mov ah,1
    int 21h
    
    
    mov bl,al
    cmp bl,'z'
    je next
    cmp bl,'Z'
    je ne
    
    jmp cal
    
    next:
    mov bl,096
    jmp cal
    ne :
    mov bl,064
    jmp cal
    
    cal:
    
    xor bl,20h
    
    mov cl,5
    top:
     inc bl
    
    mov dl,bl
    mov ah,2
    int 21h
    
    loop top
    ret