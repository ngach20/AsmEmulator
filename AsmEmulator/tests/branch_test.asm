LOAD R1=4
LOAD R2=5
BRANCH BLE R1, R2, PC+16
STORE M[SP-2]=R1
STORE M[SP]=R2
BRANCH BGT R1, R2, PC+16
STORE M[SP-4]=10
STORE M[SP-6]=17
BRANCH BLT R1, R2, PC+16
STORE M[SP-8]=66
STORE M[SP-10]=67
BRANCH BNE R1, R2, PC+16
STORE M[SP-8]=9
STORE M[SP-12]=77
LOAD R1=10
BRANCH BEQ R1, R1, PC+24
STORE M[SP-8]=9
STORE M[SP-12]=755
STORE M[SP-14]=65520