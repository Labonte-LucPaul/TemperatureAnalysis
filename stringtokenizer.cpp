#include "stringtokenizer.h"

#include <cstring>
#include <string>
#include <vector>

StringTokenized tokenize(const std::string &str, const char *token)
{
    StringTokenized splitted;
    char* s = const_cast<char*>(str.c_str());
    char *data = std::strtok(s, token);
    while(data != NULL) {
        splitted.push_back(std::string(data));
        data = std::strtok(NULL, token);
    }

    return splitted;
}
