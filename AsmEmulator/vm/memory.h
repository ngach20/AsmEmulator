#include "../defines.h"

class Memory{
    public:
        Memory();
        void store(short val, unsigned short addr);
        short load(unsigned short addr);

    private:
        char mem[MEMORY_SIZE];
};
