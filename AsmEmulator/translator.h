#include "reader.h"
#include "instruction_set.h"
#include "instruction_types.h"
#include <unordered_map>
#include <iostream>
#include <string.h>

#ifndef TRANSLATOR_DEF
#define TRANSLATOR_DEF

/* 
    Translates given assembly code into readable instructions for our custom vm.
*/
namespace Translator{
    static std::unordered_map<std::string, int> special_registers;
    static std::unordered_map<std::string, int> branch_types;
    static std::unordered_map<std::string, long long int(*)(std::string)> functions;
    static std::unordered_map<std::string, char> defines;
    static std::unordered_map<char, unsigned short> function_pc_map;

    void init_special_registers();
    void init_branch_types();
    void init_func_pointers();


    void translate(Reader& reader, Instructions& program_memory);

    long long int translate_alu(std::string instr);

    long long int translate_load(std::string instr);

    long long int translate_store(std::string instr);

    long long int translate_jump(std::string instr);

    long long int translate_call(std::string instr);

    long long int translate_branch(std::string instr);

    long long int translate_call(std::string instr);

    long long int translate_ret(std::string instr);

    void translate_define(Reader& reader, Instructions& program_memory, std::string instr);

    bool is_digit(char c);

    unsigned char get_reg_idx(std::string reg);

};

#endif