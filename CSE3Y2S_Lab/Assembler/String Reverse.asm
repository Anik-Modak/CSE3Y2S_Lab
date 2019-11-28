.MODEL SMALL
.STACK 100H
.DATA
    X DB 80 DUP(?)
    OUTPUT_MSG DB 0AH,0DH,'Reverse String is: $'
.CODE

MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
  
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
    MOV AH,9
    LEA DX,OUTPUT_MSG
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