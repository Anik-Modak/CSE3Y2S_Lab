.MODEL SMALL
.STACK 100H
.CODE

MAIN PROC
    
MOV AH, 1 
INT 21H 
MOV BL, AL 

MOV AH, 2
INT 21H
MOV DL, 0AH
INT 21H 
MOV DL, 0DH
INT 21H 


L1: CMP BL,'A'
    JL L
    CMP BL,'Z'
    JG L2
    ADD BL, 32
    JMP L
L2: CMP BL,'a'
    JL L
    CMP BL,'z'
    JG L
    SUB BL, 32
           
L:  MOV DL, BL     
    MOV AH, 2
    INT 21H

Exit:
    MOV AH, 4CH
    INT 21H
    MAIN ENDP 

END MAIN 
