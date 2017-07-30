#include "validatetemperature.h"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

#include "temperaturedata.h"

using namespace std;

constexpr double TOLERANCE_60 = 0.32;
constexpr double TOLERANCE_25 = 0.32;
constexpr double TOLERANCE_NEG20 = 0.51;

Report validateTemperature(const Sample &sample, const Reference &ref)
{
    Report report;

    auto variance = [](double t, double r) { return r - t; };
    auto isTolerance = [](double t, double v) { return v <= t && v >= -t; };

    for(auto s : sample) {
        auto r = ref.cbegin();
        for(const auto d : s) {
            double v = variance(d.temperature, r->temperature);
            ReportData rep = {};
            rep.sequence = d.sequence;
            rep.ref = r->temperature;
            rep.sample = d.temperature;
            rep.variance = v;
            rep.isvalid = isTolerance(TOLERANCE_60, v) ||
                          isTolerance(TOLERANCE_25, v) ||
                          isTolerance(TOLERANCE_NEG20, v);
            report.add(rep);
            ++r;
        }
    }

    return report;
}
