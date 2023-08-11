#include "screen.h"
#include <iostream>
#include <ncurses.h>

Screen::Screen(Memory& memory) : ram(memory){
    initscr();
    wresize(stdscr, SCREEN_HEIGHT + 2, SCREEN_WIDTH + 2);
}

void Screen::update_display(){
    wprintw(stdscr, "%s", "+");
    wprintw(stdscr, "%s", std::string(SCREEN_WIDTH,'=').c_str());
    wprintw(stdscr, "%s", "+");
    for(int i = SCREEN_START; i < SCREEN_START + SCREEN_HEIGHT*SCREEN_WIDTH*2; i+=2){
        unsigned short x = (i % (SCREEN_WIDTH * 2)) / 2;
        unsigned short y = ((i - SCREEN_START) / SCREEN_WIDTH) / 2;

        this->display[y][x] = this->ram.load(i);

        if(x == 0){
            waddch(stdscr, '|');
        }

        if(this->display[y][x] == 0){
            waddch(stdscr, '.');
        }else{
            waddch(stdscr, this->display[y][x]);
        }

        if(x == SCREEN_WIDTH - 1){
            waddch(stdscr, '|');
        }

    }
    wprintw(stdscr, "%s", "+");
    wprintw(stdscr, "%s", std::string(SCREEN_WIDTH,'=').c_str());
    wprintw(stdscr, "%s", "+");

    refresh();
    getch();
}

void Screen::remove_display(){
    endwin();
}