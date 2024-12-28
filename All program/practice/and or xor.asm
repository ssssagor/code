.model small
.stack 100h

.data
 a db 10,13, 'for AND : $'
 b db 10,13, 'for OR : $'
 c db 10,13, 'for XOR : $'
 
 
.code
main proc 
    
    mov ax,@data
    mov ds,ax
    
    ;for AND.................
    mov ah,9
    lea dx,a
    int 21h
    
    mov bl,111b   ;oprand1
    and bl,101b   ;oprand2=111b AND 101b
    
    add bl,48
    
    mov ah,2
    mov dl,bl
    int 21h
    ;for OR .................
    mov ah,9
    lea dx,b
    int 21h
    
    mov bh,111b
    or bh,101b
    
    add bh,48
    
    mov ah,2
    mov dl,bh
    int 21h
    
    ;for xor................. 
    
    mov ah,9
    lea dx,c
    int 21h
    
    mov cl,111b
    xor cl,101b
    
    add cl,48
    
    mov ah,2
    mov dl,cl
    int 21h
    
    
    
    