.MODEL SMALL
.STACK 100H  

.DATA
MSG1 DB 'Enter number: $'
MSG2 DB 10, 13,'Factorial: $' 

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
    MOV CX, 3 
    
    MOV AH,9
    LEA DX, MSG2
    INT 21H
       
    MOV AX, 1 
    TOP:
        ADD CX
        LOOP TOP
        
    ADD AX, 30H
    MOV DX, AX    
    MOV AH, 2
    INT 21H
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN
