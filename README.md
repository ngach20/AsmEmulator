# AsmEmulator
Created based on the Programming Paradigms course.
Translates and emulates a custom ASM program.

## Assembly Instructions
### Store to memory
Storing register: STORE M[ADDR+OFFST]=REG
Storing constant: STORE M[ADDR+OFFST]=CONST
### Load to register
Load from memory: LOAD REG=M[ADDR+OFFST]
Load constant: LOAD REG=CONST
### Arithmetic instruction
Operation with two registers: ALU REG1=REG2opREG3
Operation with a register and a constant: ALU REG1=REG2opCONST, ALU REG1=CONSTopREG2
Copy register value: REG1=REG2
### Branching
BRANCH COND REG1, REG2, REG3+OFFST
Available conditions: BGT, BGE, BEQ, BNE, BLT, BLE
Note: BRANCH jumps to address stored in REG3 if COND REG1, REG2 succeeds. (REG3 should generally be PC register).
### Jumping
Unconditional jump: JUMP REG+OFFST
### Calling
CALL FUNC_NAME
Jumps to the beginning of FUNC_NAME function
Calling a function saves the current PC on the stack
### Return
RET
Jumps to the instruction after last CALL
Old PC is extracted from the stack

## Defining a function
Function can be defined with DEFINE FUNC_NAME. It can be called only after its definition.
Recursive calls are supported.

## Supported registers
Special registers: PC -> Program Counter, SP -> Stack Pointer, RV -> Return Value.
General purpose registers: R1 through R9.