#include <ncurses.h>
#include <mutex>
#include <atomic>
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
        void get_input(std::atomic_bool* program_on);

    private:
        WINDOW* scr;
        WINDOW* border;
        
        WINDOW* ram_scr;
        WINDOW* ram_scr_bord;

        WINDOW* inp;

        Memory& ram;

        //Shared resources
        std::atomic_bool should_exit;
        std::atomic_int focus;
        std::atomic_int _focus;
        std::atomic_int ram_view_scroll;

        void display_mem(); 
};