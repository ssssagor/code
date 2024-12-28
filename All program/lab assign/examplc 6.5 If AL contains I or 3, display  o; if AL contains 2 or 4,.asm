.model small
.stack 100h 
.data
odd db 10,13,'o $'
even db 10,13,'e $'
.code
main proc 
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
    mov bl,al
    
    cmp bl,49
    jz L1
    cmp bl,51
    jz L1
    cmp bl,50
    jz L2
    cmp bl,52
    jz L2
    
    L1: 
    mov ah,9
    lea dx,odd
    int 21h
    jmp exit:
    L2:
    mov ah,9 
    lea dx,even
    int 21h
    jmp exit:
    
    exit:
    main endp
end main