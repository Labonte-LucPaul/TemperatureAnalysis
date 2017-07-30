#ifndef DATAINITIALIZER_H
#define DATAINITIALIZER_H

#include <string>

#include "temperaturedata.h"

TemperatureData<SampleData> parseSampleData(const std::string &file);

TemperatureData<ReferenceData> parseReferenceData(const std::string &file);

#endif // DATAINITIALIZER_H
