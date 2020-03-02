.MODEL SMALL
.STACK 100H
.CODE

.DATA
MSG1 DB 'Input : $'
MSG2 DB 10, 13,'Output : $'  


MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH,9
    LEA DX, MSG1
    INT 21H 
    
    MOV AH, 1
    INT 21H
    MOV BL, AL
    
    L1: 
        CMP BL, 'A'
        JL L
        CMP BL, 'Z'
        JG L2
        ADD BL, 32
        JMP L
        
    L2: 
        CMP BL, 'a'
        JL L
        CMP BL, 'z'
        JG L
        SUB BL, 32
    
    L:  
        MOV AH,9
        LEA DX, MSG2
        INT 21H 
        
        MOV DL, BL     
        MOV AH, 2
        INT 21H
    
    EXIT: 
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
 
       
        
    
    