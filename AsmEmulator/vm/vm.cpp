#include "vm.h"
#include <iostream>
#include <iomanip>
#include <thread>

VM::VM(Instructions& instr) : program(instr), cpu(this->ram), screen(this->ram){
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
    bool program_on = true;

    long long int instruction = this->program.get_instruction(this->cpu.get_regs()[PC]);

    std::thread output_thread ([&] (Screen * scr) {
            scr->update_display();
        }, 
        &this->screen);

    std::thread input_thread ([&] (Screen * scr) {
            scr->get_input(&program_on);
        }, 
        &this->screen);

    while(instruction != 0 && program_on){
        this->cpu.execute(instruction);

        instruction = this->program.get_instruction(this->cpu.get_regs()[PC]);
    }

    output_thread.join();
    input_thread.join();
}