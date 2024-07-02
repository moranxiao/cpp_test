Datas segment
    OLDS db 'match'
    NEWS db 'matah'
    ot1 db 'no match$'
    ot2 db 'match$'
Datas ends

CODES segment
    ASSUME cs:CODES,DS:DATAS,ES:DATAS
main proc far
start:    mov ax,Datas
    mov ds,ax
    mov es,ax
    lea si,OLDS
    lea di,NEWS
    mov cx,5
    cld
    repe cmpsb
    jz match
    lea dx,ot1
    mov ah,9
    int 21h
    jmp exit
match:
    lea dx,ot2
    mov ah,9
    int 21h
exit:
    mov ah,4ch
    int 21h
    
    main endp 

CODES ENDS
end start