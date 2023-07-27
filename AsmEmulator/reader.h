#include <fstream>
#include <string.h>

class Reader{
    public:
        Reader(const char* filename);
        std::string next_line();
        bool has_next();
        ~Reader();

    private:
        struct lines{
            std::string line;
            lines* next;
        };
        
        lines* lines_head;
        lines* cur_line;
    
};

