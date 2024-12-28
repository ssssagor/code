org 100h            ; Program origin
.model small        ; Memory model
.stack 100h         ; Stack size
.data               ; Data section

a db 10,13, 'star problem $' ; Message to display

.code               ; Code section

main proc
    mov ax, @data   ; Load the data segment address into AX
    mov ds, ax      ; Set DS to point to the data segment
    
    ; Display a message
    mov ah, 9        ; AH=9 is the DOS function to display a string
    lea dx, a        ; Load the address of the message into DX
    int 21h          ; Call DOS interrupt 21h to display the message
    
    ; Move the cursor to a new line
    mov ah, 2        ; AH=2 is the DOS function to display a character
    mov dl, 10       ; ASCII code for newline character
    int 21h          ; Call DOS interrupt 21h to display the newline
    mov dl, 13       ; ASCII code for carriage return character
    int 21h          ; Call DOS interrupt 21h to display the carriage return
    
    mov cx, 10       ; Set CX to 10, the number of asterisks to print
    
level:
    ; Print an asterisk
    mov dl, '*'      ; Load the asterisk character into DL
    mov ah, 2        ; AH=2 is the DOS function to display a character
    int 21h          ; Call DOS interrupt 21h to display the asterisk
    int 21h
    int 21h
    int 21h
    ; Move the cursor to a new line
    mov ah, 2        ; AH=2 is the DOS function to display a character
    mov dl, 10       ; ASCII code for newline character
    int 21h          ; Call DOS interrupt 21h to display the newline
    mov dl, 13       ; ASCII code for carriage return character
    int 21h          ; Call DOS interrupt 21h to display the carriage return
    
    loop level       ; Repeat the loop until CX becomes 0
    
exit:
    mov ah, 4ch      ; AH=4Ch is the DOS function to exit the program
    int 21h          ; Call DOS interrupt 21h to exit
    
main endp            ; End of the main procedure

end main            ; End of the program
