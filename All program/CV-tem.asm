

org 100h
  
 .model small
 
 .stack 100h
 .DATA
 
 F DW ?
 
 .CODE  
    MAIN PROC
        
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AX,260
    MOV BX,9
    MUL BX
    MOV BX,5
    DIV BX
    
    ADD AX,32
    SUB AX,1
    
    MOV F,AX
    
  main endp
  
 END MAIN


ret




