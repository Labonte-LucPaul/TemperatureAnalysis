#include "iofile.h"

#include <fstream>
#include <string>

void readFile(const std::string &file, ReadFunct f)
{
    std::string line;
    std::ifstream stream(file);
    if(stream.is_open()) {
        std::getline(stream, line); // header
        while(std::getline(stream, line))
            f(line);
        stream.close();
    }
}

void writeFile(const std::string &file, WriteFunct f)
{
    std::ofstream stream(file);
    if(stream.is_open()) {
        f(stream);
        stream.close();
    }
}
