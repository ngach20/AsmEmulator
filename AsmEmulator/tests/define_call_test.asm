DEFINE FUNC1
LOAD R1=70
ALU SP=SP-2
STORE M[SP]=R1
ALU SP=SP+2
RET
END
DEFINE FUNC2
ALU SP=SP-4
LOAD R1=M[SP+2]
ALU R1=R1*2
STORE M[SP]=R1
ALU SP=SP+4
RET
END
CALL FUNC1
CALL FUNC2