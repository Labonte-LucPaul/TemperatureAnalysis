#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include <string>
#include <vector>

using StringTokenized = std::vector<std::string>;

StringTokenized tokenize(const std::string &str, const char *token);

#endif // STRINGTOKENIZER_H
