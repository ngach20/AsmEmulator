#include "cpu.h"
#include <cstring>

CPU::CPU(Memory& memory) : ram(memory){
    init_instr_to_func();
    memset(this->regs, 0, sizeof(short) * 128);

    pc = &(this->regs[PC]);
    sp = &(this->regs[SP]);
    rv = &(this->regs[RV]);
    jm = &(this->regs[JM]);
    
    *this->sp = MEMORY_SIZE - 2;
}



void CPU::init_instr_to_func(){
    this->instr_to_func = {
        {ALU, *execute_alu},
        {HI_BIT|ALU, *execute_alu_const},
        {LOAD, *execute_load_mem},
        {HI_BIT|LOAD, *execute_load_const},
        {STORE, *execute_store_reg},
        {HI_BIT|STORE, *execute_store_const},
        {JUMP, *execute_jump},
        {CALL, *execute_call},
        {BRANCH, *execute_branch},
        {RET, *execute_ret}
    };
}

void CPU::execute(long long int instruction){
    this->instr_to_func[(int)*(unsigned char*)&instruction](this, instruction);

    //Don't increase program counter if jump or call has occured.
    if(!(*this->jm)){
        *pc += 8;
    }else{
        *this->jm = 0;
    }
}