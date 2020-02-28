.MODEL SMALL
.STACK 100H  

.DATA
MSG1 DB 'Enter number: $'
MSG2 DB 10, 13,'Total sum: $' 

.CODE      
MAIN PROC  
    MOV AX, @DATA
    MOV DS, AX  
    
    MOV AH,9
    LEA DX, MSG1
    INT 21H
    MOV AH, 1
    INT 21H  
              
    SUB AL, 30H
    MOV CL, AL 
    
    MOV AH,9
    LEA DX, MSG2
    INT 21H
    
    XOR CH, CH
    XOR AL, AL 
    TOP:
        ADD AL, CL
        LOOP TOP
        
    ADD AL, 30H
    MOV DL, AL    
    MOV AH, 2
    INT 21H
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN