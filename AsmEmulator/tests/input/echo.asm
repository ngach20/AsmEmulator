DEFINE PRINT
LOAD R2=M[R8]
BRANCH BEQ R8, R2, PC+24
LOAD R2=M[R8]
JUMP PC-16
STORE M[R8]=R0
RET
END
DEFINE READ
ALU SP=SP-4
LOAD R1=2
LOAD R3=10
LOAD R9=127
LOAD R4=0
LOAD R5=0
LOAD R8=0
BRANCH BEQ R2, R3, PC+168
LOAD R2=0
BRANCH BNE R2, R8, PC+24
LOAD R2=M[R1]
JUMP PC-16
STORE M[R1]=0
BRANCH BNE R2, R9, PC+32
BRANCH BEQ R5, R8, PC-56
ALU R5=R5-1
JUMP PC+40
ALU R6=R5*2
ALU R7=R0+R6
STORE M[R7]=R2
ALU R5=R5+1
STORE M[SP]=R2
STORE M[SP+2]=R0
ALU R0=R2
CALL PRINT
LOAD R2=M[SP]
LOAD R0=M[SP+2]
JUMP PC-160
ALU SP=SP+4
RET
END
ALU SP=SP-2048
ALU R0=SP
LOAD R1=0
LOAD R3=0
LOAD R4=0
LOAD R7=10
LOAD R2=0
BRANCH BNE R0, SP, PC+200
CALL READ
LOAD R1=0
LOAD R3=0
LOAD R4=0
LOAD R7=10
LOAD R0=M[SP]
BRANCH BEQ R0, R7, PC+56
CALL PRINT
ALU R3=R3+1
ALU R4=R3*2
ALU R4=SP+R4
LOAD R0=M[R4]
JUMP PC-48
LOAD R0=10
CALL PRINT
JUMP PC-176
