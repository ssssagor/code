org 100h
.model SMALL
.STACK 100H
.DATA


.CODE
MAIN PROC
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H 
    
    MOV AH,1
    INT 21H
    MOV BH,AL 
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    
    MOV AH,2
    MOV DL,BL 
    INT 21H
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    MOV AH,2
    MOV DL,BH
    INT 21H  
    
    
    
    MOV AH,2
    MOV DL,07
    INT 21H
    
 EXIT:
    MOV AH,4CH
    INT 21H
  MAIN ENDP
END MAIN
    
    