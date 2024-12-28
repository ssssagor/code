 .model small
 .stack 100h
 
 .data
 msg db 'i love mehrab $'
 .code
 main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,msg
    int 21h
    
    
    mov ah,1
    int 21h
    mov bl,al
    
    mov ah,2  
    mov dl,bl
    int 21h
    
    exit:
    mov ah,4ch
    int 21h 
    main endp
 end main
ret