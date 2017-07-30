#ifndef STRINGTOTIME_H
#define STRINGTOTIME_H

#include <ctime>
#include <string>

std::time_t stringToTime(std::string str, const char* format);

int64_t getElapsed(size_t h, size_t m, size_t s);

#endif // STRINGTOTIME_H
