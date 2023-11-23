
TITLE : Zidane

PILE SEGMENT stack
		100 DD dup (?)
PILE ENDS

DATA SEGMENT
	 Jj DW 0
	 Ki DW 0
	 Zi DW 0
	 Bc DD 0.0
	 Xrs DD 0.0
	 Zsa DW 0
	 Tabr DD 0 DUP(2)
	 Ss DW 0
	 N DW 0
	 In DW 0
	 Srsq DW 0 DUP(3)
	 Nsa DW 0
	 Z2 DW 0
	 A DD 0.0
	 B DD 0.0
	 Ri DW 2000
	 Flti DD 0.0
	 Nri.brs DW 0
	 Nom DW 0 DUP(5)
	 X DW 0
	 Ra DD 2.5
	 Ij DW 0
	 Y DW 0
	 ssr DW 0
	 Bb DD 0.0
DATA ENDS

CODE SEGMENT
BEGIN:
		ASSUME SS: PILE, DS: DATA, CS: CODE
			Mov AX,DATA
			Mov DX,AX

			MOV AX,Zi
			MOV N,AX
			MOV AX,0
			MOV Ki,AX
			MOV AX,2
			ADD AX,2
			PUSH AX
			POP AX
			ADD AX,1
			PUSH AX
			POP AX
			MOV Y,AX
			MOV AX,Nom[3]
			MOV Y,AX
			MOV AX,2
			ADD AX,1
			PUSH AX
			POP AX
			ADD AX,3
			PUSH AX
			POP AX
			MOV Y,AX
			MOV AX,1
			MOV Y,AX
			MOV AX,(-2)
			ADD AX,4
			PUSH AX
			POP AX
			ADD AX,1
			PUSH AX
			MOV AX,4
			SUB AX,10
			PUSH AX
			POP AX
			POP BX
			MUL AX,BX
			PUSH AX
			MOV AX,3
			DIV AX,0
			PUSH AX
			POP AX
			POP BX
			SUB AX,BX
			PUSH AX
			POP AX
			MOV Y,AX
			MOV AX,Zi
			MOV BX,In
			CMP AX,BX
			JL etiq[ 31 ]
			MOV AX,55
			MOV In,AX
			MOV AX,2.5
			MOV Y,AX
			JMP etiq[ 34 ]
etiq [ 31 ] : 
			MOV AX,1.1
			MOV Y,AX
			MOV AX,2.2
			MOV Y,AX
			MOV AX,3.3
			MOV Y,AX
etiq [ 34 ] : 
			MOV AX,A
			ADD AX,1
			PUSH AX
			POP AX
			ADD AX,1
			PUSH AX
			POP AX
			ADD AX,1
			PUSH AX
			MOV AX,X
			MOV BX,Zi
			CMP AX,BX
			JLE etiq[ 52 ]
			MOV AX,Y
			MOV BX,Zi
			CMP AX,BX
			JG etiq[ 46 ]
			MOV AX,4.4
			MOV Y,AX
			MOV AX,5
			MOV X,AX
			MOV AX,6.6
			MOV Y,AX
			JMP etiq[ 48 ]
etiq [ 46 ] : 
			MOV AX,7.7
			MOV Y,AX
			MOV AX,8.8
			MOV Y,AX
etiq [ 48 ] : 
			MOV AX,9.9
			MOV Y,AX
			MOV AX,10
			MOV X,AX
			MOV AX,11.11
			MOV Y,AX
			JMP etiq[ 54 ]
etiq [ 52 ] : 
			MOV AX,12.2
			MOV Y,AX
			MOV AX,13.3
			MOV Y,AX
etiq [ 54 ] : 
			MOV AX,0
			MOV In,AX
			JMP etiq[ 57 ]
etiq [ 56 ] : 
			MOV AX,2
			ADD AX,
			PUSH AX
etiq [ 57 ] : 
			MOV AX,In
			MOV BX,N
			CMP AX,BX
			JG etiq[ 82 ]
			MOV AX,In
			ADD AX,66
			PUSH AX
			POP AX
			MOV In,AX
			MOV AX,1
			MOV Ij,AX
			JMP etiq[ 63 ]
etiq [ 62 ] : 
			MOV AX,5
			ADD AX,
			PUSH AX
