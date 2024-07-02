data segment
 message db 'The input char isn',27h,'t between '
        db 27h,'a',27h,' and ',27h,'z',27h,'.Please input'
        db 'again!',13,10,'$'
 crlf db 13,10,'$'
 buf db 80,?,80 dup(?)
data ends
code segment
 assume cs:code,ds:data
start:
 mov ax,data
 mov ds,ax
again:
 lea dx,buf
 mov ah,10
 int 21h  ;输入字符串到缓冲区buf中
 lea dx,crlf
 mov ah,9
 int 21h  ；输出回车换行
 lea si,buf+2
 mov cl,buf+1
 mov ch,0
l:
cmp byte ptr [si],'a'
 jb error ;若输入的字符小于‘a’，则输出错误信息
 cmp byte ptr [si],'z'
 jg error ;若输入的字符大于‘z’，则输出错误信息
 sub byte ptr [si],20h ；否则将小写转换成大写
 inc si
 loop l
 mov byte ptr [si],'$' ;在字符串末尾加上‘$’
 lea dx,buf+2
 mov ah,9
 int 21h   ;输出转换成大写的字符串
 jmp exit
error:
 lea dx,message
 mov ah,9
 int 21h
 jmp again
exit:
 mov ah,4ch
 int 21h
code ends
 end start
