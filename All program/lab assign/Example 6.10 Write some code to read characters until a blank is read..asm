.model small
.stack 256 
.data
otp db 'Enter a string until blank is read : $'    
.code

main proc  
    mov ax,@data
    mov ds,ax
    mov ah,9
    lea dx,otp
    int 21h  
    
    for:   
        mov ah,1
        int 21h
        mov bl,al
        
        cmp bl,' '
        je exit:
        
        jmp for:
    
    exit:
    main endp
end main