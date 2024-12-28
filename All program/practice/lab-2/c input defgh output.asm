.model small
.stack 100h  
.data
inp db 'Input : $'
outp db 10,13,'Output : $'   
.code

main proc  
    mov ax,@data
    mov ds,ax    
    
    mov ah,9
    lea dx,inp
    int 21h
    
    mov ah,1
    int 21h
    mov bl,al  
    mov cl,bl 
    
    mov ah,9
    lea dx,outp
    int 21h
    
    cmp bl,97  
    jge L1
    
    L1:
        sub bl,32 
        add bl,1
        cmp bl,90
        jg LL1
        jmp LL2
        LL1:
            sub bl,90
            add bl,64
            mov ah,2
            mov dl,bl
            int 21h  
            jmp f2:
        LL2:
            mov ah,2
            mov dl,bl
            int 21h 
        f2:  
            add bl,1  
            cmp bl,90
            jg LL3
            jmp LL4 
        LL3:
            sub bl,90
            add bl,64
            mov ah,2
            mov dl,bl
            int 21h  
            jmp f3:
        LL4:
            mov ah,2
            mov dl,bl
            int 21h  
        f3:    
            add bl,1  
            cmp bl,90
            jg LL5
            jmp LL6   
            
        LL5:
            sub bl,90
            add bl,64
            mov ah,2
            mov dl,bl
            int 21h  
            jmp f4:
        LL6:
            mov ah,2
            mov dl,bl
            int 21h  
        f4:
            add bl,1  
            cmp bl,90
            jg LL7
            jmp LL8 
        LL7:
            sub bl,90
            add bl,64
            mov ah,2
            mov dl,bl
            int 21h  
            jmp f5:
        LL8:
            mov ah,2
            mov dl,bl
            int 21h
            
        f5:
            add bl,1  
            cmp bl,90
            jg LL9
            jmp LL0 
        LL9:
            sub bl,90
            add bl,64
            mov ah,2
            mov dl,bl
            int 21h 
        LL0:
            mov ah,2
            mov dl,bl
            int 21h  
            
    exit:
    main endp
end main