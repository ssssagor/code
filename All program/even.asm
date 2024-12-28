

org 100h

org 100h
 .MODEL SMALL
 .STACK 100h
 .DATA
     MSG1 DB ':THE GIVEN NUMBER IS ODD$'
    
     MSG2 DB ':THE GIVEN NUMBER IS EVEN$'  
  .CODE
 MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    MOV CX,9
    LOOPER:
    MOV AH,1
    INT 21H
    MOV BL,2 
    DIV BL
    CMP AH,1 
    JE ODD 
    MOV AH,9
    LEA DX,MSG2
    INT 21H 
    JMP SKIP  
   ODD: 
       MOV AH,9
       LEA DX,MSG1
       INT 21H   
   SKIP:
       MOV AH,2
       MOV DL,0DH
       INT 21H
       MOV DL,0AH
       INT 21H
     LOOP LOOPER
     MAIN ENDP
 END MAIN
       
        
   
    







ret




