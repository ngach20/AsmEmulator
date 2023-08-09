#include "reader.h"
#include <iostream>

Reader::Reader(const char* filename){
    std::fstream myFile;

    myFile.open(filename, std::ios_base::in);
    
    if(!myFile.is_open()){
        std::cerr << "Incorrect file path" << std::endl;
        exit(-1);
    }

    this->lines_head = NULL;

    lines** lines_ptr;
    lines_ptr = &lines_head;

    std::string line;
    while(std::getline(myFile, line)){
        *lines_ptr = new lines;
        (*lines_ptr)->line = line;
        (*lines_ptr)->next = NULL;
        lines_ptr = &(*lines_ptr)->next;
    }


    this->cur_line = this->lines_head;
    myFile.close();
}

std::string Reader::next_line(){
    if(this->cur_line == NULL){
        return NULL;
    }

    std::string line = this->cur_line->line;
    this->cur_line = this->cur_line->next;
    return line;
}

bool Reader::has_next(){
    return this->cur_line != NULL;
}

Reader::~Reader(){
    this->cur_line = this->lines_head;

    while(this->cur_line != NULL){
        lines* prev_line = this->cur_line;
        this->cur_line = prev_line->next;
        
        delete prev_line;
    }
}