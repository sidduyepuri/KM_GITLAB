DATE: 23-SEP-2023 || TOPIC: Data transfer instructions.

1. Store/write 8 bit data 0x12 into 4000H memory location.
	METHOD 1: MVI B 12h
		  LXI H 6000h
		  MOV M B
	METHOD 2: LXI H 60000h
		  MVI M 12h
	METHOD 3: MVI A 12h
		  STA 6000h
	METHOD 4: MVI A 12h
		  LXI B 6000h
		  STAX B

2. Load 8 bit data from 4000H memory location into Accumulator.
	METHOD 1: LXI H 6000h
		  MOV A M
	METHOD 2: LDA 6000h
	METHOD 3: LXI B 6000h
		  LDAX B

3. Store 16 bit data 0x1234 into 4000H and 4001H corresponding memory locations using Little Endian format.
	METHOD 1: MVI B 34h
		  LXI H 6000h
		  MOV M B
		  MVI B 12h
		  LXI H 6000h
		  MOV M B
		  
	METHOD 2: LXI H 6000h
		  MVI M 34h
		  LXI H 6001H
		  MVI M 12H
	
	METHOD 3: MVI A 34H
		  STA 6000H
		  MVI A 12H
		  STA 6000H

	METHOD 4: MVI A 34H
		  LXI B 6000H
		  STAX B
		  MVI A 12H
		  LXI B 6000H
		  STAX B


4. Load 16 bit data from 4000H & 4001H memory locations into HL pair using Little Endian format.
	METHOD 1: LHLD 6000h

	METHOD 2: LDA 6000H
		  MOV L A
		  LDA 6001H
		  MOV H A

	METHOD 3: LXI B 6000H
		  LDAX B
		  MOV L A
		  LXI B 6001H
		  LDAX A
		  MOV H B
....................................................................
DATE: 25-SEP-2023 || TOPIC: Branch instructions

1. To Add two 8-bit numbers:
   Write an ALP to Add the contents of memory locations 4000H and 4001H and place the result in memory location 4002H.
   ALP:	LXI H 4000h
	ADD M
	INX H
	ADD M
	STA 4002h
	HLT

2. To find 2’s complement:
   Write an ALP to find the 2’s complement of a number and load number from 4000H memory location the result stored in 6000H.
   ALP:	LDA 4000h
	CMA
	INR A
	STA 6000h
	HLT

3. To find Odd No or Even No:
	Write an ALP to find if a given number is odd or even and load number in 4000H memory location the result stored in 6000H.  If even, store 22H at memory location 6000 otherwise store 11H at memory location 6000.
   ALP:	LDA 4000h
	MVI B 01h
	ANA B
	JZ EVEN
	MVI A 11h
	STA 6000h
	HLT
	EVEN: MVI A 22h
	STA 6000h
	HLT
4. To Perform Multiplication without using MUL instruction:
	Write an ALP to perform multiplication of two numbers without using MUL instruction first & second number stored in 4000H & 4001H memory locations respectively and the result stored in 6000H?
   ALP:	LDA 4000h
	MOV C A
	LDA 4001h
	MOV B A
	MVI A 00h
	MUL: ADD B
	DCR C
	JNZ MUL
	STA 6000h
	HLT

5. To Perform Division without using DIV instruction:
	Write an ALP to perform division of two numbers without using DIV instruction first & second number stored in 4000H & 4001H memory locations respectively and the result stored in 6000H?
   ALP:	LXI H 4000h
	MOV A M
	INX H
	MOV B M
	MVI C 00h
	DIV: CMP B
	JM NEG
	SUB B
	INR C
	JNZ DIV
	NEG: MOV A C
	STA 6000h
	HLT

6. To find average of 5 Numbers:
   Write an ALP average of 5 numbers, take the numbers from 4000H to 4004H location and store the result in 4005H?
   ALP:	LXI H 4000h
	MVI C 05h
	LB1: ADD M
	INX H
	DCR C
	JNZ LB1	
	MVI C 05h
	LB2: CMP C
	JM LB3
	SUB C
	INR D
	JNZ LB2
	LB3: MOV A D
	STA 4005h
	HLT
.......................................................

DATE: 26-SEP-2023 || TOPIC: Branch instructions

1. Write an ALP to blink LED every 100 msec delay. Implement delay subroutine and use CALL instruction.
   ALP:	LXI SP E358h
	LB1: MVI A 01h
	OUT 01h
	CALL LB2
	MVI A 00h
	OUT 01h
	CALL LB2
	JMP LB1
	HLT
	LB2: MVI C 05h
	LB3: NOP
	DCR C
	JNZ LB3
	RET

2. Write an ALP if there is no PUSH instruction and implement the same with two instructions which perform the same operation as PUSH B?
   ALP:	LXI H E358h
	LXI B 1234h
	SPHL
	DCX H
	MOV M B
	DCX H
	MOV M C
	SPHL
	HLT

3. Write an ALP to find the biggest of 3 numbers. And load numbers from 4000H to 4002H and store the biggest number in 6000H.
   ALP:	LXI SP E358h
	LXI H 4000h
	MVI D 80h
	MOV A M
	MVI C 02h
	LB: INX H
	MOV B M
	CALL B3
	DCR C
	JNZ LB
	STA 6000h
	HLT
	B3: CMP B
	JM LB2
	LB3: RET
	LB2: MOV A B
	JMP LB3

4. Write an ALP to find the given number is positive or negative. And load number from 4000H and store 11H if number is Negative in 6000H otherwise store 22H in 6000H.
   ALP:	LDA 4000h
	ANI 80h
	JZ POS
	MVI A 11h
	STA 6000h
	HLT
	POS: MVI A 22h
	STA 6000h
	HLT
