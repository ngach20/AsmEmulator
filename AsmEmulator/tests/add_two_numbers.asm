DEFINE ADD_TWO_NUMS
LOAD R1=M[SP+2]
LOAD R2=M[SP+4]
ALU R3=R1+R2
ALU RV=R3
RET
END
ALU SP=SP-4
STORE M[SP]=17
STORE M[SP+2]=15
CALL ADD_TWO_NUMS
ALU SP=SP+4
STORE M[SP]=RV
