org 100h
.data
m db 'Number of character is: $'
.code
main proc
    mov cl,0
   while: 
   
   mov ah,01h
   int 21h 
   cmp al,' '
   je exit
   inc cl
   jmp while
   
   
   
   exit:
   mov dl,cl
   add dl,48
   mov ah,02h 
   int 21h
   
   
   
 main endp
ret