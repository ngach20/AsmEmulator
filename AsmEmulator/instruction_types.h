#ifndef INSTRUCTION_TYPES
#define INSTRUCTION_TYPES

struct alu{
    char instr;
    char reg1;
    char reg2;
    char op;
    char dest_reg;
};

struct alu_const{
    char instr;
    char dest_reg;
    short constant;
    char op;
    char reg;
    char left_const; //If const is to the left left_const = 1 else 0
};

struct load_memory{
    char instr;
    char dest_reg;
    char addr_reg;
    short offset;
};

struct load_const{
    char instr;
    char dest_reg;
    short constant;
};

struct store_register{
    char instr;
    char source_reg;
    char addr_reg;
    short offset;
};

struct store_const{
    char instr;
    short constant;
    char addr_reg;
    short offset;
};

struct jump{
    char instr;
    char addr_reg;
    short offset;
};

struct call{
    char instr;
    char func_idx;
};

struct branch{
    char instr;
    char branch_type;
    char reg1;
    char reg2;
    char reg3;
    short offset;
};

#endif