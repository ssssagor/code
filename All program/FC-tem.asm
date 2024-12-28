

org 100h
  
 .model small
 
 .stack 100h
 .DATA
 
 C DW ?
 
 .CODE  
    MAIN PROC
        
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AX,499
    SUB AX,32 
    ADD AX,1
    
    MOV BX,5 
    MUL BX
    MOV BX,9 
    DIV BX
    
    
    
    MOV C,AX
    
  main endp
  
 END MAIN


ret




