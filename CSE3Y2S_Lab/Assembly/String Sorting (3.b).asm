.MODEL SMALL
.STACK 100H
.DATA
N DW 0      
str DB 80 DUP(?) 
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
        JE BREAK;
        MOV str[SI], AL
        INC SI
        JMP FOR 
    
    BREAK: 
        MOV N, SI
        MOV SI, 0
            
    FOR1:
    	CMP SI, N
    	JGE PRINT
    	MOV DI, SI
        FOR2:
	        MOV BL, str[SI]
	        CMP BL, str[DI]
	        JL SKIP
	        XCHG BL, str[DI]
	        MOV str[SI], BL
	
            SKIP:
                INC DI
                CMP DI, N
            	JL FOR2 
            	
            INC SI
            JG FOR1
            	 
    PRINT: 
        MOV AH,9
        LEA DX, MSG2
        INT 21H
          
    MOV SI, 0
    MOV AH, 2    
    LOOPING:
        CMP SI, N
        JGE EXIT
        MOV DL, str[SI] 
        INT 21H
        INC SI
        JMP LOOPING 
        
    EXIT:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN