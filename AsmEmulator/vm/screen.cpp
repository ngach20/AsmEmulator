#include "screen.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

IO::IO(Memory& memory) : ram(memory){
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    this->border = newwin(SCREEN_HEIGHT + 2, SCREEN_WIDTH + 2, 5, 5);
    this->scr = newwin(SCREEN_HEIGHT, SCREEN_WIDTH, 6, 6);
    
    this->ram_scr_bord = newwin(SCREEN_HEIGHT + 2, 7 + 7 + 1 + 2, 5, 80);
    this->ram_scr  = newwin(SCREEN_HEIGHT, 7 + 7 + 1, 6, 81);

    this->inp = newwin(1, 1, 0, 0);

    refresh();
    wborder(this->border, '|', '|', '=', '=', '+', '+', '+', '+');
    wborder(this->ram_scr_bord, '|', '|', '=', '=', '+', '+', '+', '+');
    wrefresh(this->border);
    wrefresh(this->scr);
    wrefresh(this->ram_scr_bord);
    wrefresh(this->ram_scr);
    wrefresh(this->inp);
    
    scrollok(this->scr, true);

    this->should_exit = false;

    this->focus = 0;
    this->_focus = 0;

    this->ram_view_scroll = 0;

    display_mem();
}

void IO::update_display(){
    wmove(this->scr, 0, 0);  
    while(1){
        if(this->focus.load() == 0){
            wborder(this->border, '|', '|', '=', '=', '+', '+', '+', '+');
            wrefresh(this->border);
            while(this->focus.load() == 0){
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
                    }else{
                        waddch(this->scr, c);
                    }
                    wrefresh(this->scr);

                    //Reset output buffer
                    this->ram.store(0, OUT_ADDR);

                }
                display_mem();
            }
        }

        if(this->focus.load() == 1){
            wborder(this->ram_scr_bord, '|', '|', '=', '=', '+', '+', '+', '+');
            wrefresh(this->ram_scr_bord);
            while(this->focus.load() == 1){
                display_mem();
            }
        }

        while(focus.load() == -1){
            if(should_exit.load()){
                delwin(this->scr);
                delwin(this->border);
                delwin(this->ram_scr);
                delwin(this->ram_scr_bord);
                endwin();
                return;
            }

            if(this->_focus.load() == 0){
                wborder(this->border, '#', '#', '#', '#', '#', '#', '#', '#');
                wborder(this->ram_scr_bord, '|', '|', '=', '=', '+', '+', '+', '+');
            }else{
                wborder(this->border, '|', '|', '=', '=', '+', '+', '+', '+');
                wborder(this->ram_scr_bord, '#', '#', '#', '#', '#', '#', '#', '#');
            }

            overwrite(this->scr, this->border);
            overwrite(this->ram_scr, this->ram_scr_bord);
            wrefresh(this->border);
            wrefresh(this->ram_scr_bord);
        }
    }
}

void IO::get_input(std::atomic_bool *program_on){
    int c;
    std::string num = "";
    while(1){
        if(this->focus.load() == 0){
            while(1){
                c = wgetch(this->inp);

                if(c == ERR){
                    this->ram.store(0, IN_ADDR);
                }
                else if(c == 27){ //ESC
                    this->focus = -1;
                    break;
                }
                else{
                    //Sleep for some time if the buffer is not yet cleared
                    if(this->ram.load(IN_ADDR) != 0){
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    }
                    this->ram.store(c, IN_ADDR);
                }
            }
        }else if(this->focus.load() == 1){
            while(1){
                c = wgetch(this->inp);

                if(c == 27){ //ESC
                    num = "";
                    focus = -1;
                    break;
                }else if(c == 'j'){
                    if(this->ram_view_scroll.load() > 0){
                        this->ram_view_scroll -= 2;
                    }

                    num = "";
                }else if(c == 'k'){
                    if(this->ram_view_scroll.load() < MEMORY_SIZE - SCREEN_HEIGHT * 2){
                        this->ram_view_scroll += 2;
                    }

                    num = "";
                }else if (c >= '0' && c <= 'z'){
                    num += (char)c;
                }else if(c == '\n'){
                    int addr = 0;
                    
                    //Get the hex string and convert it into an integer
                    try{
                        addr = std::stoi(num, nullptr, 16);
                    }catch(std::exception e){
                        addr = 0;
                    }

                    if(addr > MEMORY_SIZE - SCREEN_HEIGHT * 2){
                        addr = MEMORY_SIZE - SCREEN_HEIGHT * 2;
                    }

                    this->ram_view_scroll = addr;
                    num = "";
                }
            }
        }

        c = wgetch(this->inp);

        if(c == 27){
            break;
        }
        else if(c == 'j'){
            _focus = (2 + (_focus.load() - 1) % 2) % 2;
        }else if (c == 'k'){
            _focus = (2 + (_focus.load() + 1) % 2) % 2;
        }else if (c == '\n'){
            this->focus = _focus.load();
        }
    }

    should_exit = true;
    program_on->store(false);
}

void IO::display_mem(){
    wmove(this->ram_scr, 0, 0);
    for(int i = ram_view_scroll.load(); i < ram_view_scroll.load() + SCREEN_HEIGHT * 2; i+=2){
        wprintw(this->ram_scr, "0x%04X | 0x%04X", i, (unsigned short)this->ram.load(i));
    }

    wrefresh(this->ram_scr);
}