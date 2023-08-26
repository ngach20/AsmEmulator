#include <ncurses.h>
#include <mutex>
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
        
        WINDOW* ram_scr;
        WINDOW* ram_scr_bord;
        int ram_view_scroll;

        WINDOW* inp;

        Memory& ram;

        bool should_exit;

        int focus;
        int _focus;

        void display_mem();

        std::mutex screen_lock; 
};