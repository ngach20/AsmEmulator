#include "vm.h"
#include <iostream>
#include <iomanip>

VM::VM(Instructions& instr) : program(instr), cpu(this->ram){
}

void VM::print_stack(short num_lines){
    std::cout << "========================" << '\n';
    std::cout << "| " << "ADDRESS" << std::setw(6) << "| " << "VALUE" << std::setw(4) << '|' << '\n';
    std::cout << "========================" << std::endl;
    for(unsigned short i = (MEMORY_SIZE - 2); i >= (MEMORY_SIZE - (num_lines * 2)); i -= 2){
        std::cout << "| " << std::setw(6) << "0x" << std::hex << i << " |";
        std::cout << " " << std::setw(7) << std::dec << (short)this->ram.load(i) << " |";
        std::cout << std::endl;
    }
    std::cout << "========================" << std::endl;
}

void VM::run(){
    long long int instruction = this->program.get_instruction(this->cpu.get_regs()[PC]);

    while(instruction != 0){
        this->cpu.execute(instruction);

        instruction = this->program.get_instruction(this->cpu.get_regs()[PC]);
    }
}