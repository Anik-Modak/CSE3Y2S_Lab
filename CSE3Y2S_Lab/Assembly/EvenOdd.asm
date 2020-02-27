.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'Enter Number: $'
MSG2 DB 10, 13,'The number is Odd$'
MSG3 DB 10, 13,'The number is Even$'  

.CODE      
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX
     
    MOV AH,9
    LEA DX, MSG1
    INT 21H 
    MOV AH, 1
    INT 21H
    
    SUB AX, 30H    
    MOV BX, 2
    MOV DX, 0
    
    DIV BX
    CMP DX, 0
    JE even
    
    MOV AH,9
    LEA DX, MSG2
    INT 21H 
    JMP Exit
        
    Even:
        MOV AH,9
        LEA DX, MSG3
        INT 21H
      
    Exit:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN