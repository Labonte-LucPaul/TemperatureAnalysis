#ifndef TEMPERATUREANALYSIS_H
#define TEMPERATUREANALYSIS_H

#include <string>
#include <vector>

#include "dataparser.h"
#include "iofile.h"
#include "temperaturedata.h"

class TemperatureAnalysis
{
    using FilesPath = std::vector<std::string>;

  public:
    explicit TemperatureAnalysis();

    void setSampleFilePath(FilesPath paths);
    void setReferencePath(std::string path);
    void setOutputDir(std::string dir);

    void execute();

  private:
    void parseData();

    FilesPath filesPath;
    std::string refPath;
    std::string outputFile;

    Sample sampleData;
    Reference refData;
};

#endif // TEMPERATUREANALYSIS_H
