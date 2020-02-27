.MODEL SMALL
.STACK 100H

.DATA
X DB 80 DUP(?)
MSG1 DB 'Input String: $'
MSG2 DB 10, 13,'Output String: $'  

.CODE 
MAIN PROC
    
    MOV AX,@DATA
    MOV DS, AX
    
    MOV AH,9
    LEA DX, MSG1
    INT 21H 
    
    MOV SI,0 
    MOV AH,1
    TAKEINPUT:  
        INT 21H
        CMP AL, 0DH
        JE TERMINATE
     
        MOV X[SI], AL
        INC SI
        JMP TAKEINPUT
 
      
    TERMINATE:
        MOV AH,9 
        LEA DX, MSG2
        INT 21H
    
    
    MOV AH,2
    NEXT:
        CMP SI,0
        JE EXIT
     
        DEC SI
        MOV DL, X[SI]
        INT 21H
        JMP NEXT
     
    EXIT: 
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
