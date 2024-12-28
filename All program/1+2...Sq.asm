org 100h

 .MODEL SMALL
 .STACK
 .DATA
   
  
   I dw 1
   ADDs dw ?
   
 .CODE
 
    main proc
        mov ax,@data
        mov ds,ax
        
        mov ah,01h
        int 21h
        sub al,48
        
        mov cx,0
        mov cl,al
        mov bx,0
        mov ax,0
    
    SUM: 
        mov ax,I
        mul ax
        add bx,ax
        
        inc I
        loop SUM
        
        mov ADDS,bx
        
        
    main endp
   end main




ret



    
