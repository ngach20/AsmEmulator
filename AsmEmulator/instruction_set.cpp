#include "instruction_set.h"
#include <iostream>

Instructions::Instructions(){
    this->instructions = (char*)malloc(PROGRAM_SIZE/2);
    this->defines = (char*)malloc(PROGRAM_SIZE/2);
    memset((void*)this->instructions, 0, PROGRAM_SIZE/2);
    memset((void*)this->defines, 0, PROGRAM_SIZE/2);

    this->cur_instruction = this->instructions;
    this->cur_define = this->defines;

    this->cur_function_number = 0;
}

void Instructions::add_instruction(unsigned long long int instruction, bool defined){
    char** cur_ptr;

    cur_ptr = defined ? &this->cur_define : &this->cur_instruction;


    **(unsigned long long int**)cur_ptr = instruction;
    *cur_ptr += sizeof(unsigned long long int);
}

char Instructions::add_function_define(){
    this->function_address_map[this->cur_function_number] = this->cur_define;

    return this->cur_function_number++;
}

unsigned short Instructions::get_function_pc(int func_idx){
    char* func_ptr = this->function_address_map[func_idx];

    return PROGRAM_SIZE/2 + (func_ptr - this->defines);
}

long long int Instructions::get_instruction(unsigned short pc){
    if(pc >= PROGRAM_SIZE){
        std::cerr << "Invalid program address" << std::endl;
        return 0;
    }

    if(pc < PROGRAM_SIZE/2){
        return ((long long int*)this->instructions)[pc/8];
    }else{
        return ((long long int*)this->defines)[(pc%(PROGRAM_SIZE/2))/8];
    }
}


Instructions::~Instructions(){
    free(this->instructions);
    free(this->defines);
}