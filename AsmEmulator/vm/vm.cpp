#include "vm.h"
#include <iostream>
#include <iomanip>

VM::VM(){
    init_instr_to_func();
    this->jumped = false;
    memset(this->regs, 0, sizeof(char) * 128);
    *this->sp = MEMORY_SIZE - 2;
}

void VM::print_stack(short num_lines){
    std::cout << "========================" << '\n';
    std::cout << "| " << "ADDRESS" << std::setw(6) << "| " << "VALUE" << std::setw(4) << '|' << '\n';
    std::cout << "========================" << std::endl;
    for(unsigned short i = (MEMORY_SIZE - 2); i >= (MEMORY_SIZE - (num_lines * 2)); i -= 2){
        //std::string num = std::to_string((short)this->ram.load(i));
        std::cout << "| " << std::setw(10) << i << " |";
        std::cout << " " << std::setw(7) << (short)this->ram.load(i) << " |";
        std::cout << std::endl;
    }
    std::cout << "========================" << std::endl;
}

void VM::init_instr_to_func(){
    instr_to_func = {
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

void VM::insert_program(Instructions& program){
    this->program = program;
}

void VM::run(){
    long long int instruction = this->program.get_instruction(*pc);

    while(instruction != 0){
        instr_to_func[(int)*(unsigned char*)&instruction](this, instruction);
        //Don't increase program counter if jump or call has occured.
        if(!jumped){
            *pc += 8;
        }else{
            jumped = false;
        }

        instruction = this->program.get_instruction(*pc);
    }
}