#include "translator.h"


void Translator::init_special_registers(){
    special_registers = {
        {"SP", SP},
        {"RV", RV},
        {"PC", PC}
    };
}

void Translator::init_branch_types(){
    branch_types = {
        {"BLT", BLT},
        {"BLE", BLE},
        {"BEQ", BEQ},
        {"BNE", BNE},
        {"BGT", BGT},
        {"BGE", BGE}
    };
}

void Translator::init_func_pointers(){
    functions = {
        {"ALU", *translate_alu},
        {"LOAD", *translate_load},
        {"STORE", *translate_store},
        {"JUMP", *translate_jump},
        {"CALL", *translate_call},
        {"BRANCH", *translate_branch},
        {"CALL", *translate_call}
    };
}



void Translator::translate(Reader& reader, Instructions& program_memory){
    init_special_registers();
    init_branch_types();
    init_func_pointers();   

    while(reader.has_next()){
        std::string cur_instr = reader.next_line();

        if(cur_instr == "RET"){
            program_memory.add_instruction(RET, false);
            continue;
        }

        int space_idx = cur_instr.find(' ');
        std::string cmd = cur_instr.substr(0, space_idx);

        if(cmd == "DEFINE"){
            translate_define(reader, program_memory, cur_instr.substr(space_idx + 1));
        }else{
            long long int operation = functions[cmd](cur_instr.substr(space_idx + 1));
            program_memory.add_instruction(operation, false);
        }
    }
}

long long int Translator::translate_alu(std::string instr){
    long long int res = 0;
    int eq_idx = instr.find('=');
    
    // e.g.: R1=4+R4
    if(is_digit(instr.at(3))){
        char dest_reg_idx = get_reg_idx(instr.substr(0, 2));
        int constant = std::stoi(instr.substr(eq_idx + 1));

        char reg = get_reg_idx(instr.substr(instr.size() - 2, 2));

        alu_const* operation = (alu_const*)&res;
        operation->constant = (short)constant;
        operation->left_const = 1;
        operation->instr = HI_BIT | ALU;
        operation->dest_reg = dest_reg_idx;
        operation->reg = reg;
        operation->op = instr.at(instr.size() - 3);
    }else{
        // e.g.: R1=R2*R3
        if(instr.size() == 8){
            char dest_reg_idx = get_reg_idx(instr.substr(0, 2));
            char reg1 = get_reg_idx(instr.substr(3, 2));
            char reg2 = get_reg_idx(instr.substr(6, 2));

            alu* operation = (alu*)&res;
            operation->instr = ALU;
            operation->dest_reg = dest_reg_idx;
            operation->reg1 = reg1;
            operation->reg2 = reg2;
            operation->op = instr.at(5);
        }else if(instr.size() == 7){ //e.g.: R1=R2*2
            char dest_reg_idx = get_reg_idx(instr.substr(0, 2));
            int constant = std::stoi(instr.substr(6));

            char reg = get_reg_idx(instr.substr(eq_idx + 1, 2));

            alu_const* operation = (alu_const*)&res;
            operation->instr = HI_BIT | ALU;
            operation->constant = (short)constant;
            operation->left_const = 0;
            operation->dest_reg = dest_reg_idx;
            operation->reg = reg;
            operation->op = instr.at(instr.size() - 2);
        }else if(instr.size() == 5){
            char dest_reg_idx = get_reg_idx(instr.substr(0, 2));
            char reg = get_reg_idx(instr.substr(eq_idx + 1, 2));

            alu_const* operation = (alu_const*)&res;
            operation->instr = HI_BIT | ALU;
            operation->constant = 0;
            operation->left_const = 0;
            operation->dest_reg = dest_reg_idx;
            operation->reg = reg;
            operation->op = '+';
        }
    }

    return res;
}

long long int Translator::translate_load(std::string instr){
    char dest_reg_idx = get_reg_idx(instr.substr(0, 2));
    int eq_idx = instr.find('=');
    long long int res = 0;


    if(instr.at(eq_idx + 1) == 'M'){
        int opening_bracket_idx = instr.find('[');
        int reg = get_reg_idx(instr.substr(opening_bracket_idx + 1, 2));
        int offset = 0;

        if(instr.find('+') != std::string::npos){
            offset = std::stoi(instr.substr(opening_bracket_idx + 4));
        }else if(instr.find('-') != std::string::npos){
            offset = -std::stoi(instr.substr(opening_bracket_idx + 4));
        }
        load_memory* operation = (load_memory*)&res;
        operation->instr = LOAD;
        operation->dest_reg = dest_reg_idx;
        operation->addr_reg = reg;
        operation->offset = (short)offset;
    }else{
        int constant = std::stoi(instr.substr(eq_idx + 1));
        load_const* operation = (load_const*)&res;
        operation->instr = HI_BIT | LOAD;
        operation->constant = constant;
        operation->dest_reg = dest_reg_idx;
    }

    return res;
}

