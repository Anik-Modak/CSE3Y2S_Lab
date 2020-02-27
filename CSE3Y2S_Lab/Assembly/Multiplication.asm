.model small
.stack 100H
.data
a dw ?
b dw ?
c dw 'Enter 1st digit: $'
d dw 10, 13 'Enter 2nd digit: $'
ans dw 10, 13 'Result: $'

.code
main proc
    mov ax @data
    mov ds ax
    
    mov ah, 9
    lea ds, c
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 48
    mov a, al
    
    mov ah, 9
    lea ds, c
    int 21h
    
    mov ah, 1
    int 21h
    sub al, 48
    mov b, al
    
    exit: 
    mov ah, 4ch
    int 21h
    main endp
end main
    