.model small
.stack 100h

.data
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ax,0
    cmp ax,0
    
    jl negative
    je zero
    jg positive
    
    negative:
    mov bx,-1
    jmp exit
    
    zero:
    mov bx,0
    jmp exit
    
    positive:
    mov bx,1

    
    exit :
    mov ah,4ch
    int 21h