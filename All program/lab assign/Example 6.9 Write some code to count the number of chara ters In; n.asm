.model small
.stack 256   
.data
otp db 'Enter a string until terminate the program : $'       
.code

main proc     
    mov ax,@data
    mov ds,ax 
    
    mov ah,9
    lea dx,otp
    int 21h 
    
    mov cl,0  
    
    level1:   
        mov ah,1
        int 21h
        mov bl,al
        
        cmp bl,13
        je exit:
                 
        inc cl
        jmp level1:
    
    exit:
        
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    mov ah,2
    mov dl,cl  
    add dl,48
    int 21h
    main endp
end main