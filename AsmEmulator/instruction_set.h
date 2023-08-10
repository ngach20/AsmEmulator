#include <cstdlib>
#include <cstring>
#include <string.h>
#include "defines.h"
#include <unordered_map>

#ifndef INSTRUCTION_SET
#define INSTRUCTION_SET

class Instructions{
    public:
        Instructions();

        void add_instruction(unsigned long long int instruction, bool defined);
        
        //Returns function number
        char add_function_define();

        //Returns function address
        unsigned short get_function_pc(int func_idx);
        
        long long int get_instruction(unsigned short pc);

        ~Instructions();

    private:
        char* instructions;
        char* defines;

        char* cur_instruction;
        char* cur_define;

        char cur_function_number;
        std::unordered_map<int, char*> function_address_map;
};


#endif