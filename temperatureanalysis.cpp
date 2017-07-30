#include "temperatureanalysis.h"

#include <ostream>
#include <vector>

#include "dataparser.h"
#include "iofile.h"
#include "temperaturedata.h"
#include "validatetemperature.h"

TemperatureAnalysis::TemperatureAnalysis()
{

}

void TemperatureAnalysis::setSampleFilePath(TemperatureAnalysis::FilesPath path)
{
    filesPath = path;
}

void TemperatureAnalysis::setReferencePath(std::string paths)
{
    refPath = paths;
}

void TemperatureAnalysis::setOutputDir(std::string dir)
{
    outputFile = dir;
}

void TemperatureAnalysis::execute()
{
    parseData();

    auto report = validateTemperature(sampleData, refData);

    writeFile(outputFile, [&](auto &os)
    {
        os << "S.N.," << "Ref," << "Log," << "Variance," << "IsValid" << "\n";
        for(const auto r : report)
            os << r;
    });
}

void TemperatureAnalysis::parseData()
{
    sampleData.clear();
    for(const auto &p : filesPath)
        sampleData.push_back(parseSampleData(p));

    refData = parseReferenceData(refPath);
}
