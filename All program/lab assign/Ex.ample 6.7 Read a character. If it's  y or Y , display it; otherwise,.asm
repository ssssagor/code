.model small
.stack 100h
.code
main proc
    mov ah,1
    int 21h
    mov bl,al   
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    cmp bl,'y'
    jz L1
    cmp bl,'Y'
    jz L1 
    jmp L2
    
    L1:
    mov ah,2
    mov dl,bl
    int 21h
    jmp exit:   
    
    L2:
    jmp exit:
    
    exit:
    main endp
end main