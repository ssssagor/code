.model samll
.stack 100h

.data 
c dw ?

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ax,499
    sub ax,32
    add ax,1
    
    mov bx,5
    mul bx
    
    mov bx,9
    div bx
    
    mov c,ax
    