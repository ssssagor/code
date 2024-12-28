.model small
.stack 100h

.data
 f dw ?
.code
main proc 
    mov ax,@data
    mov ds,ax
    
    
    mov ax,260 
    mov bx,9
    mul bx  
    
    mov bx,5
    div bx
    
    add ax,32
    sub ax,1
    
    mov f,ax
    
    
    