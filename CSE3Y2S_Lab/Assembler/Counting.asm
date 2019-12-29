.MODEL SMALL
.STACK 100H    

.DATA
	str DB 80 DUP ?
	MSG DB "ENTER A STRING: $"
	vowel_ DB "Number of Vowel: $"
	cons_ DB "Number of Consonants: $"
	space_ DB "Number of Spaces: $"
	number_ DB "Number of Digits: $"
	bc DB '0'
	cc DB '0'
	space DB '0'
	num DB '0'    
	;vowelarr DB 80 DUP ?
	;consarr DB 80 DUP ?
	;vindex DB 48
	;cindex DB 48

.CODE   
    MAIN PROC
    MOV AX, @DATA
	MOV DS, AX
	
	MOV AH,9
	LEA DX, MSG
	INT 21H
	
	MOV BL,48           
	MOV CL,48
	MOV SI,0
	MOV AH,1 
	
NEXT:
	INT 21H
	CMP AL,0DH
	JZ EXIT
	
	MOV str[SI], AL
	
	;comparing
L1: CMP str[SI],'A'
    JL L
    CMP str[SI],'Z'
    JG L2
    JMP L3
L2: CMP str[SI],'a'
    JL L
    CMP str[SI],'z'
    JG L
    JMP L3

	;COMPARISION FOR VOWEL
L3:
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
	JMP cons
vowel:
    ;MOV vowelarr[vindex], AL
    ;ADD vindex,1
	ADD bc,1
	jmp L
cons:
    ;MOV consarr[cindex], AL
    ;ADD cindex, 1
	ADD cc,1
L:  
    CMP str[SI],' '
    JNE number
    ADD space, 1
    JMP ignore
number:
    CMP str[SI],'0'
    JL ignore
    CMP str[SI],'9'
    JG ignore
    ADD num,1
ignore:
    INC SI
    JMP NEXT
    
EXIT:
	DEC SI
    ;MOV _vowel[vindex],'$'
    ;MOV _cons[cindex], '$'
	
	;print a new line
	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H
	
	
	;output vowel
	MOV AH,9
	LEA DX, vowel_
	INT 21H 
	
	MOV AH,2
	MOV DL,bc
	INT 21H  
	
	
	
	;print a new line

	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H   
	
	;output consonants
	MOV AH,9
	LEA DX, cons_
	INT 21H
	
	MOV AH, 2
	MOV DL,cc
	INT 21H
	
	;print a new line
	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H
	
	;output space
	MOV AH,9
	LEA DX, space_
	INT 21H
	
	MOV AH, 2
	MOV DL,space
	INT 21H
	
	;print a new line
	MOV AH, 2
	MOV DL, 0AH
	INT 21H
	MOV DL, 0DH
	INT 21H
	
	;output numbers
	MOV AH,9
	LEA DX, number_
	INT 21H
	
	MOV AH, 2
	MOV DL,num
	INT 21H
	
	MOV AH, 4CH
	INT 21H

	MOV AH,4CH

MAIN ENDP
END MAIN

