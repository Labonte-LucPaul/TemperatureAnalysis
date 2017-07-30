#include "dataparser.h"

#include <algorithm>
#include <cctype>
#include <sstream> // for istringstream >> boolean
#include <string>

#include "iofile.h"
#include "stringtokenizer.h"
#include "stringtotime.h"
#include "temperaturedata.h"

using namespace std;

constexpr const char* const CSV_TOKEN = ",";
constexpr const char* const REF_TOKEN = "\t";

TemperatureData<SampleData> parseSampleData(const string &file)
{
    TemperatureData<SampleData> sample;

    readFile(file, [&](string l) {
        const auto split = tokenize(l, CSV_TOKEN);
        if(split.empty()) return;
        SampleData data;
        data.sequence = stoi(split.at(0));
        const auto es = tokenize(split.at(1), ":");
        if(!es.empty())
            data.elapsed = getElapsed(std::stoi(es[0]),
                                      std::stoi(es[1]),
                                      std::stoi(es[2]));
        data.timestamp = stringToTime(split.at(2),
                                      "%d/%m/%Y %H:%M:%S");
        data.temperature = stod(split.at(3));

        sample.add(data);
    });

    return sample;
}

TemperatureData<ReferenceData> parseReferenceData(const string &file)
{

    auto trim = [](std::string &s) {
        std::size_t i = s.size();
        for(auto end = s.rbegin(); end != s.rend(); ++end)
            if(*end != ' ') break;
            else --i;
        s.erase(std::remove(s.begin() + i, s.end(), ' '), s.end());
    };
    auto stob = [](string s) {
        bool a;
        istringstream(s) >> a;
        return s.empty() ? false : a;
    };

    TemperatureData<ReferenceData> ref;

    readFile(file, [&](string l) {
        const auto split = tokenize(l, REF_TOKEN);
        if(split.empty()) return;
        ReferenceData data;
        std::string date = split.at(0);
        std::string time = split.at(1);
        std::string temperature = split.at(2);
        std::string alarm = split.at(3);

        trim(date);
        trim(time);
        trim(temperature);
        trim(alarm);
        std::string timeStamp = date + " " + time;
        data.timestamp = stringToTime(timeStamp, "%m/%d/%Y %I:%M:%S %p");
        data.temperature = stod(temperature);
        data.alarm = stob(alarm);
        ref.add(data);
    });

    return ref;
}
