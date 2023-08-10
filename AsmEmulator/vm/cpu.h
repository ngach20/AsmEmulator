#include "memory.h"
#include "../instruction_types.h"
#include <unordered_map>

class CPU{
    public:
        CPU(Memory& mem);

        void execute(long long int instruction);

        short* get_regs(){
            return this->regs;
        }

    private:
        std::unordered_map<int, void(*)(CPU*, const long long int)> instr_to_func;
        void init_instr_to_func();

        Memory& ram;

        short regs[128]; //Registers

        short* pc; //Program Counter
        short* sp; //Stack Pointer
        short* rv; //Return Value
        short* jm; //Jumped value

        //bool jumped;

        static void execute_alu(CPU* cpu, const long long int instruction){
            //std::cout << "executing alu" << std::endl;
            alu operation = *(alu*)&instruction;

            short reg1_val = cpu->regs[operation.reg1];
            short reg2_val = cpu->regs[operation.reg2];

            short res = alu_func(reg1_val, reg2_val, operation.op);

            cpu->regs[operation.dest_reg] = res;
        }

        static void execute_alu_const(CPU* cpu, const long long int instruction){
            //std::cout << "executing alu_const" << std::endl;
            alu_const operation = *(alu_const*)&instruction;

            short res = 0;
            short reg_val = cpu->regs[operation.reg];

            if(operation.left_const){
                res = alu_func(operation.constant, reg_val, operation.op);
            }else{
                res = alu_func(reg_val, operation.constant, operation.op);
            }

            cpu->regs[operation.dest_reg] = res;
        }

        static short alu_func(short val1, short val2, char op){
            short res = 0;
            switch (op)
            {
                case '+':
                    res = val1 + val2;
                    break;
                case '*':
                    res = val1 * val2;
                    break;
                case '-':
                    res = val1 - val2;
                    break;
                case '/':
                    res = val1 / val2;
                    break;
                default:
                    break;
            }

            return res;
        }

        static void execute_load_const(CPU* cpu, const long long int instruction){
            //std::cout << "executing load_const" << std::endl;
            load_const operation = *(load_const*)&instruction;
            
            cpu->regs[operation.dest_reg] = operation.constant;
        }

        static void execute_load_mem(CPU* cpu, const long long int instruction){
            //std::cout << "executing load_mem" << std::endl;
            load_memory operation = *(load_memory*)&instruction;

            short addr = cpu->regs[operation.addr_reg] + operation.offset;
            cpu->regs[operation.dest_reg] = cpu->ram.load(addr);
        }

        static void execute_store_reg(CPU* cpu, const long long int instruction){
            //std::cout << "executing store_reg" << std::endl;
            store_register operation = *(store_register*)&instruction;
            short addr = cpu->regs[operation.addr_reg] + operation.offset;
            short val = cpu->regs[operation.source_reg];
            cpu->ram.store(val, addr);
        }

        static void execute_store_const(CPU* cpu, const long long int instruction){
            //std::cout << "executing store_const" << std::endl;
            store_const operation = *(store_const*)&instruction;

            short addr = cpu->regs[operation.addr_reg] + operation.offset;
            cpu->ram.store(operation.constant, addr);
        }

        static void execute_jump(CPU* cpu, const long long int instruction){
            //std::cout << "executing execute_jump" << std::endl;
            jump operation = *(jump*)&instruction;

            short addr = cpu->regs[operation.addr_reg] + operation.offset;
            *cpu->pc = addr;
            *cpu->jm = 1;
        }

        static void execute_call(CPU* cpu, const long long int instruction){
            //std::cout << "executing call" << std::endl;

            call operation = *(call*)&instruction;

            unsigned short pc = operation.func_addr;

            *cpu->sp -= 2;
            cpu->ram.store(*cpu->pc, *cpu->sp);
            *cpu->pc = pc;
            *cpu->jm = 1;
        }

        static void execute_branch(CPU* cpu, const long long int instruction){
            //std::cout << "executing branch" << std::endl;

            branch operation = *(branch*)&instruction;

            unsigned char b_type = operation.branch_type;

            bool res = false;

            short val1 = cpu->regs[operation.reg1];
            short val2 = cpu->regs[operation.reg2];

            if(b_type&BLT){
                res = (val1 < val2);
            }else if(b_type&BLE){
                res = (val1 <= val2);
            }else if(b_type&BEQ){
                res = (val1 == val2);
            }else if(b_type&BNE){
                res = (val1 != val2);
            }else if(b_type&BGT){
                res = (val1 > val2);
            }else if(b_type&BGE){
                res = (val1 >= val2);
            }

            if(res){
                unsigned short addr = cpu->regs[operation.reg3] + operation.offset;
                *cpu->pc = addr;
                *cpu->jm = 1;
            }

        }

        static void execute_ret(CPU* cpu, const long long int instruction){
            //std::cout << "executing ret" << std::endl;

            *cpu->pc = (unsigned short)cpu->ram.load(*cpu->sp);
            *cpu->sp += 2;
        }
};