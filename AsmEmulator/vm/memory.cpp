#include "memory.h"
#include <iostream>
#include <string.h>

Memory::Memory(){
    memset(this->mem, 0, sizeof(char) * MEMORY_SIZE);
}

void Memory::store(short val, unsigned short addr){
    if(addr % 2 != 0 || addr >= MEMORY_SIZE){
        std::cerr << "Invalid memory location" << std::endl;
        exit(-1);
    }

    memory_lock.lock();
    ((short*)this->mem)[addr/2] = val;
    memory_lock.unlock();
}

short Memory::load(unsigned short addr){
     if(addr % 2 != 0 || addr >= MEMORY_SIZE){
        std::cerr << "Invalid memory location" << std::endl;
        exit(-1);
    }

    memory_lock.lock();
    short res = ((short*)this->mem)[addr/2];
    memory_lock.unlock();
    
    return res;
}