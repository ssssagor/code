.model small
.stack 100h

.data
msg1 db 'first number: $'
msg2 db 'secode number : $'

.code

main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,msg1
    int 21h
    
    mov ah,1
    int 21h
    mov bl,al
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    mov ah,9
    lea dx,msg2
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al
    
    
    exit:
    mov ah,4ch
    int 21h
   
    main endp
end main
ret
    
    