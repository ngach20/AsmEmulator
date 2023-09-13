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

    VM vm(instructions);
    vm.run();

    std::cout << "Finished executing" << std::endl;

    return 0;
}