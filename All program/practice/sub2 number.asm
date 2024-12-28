          .model small
.stack 100h

.data
    msg1 db 10,13,'enter the 1st number : $'
    msg2 db 10,13,'enter the 2nd number : $'
    msg3 db 10,13,'result : $'
.code
main proc
    mov ax,@data
    mov ds,ax
    
            
    mov ah,09
    lea dx,msg1
    int 21h
            
    mov ah,1
    int 21h
    mov bl,al
    
    
    mov ah,09
    lea dx,msg2 
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al  
    
    
    mov ah,09
    lea dx,msg3
    int 21h
    
    sub bl,bh  ;bl=bl-bh
    add bl,48  ;bl=bl-48
    
     
    
    mov ah,02
    mov dl,bl
    int 21h
    
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main
ret