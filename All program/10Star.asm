

org 100h
.model small
.stack 100h
.data

a db 10,13, 'star problem $'
.code

main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h 
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h 
    
    mov cx,10 
    
 level:
    mov dl,'*'
    mov ah,2
    int 21h  
    int 21h
    int 21h
    int 21h
    
    
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    loop level
    
  exit:
    mov ah,4ch
    int 21h
    
  main endp
end main
    


ret




