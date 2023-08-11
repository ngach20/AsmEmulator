cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_BUILD_TYPE "Debug")
project(asm_emulator)


set(CMAKE_CXX_STANDARD 17)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )


add_executable(interpreter AsmEmulator/main.cpp
                           AsmEmulator/defines.h 
                           AsmEmulator/instruction_set.h 
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
                           AsmEmulator/vm/screen.h
                           AsmEmulator/vm/screen.cpp
)   

target_link_libraries( interpreter ${CURSES_LIBRARIES} )