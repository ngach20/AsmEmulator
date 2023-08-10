#include "memory.h"
#include "cpu.h"
#include "../instruction_set.h"
#include "../instruction_types.h"
#include "../defines.h"
#include <iostream>

class VM{
    public:
        VM(Instructions& instr);

        void run();

        void insert_program(Instructions& program);

        void print_stack(short num_lines);

    private:
        Instructions& program;

        Memory ram;
        CPU cpu;

        void execute(long long int instruction);
};