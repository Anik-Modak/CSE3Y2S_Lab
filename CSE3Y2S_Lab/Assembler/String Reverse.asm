.MODEL SMALL
.STACK 100H
.DATA
X DB 80 DUP(?)
MSG1 DB 'Input String: $'
MSG2 DB 'Output String: $'
.CODE 

MAIN PROC
    
    MOV AX,@DATA
    MOV DS, AX
    
    LEA DX, MSG1
    MOV AH,9
    INT 21H 
    
    MOV SI,0
    TAKEINPUT:
        MOV AH,1
        INT 21H
     
        CMP AL,0DH
        JE TERMINATE
     
        MOV X[SI], AL
        INC SI
        JMP TAKEINPUT
 
      
    TERMINATE: 
    MOV AH,2
    MOV DL, 0DH
    INT 21H
    MOV DL,0AH
    INT 21H 
      
    
    LEA DX, MSG2
    MOV AH,9
    INT 21H
    
    NEXT:
        CMP SI,0
        JE EXIT
     
        MOV AH,2
        DEC SI
        MOV DL, X[SI]
        INT 21H
        JMP NEXT
     
    EXIT: 
    MOV AH,4CH
    INT 21H
    MAIN ENDP

END MAIN