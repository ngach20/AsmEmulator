cmake_minimum_required(VERSION 3.0.0)
project(asm_emulator)

set(CMAKE_CXX_STANDARD 17)


add_executable(interpreter AsmEmulator/main.cpp
                           AsmEmulator/defines.h 
                           AsmEmulator/instruction_set.h 
                           AsmEmulator/interpreter.exe 
                           AsmEmulator/reader.cpp 
                           AsmEmulator/translator.h 
                           AsmEmulator/instruction_set.cpp 
                           AsmEmulator/instruction_types.h 
                           AsmEmulator/reader.h 
                           AsmEmulator/translator.cpp
                           AsmEmulator/vm/vm.h
                           AsmEmulator/vm/vm.cpp
                           AsmEmulator/vm/cpu.h
                           AsmEmulator/vm/cpu.cpp
                           AsmEmulator/vm/memory.h
                           AsmEmulator/vm/memory.cpp
)   