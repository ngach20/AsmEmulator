#include "memory.h"
#include "../instruction_set.h"
#include "../instruction_types.h"
#include "../defines.h"
#include <iostream>

class VM{
    public:
        VM();

        void run();

        void insert_program(Instructions& program);

        void print_stack(short num_lines);

    private:
        std::unordered_map<int, void(*)(VM*, const long long int)> instr_to_func;
        void init_instr_to_func();

        Instructions program;

        Memory ram;

        short regs[128]; //Registers

        short* pc  = &regs[PC];   //Program Counter
        short* sp  = &regs[SP];   //Stack Pointer
        short* rv  = &regs[RV];   //Return Value

        bool jumped;

        void execute(long long int instruction);

        static void execute_alu(VM* vm, const long long int instruction){
            //std::cout << "executing alu" << std::endl;
            alu operation = *(alu*)&instruction;

            short reg1_val = vm->regs[operation.reg1];
            short reg2_val = vm->regs[operation.reg2];

            short res = alu_func(reg1_val, reg2_val, operation.op);

            vm->regs[operation.dest_reg] = res;
        }

        static void execute_alu_const(VM* vm, const long long int instruction){
            //std::cout << "executing alu_const" << std::endl;
            alu_const operation = *(alu_const*)&instruction;

            short res = 0;
            short reg_val = vm->regs[operation.reg];

            if(operation.left_const){
                res = alu_func(operation.constant, reg_val, operation.op);
            }else{
                res = alu_func(reg_val, operation.constant, operation.op);
            }

            vm->regs[operation.dest_reg] = res;
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

        static void execute_load_const(VM* vm, const long long int instruction){
            //std::cout << "executing load_const" << std::endl;
            load_const operation = *(load_const*)&instruction;
            
            vm->regs[operation.dest_reg] = operation.constant;
        }

        static void execute_load_mem(VM* vm, const long long int instruction){
            std::cout << "executing load_mem" << std::endl;
            load_memory operation = *(load_memory*)&instruction;

            short addr = vm->regs[operation.addr_reg] + operation.offset;
            vm->regs[operation.dest_reg] = vm->ram.load(addr);
        }

        static void execute_store_reg(VM* vm, const long long int instruction){
            std::cout << "executing store_reg" << std::endl;
            store_register operation = *(store_register*)&instruction;
            short addr = vm->regs[operation.addr_reg] + operation.offset;
            short val = vm->regs[operation.source_reg];
            vm->ram.store(val, addr);
        }

        static void execute_store_const(VM* vm, const long long int instruction){
            //std::cout << "executing store_const" << std::endl;
            store_const operation = *(store_const*)&instruction;

            short addr = vm->regs[operation.addr_reg] + operation.offset;
            vm->ram.store(operation.constant, addr);
        }

        static void execute_jump(VM* vm, const long long int instruction){
            std::cout << "executing execute_jump" << std::endl;
            jump operation = *(jump*)&instruction;

            short addr = vm->regs[operation.addr_reg] + operation.offset;
            *vm->pc = addr;
            vm->jumped = true;
        }
        static void execute_call(VM* vm, const long long int instruction){
            //std::cout << "executing call" << std::endl;

            call operation = *(call*)&instruction;

            int func_idx = (unsigned char)operation.func_idx;

            unsigned short pc = vm->program.get_function_pc(func_idx);
            *vm->sp -= 2;
            vm->ram.store(*vm->pc, *vm->sp);
            *vm->pc = pc;
            vm->jumped = true;
        }

        static void execute_branch(VM* vm, const long long int instruction){
            //std::cout << "executing branch" << std::endl;

            branch operation = *(branch*)&instruction;

            unsigned char b_type = operation.branch_type;

            bool res = false;

            short val1 = vm->regs[operation.reg1];
            short val2 = vm->regs[operation.reg2];

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
                unsigned short addr = vm->regs[operation.reg3] + operation.offset;
                *vm->pc = addr;
                vm->jumped = true;
            }

        }

        static void execute_ret(VM* vm, const long long int instruction){
            //std::cout << "executing ret" << std::endl;

            *vm->pc = (unsigned short)vm->ram.load(*vm->sp);
            *vm->sp += 2;
        }


};