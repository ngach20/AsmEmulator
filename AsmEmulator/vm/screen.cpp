#include "screen.h"
#include <iostream>
#include <thread>
#include <chrono>

IO::IO(Memory& memory) : ram(memory){
    initscr();
    noecho();
    cbreak();

    WINDOW* win = newwin(SCREEN_HEIGHT, SCREEN_WIDTH, 1, 1);
    WINDOW* bord = newwin(SCREEN_HEIGHT + 2, SCREEN_WIDTH + 2, 0, 0);

    wborder(bord, '|', '|', '=', '=', '+', '+', '+', '+');
    refresh();
    wrefresh(bord);
    wrefresh(win);
    
    scrollok(win, true);
    
    this->scr = win;
    this->border = bord;

    this->should_exit = false;
}

void IO::update_display(){
    wmove(this->scr, 0, 0);
    while(1){
        char c = this->ram.load(OUT_ADDR);

        if(c != 0){
            //Different terminals use different backspace codes?
            if(c == '\b' || c == KEY_BACKSPACE || c == 127){
                if(getcurx(this->scr) == 0){
                    if(getcury(this->scr) != 0){
                        wmove(this->scr, getcury(this->scr) - 1, SCREEN_WIDTH - 1);
                    }
                }else{
                    wmove(this->scr, getcury(this->scr), getcurx(this->scr) - 1);
                }

                wdelch(this->scr);
                //Sleep because I can't seem to fix buffering problems
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }else{
                waddch(this->scr, c);
            }
        }

        //Reset output buffer
        this->ram.store(0, OUT_ADDR);

        wrefresh(this->scr);

        if(should_exit){
            delwin(this->scr);
            delwin(this->border);
            endwin();
            break;
        }
    }
}

void IO::get_input(bool* program_on){
    while(1){
        char c = wgetch(this->scr);

        if(c == ERR){
            this->ram.store(0, IN_ADDR);
        }
        else if(c == 27){ //ESC
            break;
        }
        else{
            this->ram.store(c, IN_ADDR);
        }
    }

    should_exit = true;
    *program_on = false;
}