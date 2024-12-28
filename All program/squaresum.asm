.model small 
.stack 100h
.data
a db 1,2,3,4,5,6,7,8,9,10
b db "Enter the value of n: $"               
c db 10,13,"The summation of(1*1+2*2+3*3... n*n):$"
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,b
    int 21h
    
    mov ah,1
    int 21h  
    
    sub al,48
        
    mov cl,al
    mov ch,0
    mov si,0 
    mov bl,0
    mov bh,0
  
    next: 
        mov al,a[si]
        mov bh,a[si]  
        mul bh
        add bl,al
        inc si
        loop next 
        
    mov ah,0
    mov al,bl
    mov bl,10
    div bl
    
    mov bl,al
    mov bh,ah
    
    add bl,48
    add bh,48 
    
    lea dx,c
    mov ah,9
    int 21h
    
    mov ah,2
    mov dl,bl
    int 21h  
    
    mov ah,2
    mov dl,bh
    int 21h
      
    main endp
end main