etiq [ 63 ] : 
			MOV AX,Ij
			MOV BX,N
			CMP AX,BX
			JG etiq[ 81 ]
			MOV AX,Ij
			ADD AX,1
			PUSH AX
			POP AX
			MOV Ij,AX
etiq [ 66 ] : 
			MOV AX,A
			MOV BX,12
			CMP AX,BX
			JL etiq[ 80 ]
			POP AX
			ADD AX,2.5
			PUSH AX
			MOV AX,3
			MOV X,AX
etiq [ 71 ] : 
			MOV AX,(+4)
			ADD AX,1
			PUSH AX
			POP AX
			MOV BX,12
			CMP AX,BX
			JL etiq[ 78 ]
			MOV AX,Bb
			ADD AX,2.5
			PUSH AX
			MOV AX,6
			MOV X,AX
			JMP etiq[ 71 ]
etiq [ 78 ] : 
			MOV AX,667
			MOV X,AX
			JMP etiq[ 66 ]
etiq [ 80 ] : 
			JMP etiq[ 62 ]
etiq [ 81 ] : 
			JMP etiq[ 56 ]
etiq [ 82 ] : 
			MOV AX,Nrw.Strne
			ADD AX,2.5
			PUSH AX
			MOV AX,0
			MOV In,AX
			JMP etiq[ 88 ]
etiq [ 87 ] : 
			MOV AX,2
			ADD AX,
			PUSH AX
etiq [ 88 ] : 
			MOV AX,In
			MOV BX,Nsa
			CMP AX,BX
			JG etiq[ 115 ]
			MOV AX,1
			MOV X,AX
			MOV AX,In
			ADD AX,2
			PUSH AX
			MOV AX,2
			MOV Ij,AX
			JMP etiq[ 95 ]
etiq [ 94 ] : 
			MOV AX,4
			ADD AX,
			PUSH AX
etiq [ 95 ] : 
			MOV AX,Ij
			MOV BX,Nsa
			CMP AX,BX
			JG etiq[ 114 ]
			MOV AX,3
			MOV X,AX
			MOV AX,Ij
			ADD AX,2
			PUSH AX
			MOV AX,Y
			MOV BX,Zi
			CMP AX,BX
			JG etiq[ 111 ]
			MOV AX,4.4
			MOV Y,AX
			MOV AX,5
			MOV X,AX
etiq [ 102 ] : 
			MOV AX,(+4)
			ADD AX,1
			PUSH AX
			POP AX
			MOV BX,12
			CMP AX,BX
			JL etiq[ 109 ]
			POP AX
			ADD AX,2.5
			PUSH AX
			MOV AX,6
			MOV X,AX
			JMP etiq[ 102 ]
etiq [ 109 ] : 
			MOV AX,6.6
			MOV Y,AX
			JMP etiq[ 113 ]
etiq [ 111 ] : 
etiq [ 113 ] : 
			JMP etiq[ 94 ]
etiq [ 114 ] : 
			JMP etiq[ 87 ]
etiq [ 115 ] : 
etiq [ 115 ] : 
			MOV AX,(+4)
			ADD AX,1
			PUSH AX
			POP AX
			CMP AX,0
			JE etiq[ 118 ]
			MOV AX,Zi
			CMP AX,0
			JE etiq[ 118 ]
etiq [ 118 ] : 
etiq [ 118 ] : 
			JMP etiq[ 126 ]
			POP AX
			ADD AX,2.5
			PUSH AX
			MOV AX,1
			MOV X,AX
			MOV AX,1
			MOV X,AX
			MOV AX,1
			MOV X,AX
			JMP etiq[ 115 ]
etiq [ 126 ] : 
etiq [ 126 ] : 
			MOV AX,1
			ADD AX,1
			PUSH AX
			MOV AX,8.8
			ADD AX,2
			PUSH AX
			POP AX
			CMP AX,0
			JE etiq[ 130 ]
			POP AX
			CMP AX,0
			JE etiq[ 130 ]
etiq [ 130 ] : 
etiq [ 130 ] : 
			JMP etiq[ 135 ]
			MOV AX,X
			CMP AX,0
			JNE etiq[ 133 ]
			JMP etiq[ 133 ]
etiq [ 133 ] : 
etiq [ 133 ] : 
			JMP etiq[ 126 ]
CODE ENDS
END BEGIN
