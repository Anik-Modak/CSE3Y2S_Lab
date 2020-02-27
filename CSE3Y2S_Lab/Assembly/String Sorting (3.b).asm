.MODEL SMALL
.STACK 100H
.DATA      
X DB 80 DUP(?)
MSG1 DB 'Input String: $'
MSG2 DB 10, 13,'Output String: $'

.CODE      
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
                
    MOV AH,9
    LEA DX, MSG1
    INT 21H 
    
    MOV SI, 0
    MOV AH, 1
    FOR: 
        INT 21H
        CMP AL, 0DH
        JE SORT
        MOV X[SI], AL
        INC SI
        JMP FOR
        
    SORT: 
        DEC SI
        MOV BX, SI
    
        EXTER:
            CMP SI, 0
            JL PRINT
            MOV DI, SI   
        
        INER: 
            CMP DI, 0
            JL EXEND
            MOV CL, X[DI]
            CMP X[SI], CL
            JL MOVE  
            
        INEND:
            DEC DI
            JMP INER 
            
        EXEND: 
            DEC SI
            JMP EXTER
        
        MOVE: 
            XCHG CL, X[SI]
            MOV X[DI], CL
            JMP INEND
    
    PRINT: 
        MOV AH,9
        LEA DX, MSG2
        INT 21H
          
    MOV SI, 0
    MOV AH, 2    
    LOOPING:
        CMP BX, SI
        JL EXIT
        MOV DL, X[SI] 
        INT 21H
        INC SI
        JMP LOOPING 
        
    EXIT:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN
