.MODEL SMALL
.STACK 100H
.CODE

.DATA 
MSG DB 'Enter a String : $'
PrintVowel DB 10,13,'Number of Vowels: $'
PrintCons DB 10,13,'Number of Consonants: $'
PrintSpace DB 10,13,'Number of Spaces: $'
PrintDigit DB 10,13,'Number of Digits: $'
bc DB '0'
cc DB '0'
spa DB '0'
num DB '0'    
 


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
        MOV N, SI
        
    MOV SI, 0    
    MOV AH, 2
    NEXT:
        CMP SI, N
        JE EXIT
        
        MOV BL, X[SI]
        CMP BL, 'A'
        JL Print
        CMP BL, 'Z'
        JG lower
        ADD BL, 32
        JMP Print
        
        Lower: 
            CMP BL, 'a'
            JL Print
            CMP BL, 'z'
            JG Print
            SUB BL, 32
    
        Print:  
            MOV DL, BL     
            INT 21H
            INC SI
            JMP NEXT
  
    EXIT: 
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
 
       
        
    
    