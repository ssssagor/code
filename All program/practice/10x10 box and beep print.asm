.model small
.stack 100h

.data
a db ,10,13,'enter letter : $'
b db ,10,13, '**********$'
c db '****$'

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h 
    ; star input.............................
    mov ah,1
    int 21h
    mov bl,al 
    
    mov ah,1
    int 21h
    mov bh,al
    
    mov ah,1
    int 21h
    mov cl,al
    ;end input...............................
    
    
    ;new line ......................
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    ;10*star print.................
    
    mov ah,9
    lea dx,b
    int 21h
    int 21h
    int 21h
    int 21h
    int 21h 
    
     ;new line ......................
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    ;4* print...............
    mov ah,9
    lea dx,c
    int 21h
    
    ;char print,,,,,,,,,,,,,
    mov ah,2
    mov dl,bl
    int 21h
    
    mov ah,2
    mov dl,bh
    int 21h
    
    mov ah,2
    mov dl,cl
    int 21h
    
    ;4* print,,,,,,,,,,,,
    mov ah,9
    lea dx,c
    int 21h
    ;10* star print,,,,,,,,,,,
    
    mov ah,9
    lea dx,b
    int 21h
    int 21h
    int 21h
    int 21h
    int 21h
    
    
    ;beep print ,,,,,,,,,,,,,,,
    
    mov ah,2
    mov dl,007
    int 21h
    
    exit:
    mov ah,4ch
    int 21h
    
    main endp
end main
ret
    
    
    
    
    
     