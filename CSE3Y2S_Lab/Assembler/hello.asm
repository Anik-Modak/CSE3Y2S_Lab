code segment
assume cs:code, ds:data, ss:stack

main proc
mov ax,data
mov ds, ax

mov ah, 0 
mov al, num
mov bl,2
div bl
cmp ah,0
je L1

mov dx, offset msg2
mov ah, 9
int 21h
jmp exit
L1: mov dx, offset msg1
	mov ah, 9
	int 21h


exit:	 mov ax,4c00h
	int 21h

main endp
code ends

data segment
msg1 db "this number is even", '$'
msg2 db " this number is odd", '$'

num db 21
data ends

stack segment STACK
db 100h dup(0)
stack ends

end main