long long int Translator::translate_store(std::string instr){
    long long int res = 0;
    
    char addr_reg = get_reg_idx(instr.substr(2, 2));
    int offset = 0;
    
    if(instr.find('+') != std::string::npos){
        offset = stoi(instr.substr(5));
    }else if(instr.find('-') != std::string::npos){
        offset = -stoi(instr.substr(5));
    }

    int eq_idx = instr.find('=');

    if(is_digit(instr.at(eq_idx + 1))){
        store_const* operation = (store_const*)&res;
        operation->instr = HI_BIT | STORE;
        operation->addr_reg = addr_reg;
        operation->offset = offset;
        operation->constant = (short)stoi(instr.substr(eq_idx + 1));
    }else{
        store_register* operation = (store_register*)&res;
        char source_reg = get_reg_idx(instr.substr(eq_idx + 1, 2));
        operation->instr = STORE;
        operation->offset = offset;
        operation->addr_reg = addr_reg;
        operation->source_reg = source_reg;
    }

    return res;
}

long long int Translator::translate_jump(std::string instr){
    long long int res = 0;
    char addr_reg = get_reg_idx(instr.substr(0, 2));
    jump* operation = (jump*)&res;
    
    operation->instr = JUMP;
    operation->addr_reg = addr_reg;

    short offset = 0;
    if(instr.find('+') != std::string::npos){
        offset = stoi(instr.substr(3));
    }else if(instr.find('-') != std::string::npos){
        offset = -stoi(instr.substr(3));
    }

    operation->offset = offset;

    return res;
}

long long int Translator::translate_call(std::string instr){
    long long int res = 0;

    char func_idx = defines[instr];

    call* operation = (call*)&res;
    operation->instr = CALL;
    operation->func_idx = func_idx;

    return res;
}

long long int Translator::translate_ret(std::string instr){
    return RET;
}

//e.g.: BNE R2, R1, PC+16 
long long int Translator::translate_branch(std::string instr){
    long long int res = 0;

    std::string type = instr.substr(0, 3);
    std::string reg1 = instr.substr(4, 2);
    std::string reg2 = instr.substr(8, 2);
    std::string reg3 = instr.substr(12, 2);
    int offset = 0;

    int plus_idx = instr.find('+');
    int minus_idx = instr.find('-');
    if(plus_idx != std::string::npos){
        offset = std::stoi(instr.substr(plus_idx + 1)); 
    }else if(minus_idx != std::string::npos){
        offset = -std::stoi(instr.substr(minus_idx + 1)); 
    }

    branch* operation = (branch*)&res;
    operation->instr = BRANCH;
    operation->branch_type = branch_types[type];
    operation->reg1 = get_reg_idx(reg1);
    operation->reg2 = get_reg_idx(reg2);
    operation->reg3 = get_reg_idx(reg3);
    operation->offset = offset;

    return res;
}

void Translator::translate_define(Reader& reader, Instructions& program_memory, std::string func_name){
    char fun_idx = program_memory.add_function_define();
    defines[func_name] = fun_idx;

    while(reader.has_next()){
        std::string cur_instr = reader.next_line();

        if(cur_instr == "RET"){
            program_memory.add_instruction(RET, true);
            continue;
        }

        if(cur_instr == "END"){
            return;
        }else{
            int space_idx = cur_instr.find(' ');
            std::string cmd = cur_instr.substr(0, space_idx);
            long long int operation = functions[cmd](cur_instr.substr(space_idx + 1));
            program_memory.add_instruction(operation, true);
        }
    }
}

bool Translator::is_digit(char c){
    return ((c - '0') >= 0 && (c - '0') <= 9);
}

unsigned char Translator::get_reg_idx(std::string reg){
    if(is_digit(reg.at(1))){ //R* register where * is some digit
        const char dig = reg.at(1);
        return dig - '0';
    }else{
        return special_registers[reg];
    }
}