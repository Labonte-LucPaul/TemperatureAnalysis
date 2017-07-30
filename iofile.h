#ifndef IOFILE_H
#define IOFILE_H

#include <fstream>
#include <functional>
#include <string>

using ReadFunct = std::function<void(std::string)>;
using WriteFunct = std::function<void(std::ofstream&)>;

void readFile(const std::string &file, ReadFunct f);

void writeFile(const std::string &file, WriteFunct f);

#endif // IOFILE_H
