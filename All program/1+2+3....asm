

 org 100h

 .MODEL SMALL
 .STACK
 .DATA
   
   ARR DB 1,2,3,4,5,6,7,8,9,10
   I db 1
   ADDs db ?
   
 .CODE
 
    main proc
        mov ax,@data
        mov ds,ax
        
        mov SI,offset ARR
        mov cx,10
  
        mov bx,0
  
    SUM: 
 
        add bh,[SI]
        inc SI
        loop SUM
        
        mov ADDS,bh
        
        
    main endp
   end main


ret






