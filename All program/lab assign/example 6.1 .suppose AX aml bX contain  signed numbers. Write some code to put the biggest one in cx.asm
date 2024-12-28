.model small
.stack 100h

.data
a db 10,13, 'enter the 1st number : $'
b db 10,13, 'enter the 2nd number : $'
c db 10,13, 'output : $'


.code
main proc
    mov ax,@data
    mov ds,ax
    
    
    mov ah,9
    lea dx,a
    int 21h
    
    mov ah,1
    int 21h
    mov bx,ax 
    
    mov ah,9
    lea dx,b
    int 21h
    
    mov ah,1
    int 21h
    
    biggest:
    cmp ax,bx
    jge level1
    jmp level2
    
    
    level2:
    
    mov cx,bx
    
    mov ah,9
    lea dx,c
    int 21h
    
    mov ah,2
    mov dx,cx
    int 21h
    
    jmp exit
    
    level1:
    
    mov cx,ax
    
    mov ah,9
    lea dx,c
    int 21h
    
    mov ah,2
    mov dx,cx
    int 21h
    
    jmp exit 
    
    exit:
    mov ah,4ch
    int 21h
    