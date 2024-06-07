#pragma once

#include <vector>
#include <string>

namespace day6 {
    using Lanterfishes = std::vector<int>;
}

namespace {
const std::vector<int> extractNumbersBySeparator(const std::string& input, const char& sep);
}

namespace day6 {
const Lanterfishes extractDataFromFile(const std::string& path);
void processOneDay(Lanterfishes& fishes);
void processNDays(Lanterfishes& fishes, const unsigned int ndays);
}
