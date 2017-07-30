#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

#include <ctime>
#include <ostream>
#include <vector>

struct SampleData
{
    int sequence;
    std::int64_t elapsed;
    std::time_t timestamp;
    double temperature;
};

struct ReferenceData
{
    std::time_t timestamp;
    double temperature;
    bool alarm;
};

struct ReportData
{
    int sequence;

    double ref;
    double sample;
    double variance;
    bool isvalid;

    friend std::ostream &operator<<(std::ostream &os, const ReportData &data)
    {
        os << data.sequence << ","
           << data.ref      << ","
           << data.sample   << ","
           << data.variance << ","
           << (data.isvalid ? "Valid" : "Invalid") << "\n";
        return os;
    }
};

template <class T>
class TemperatureData
{
  public:
    void add(const T &d) { data.push_back(d); }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto cbegin() const { return data.cbegin(); }
    auto cend() const { return data.cend(); }

  private:
    std::vector<T> data;
};

using Reference = TemperatureData<ReferenceData>;
using Report = TemperatureData<ReportData>;
using Sample = std::vector<TemperatureData<SampleData>>;

#endif // TEMPERATUREDATA_H
