.model small
.stack 100h

.data
a db 10,13, 'enter the 1st number : $'  
b db 10,13, 'enter the 2nd number : $'
c db 10,13, 'enter the 3rd number : $'
d db 10,13, 'result : $'

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,01
    int 21h
    mov bl,ah
    
    mov ah,9
    lea dx,b
    int 21h
    
    mov ah,1
    int 21h
    mov bh,al
    
    mov ah,9
    lea dx,c
    int 21h
    
    mov ah,1
    int 21h
    mov cl,al

    biggest:
    cmp bl,bh
    jge l1 
   
    
    l2: 
    cmp bh,cl
    jge l3 
    
    mov ah,9
    lea dx,d
    int 21h 
    
    mov ah,02
    mov dl, cl
    int 21h
    jmp exit
    
    l3: 
    mov ah,9
    lea dx,d
    int 21h
    
    mov ah,2
    mov dl,bh
    int 21h
    jmp exit
    
    l1:   
    cmp bl,cl
    mov ah,9
    lea dx,d
    int 21h
    mov ah,2
    mov dl,bl
    int 21h
    jmp exit
    
    exit:
    mov ah,4ch
    int 21h
    main endp     
end main
ret










