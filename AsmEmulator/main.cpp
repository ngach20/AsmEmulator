#include <iostream>
#include "translator.h"
#include "vm/vm.h"

int main(int argc, char** argv){
    if(argc < 2){
        std::cout << "No filename provided" << std::endl;
        return -1;
    }

    static char* filename = argv[1];


    Reader reader = Reader(filename);

    Instructions instructions = Instructions();

    std::cout << "Translating " << filename << std::endl;

    Translator::translate(reader, instructions);

    std::cout << "Finished translating!" << std::endl;

    std::cout << "Executing" << std::endl;

    VM vm = VM(instructions);
    vm.run();

    std::cout << "Finished executing" << std::endl;

    std::cout << "Please input the number of memory addresses you wish to see: ";
    
    std::string num_lines_str = "";
    unsigned short num_lines = 0;
    std::getline(std::cin, num_lines_str);
    std::cout << std::endl;
    
    if(!num_lines_str.empty()){
        try{
            num_lines = std::stoi(num_lines_str);
            vm.print_stack(num_lines);
        }catch(const std::exception& e){
            std::cout << "Invalid argument" << std::endl;
            exit(-1);
        }
    }

    return 0;
}