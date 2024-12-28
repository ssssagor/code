

org 100h

.MODEL SMALL

.STACK 100H
.DATA

.CODE

    MAIN PROC
        mov ax,@data
        mov ds,ax
        
        MOV AH,01
        INT 21H
        
        MOV BL,AL 
        
        
        CMP BL,97
        JGE SMALL_TO_BIG 
        
  SMALL_TO_BIG: 
  
        SUB BL,32
        
        MOV AH,02
        MOV DL,BL
        INT 21H
        
        
     MAIN ENDP
    
  END MAIN

ret




