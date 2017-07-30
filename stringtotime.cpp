#include "stringtotime.h"

#include <chrono>
#include <ctime>
#include <exception>
#include <iomanip>
#include <sstream>
#include <string>

std::time_t stringToTime(std::string str, const char* format)
{
    std::tm t = {};
    std::istringstream ss(str);
    ss >> std::get_time(&t, format);
    if(ss.fail())
        throw std::runtime_error("Error parsing time");

    return std::mktime(&t);
}

std::int64_t getElapsed(std::size_t h, std::size_t m, std::size_t s)
{
    std::chrono::hours hours(h);
    std::chrono::minutes min(m);
    std::chrono::seconds sec(s);

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(hours);
    elapsed += std::chrono::duration_cast<std::chrono::seconds>(min);
    elapsed += sec;

    return elapsed.count();
}
