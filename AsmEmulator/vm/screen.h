#include "memory.h"
#include "../defines.h"

class Screen{
    public:
        Screen(Memory& memory);

        void update_display();

        void remove_display();

    private:
        Memory& ram;

        char display[SCREEN_HEIGHT][SCREEN_WIDTH];
};