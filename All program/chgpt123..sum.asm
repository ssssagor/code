org 100h
.model small
.stack 100h
.DATA
    N DW 15      ; Change this value to calculate the sum up to a different N
    SUM DW ?     ; Variable to store the sum
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV CX, N       ; Load N into CX for loop control
    MOV AX, 0       ; Initialize the sum to 0

LOOP_START:
    ADD AX, CX      ; Add the current value of CX to AX (1+2+3+...)
    DEC CX          ; Decrement CX to move to the next number
    JNZ LOOP_START  ; Jump back to LOOP_START as long as CX is not zero
    
    MOV SUM, AX     ; Store the final sum in the SUM variable
    
    ; Display the sum as a decimal number (you may add ASCII conversion if needed)
    MOV AX, SUM
    ; Add code here to convert AX to ASCII and display it
    
    ; Your program can end here or perform additional tasks
    
    MOV AH, 4Ch     ; DOS function to terminate program
    INT 21h         ; Call DOS interrupt
    
MAIN ENDP
END MAIN
