.MODEL SMALL
.STACK 100H    

.DATA
str DB 80 DUP 
MSG1 DB 'Enter String: $'
MSG2 DB 'Number of vowels: $'
MSG3 DB 'Number of consonants: $'

.CODE 

MAIN PROC 
     
MOV AX, @DATA
MOV DS, AX
    
LEA DX, MSG1
MOV AH,9
INT 21H 
           
MOV BL, 48           
MOV CL, 48
MOV AH, 1 

NEXT:
INT 21H                   
CMP AL, 0DH
JZ EXIT

CMP AL,'z'
JG ignore  
CMP AL,'A'
JL ignore

CMP AL,96
JG  OK

CMP AL,90
JG  ignore

OK:

MOV str[SI], AL

CMP str[SI],'A'  
JZ vowel
CMP str[SI],'a'
JZ vowel
CMP str[SI],'E'
JZ vowel
CMP str[SI],'e'
JZ vowel
CMP str[SI],'I'
JZ vowel
CMP str[SI],'i'
JZ vowel
CMP str[SI],'O'
JZ vowel       
CMP str[SI],'o'
JZ vowel
CMP str[SI],'U'
JZ vowel
CMP str[SI],'u'
JZ vowel       
       
       
ADD CL,1
SUB BL,1
vowel:
ADD BL,1

ignore:

INC SI
JMP NEXT            
EXIT:                 

DEC SI
            
MOV AH,2 
MOV DL,0AH
INT 21H
MOV DL,0DH
INT 21H

LEA DX, MSG2
MOV AH,9
INT 21H
         
MOV AH,2
MOV DL,BL
INT 21H   

MOV AH,2 
MOV DL,0AH
INT 21H
MOV DL,0DH
INT 21H 

LEA DX, MSG3
MOV AH,9
INT 21H

MOV AH,2
MOV DL,CL
INT 21H  
           
              
MOV AH, 4CH
INT 21H     

MAIN ENDP     

END MAIN

