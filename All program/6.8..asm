org 100h
.code
main proc
 mov cx,80
 mov dl,15d
 mov ah, 02h
 
 top:
 int 21h
 loop top
 main endp
ret
