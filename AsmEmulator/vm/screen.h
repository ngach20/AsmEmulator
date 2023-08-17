#include <ncurses.h>
#include "memory.h"
#include "../defines.h"

class IO{
    public:
        IO(Memory& memory);

        /*
            Reads the output buffer and displays the contents to the screen.
        */
        void update_display();

        /*
            Gets the input and redirects it to the input buffer.
            Reads ESC for exit.
        */
        void get_input(bool* program_on);

    private:
        WINDOW* scr;
        WINDOW* border;

        Memory& ram;

        bool should_exit;
};