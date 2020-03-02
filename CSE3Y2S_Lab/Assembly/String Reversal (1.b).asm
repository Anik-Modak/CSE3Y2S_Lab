.MODEL SMALL
.STACK 100H
.CODE

.DATA
X DB 80 DUP(?)
MSG1 DB 'Input String : $'
MSG2 DB 10, 13,'Output String : $'  


MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH,9
    LEA DX, MSG1
    INT 21H 
    
    
    MOV SI, 0
    INPUT:
        MOV AH, 1
        INT 21H
        CMP AL, 0DH
        JE BREAK
        
        MOV X[SI], AL
        INC SI
        JMP INPUT 
    
    BREAK:
        MOV AH,9
        LEA DX, MSG2
        INT 21H
        
    MOV AH, 2
    REVERSE:
        CMP SI, 0
        JE EXIT
        DEC SI
        MOV DL, X[SI]
        INT 21H
        JMP REVERSE
            
    EXIT: 
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
 
       
        
    
    