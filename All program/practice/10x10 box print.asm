.model small
.stack 100h

.data
a db ,10,13, '**********$'
b db ,10,13, '*****CSE*****$'

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
    
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h 
   
   ;b input,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, 
    
    mov ah,9
    lea dx,b
    int 21h  
 ;a input,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, 
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h 
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
     
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h 
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h 
    
    mov ah,9
    lea dx,a
    int 21h  
    mov ah,2
    mov dl,a
    int 21h
    