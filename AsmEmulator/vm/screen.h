#include <ncurses.h>
#include "memory.h"
#include "../defines.h"

class Screen{
    public:
        Screen(Memory& memory);

        void update_display();

        void get_input(bool* program_on);

    private:
        WINDOW* scr;
        WINDOW* border;

        Memory& ram;

        void print_char(char c);

        bool should_exit;
};