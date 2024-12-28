.model small
.stack 256 
.data
outp db '*$'    
.code

main proc  
    mov ax,@data
    mov ds,ax
    
    mov bx,1
    for:
        cmp bx,80
        jg exit:
        
        mov ah,9
        lea dx,outp
        int 21h
        
        inc bx
        
        jmp for:
    
    exit:
    main endp
end main