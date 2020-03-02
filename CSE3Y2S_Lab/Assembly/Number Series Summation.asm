.MODEL SMALL
.STACK 100H  

.DATA
MSG1 DB 'Enter number: $'
MSG2 DB 10, 13,'Total sum : $'

.CODE      
MAIN PROC  
    MOV AX, @DATA
    MOV DS, AX  
    
    MOV AH,9
    LEA DX, MSG1
    INT 21H
    MOV AH, 1
    INT 21H
    
    SUB AL, 48 
    MOV CL, AL
    XOR CH, CH
    
    MOV AH,9
    LEA DX, MSG2
    INT 21H
    
    MOV AL, 0
    CMP CL, 0
    JE PRINT
      
    TOP:
        ADD AL, CL
        LOOP TOP
    
    PRINT:
        ADD AL, 48
        MOV DL, AL
        MOV AH, 2
        INT 21H
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN
        