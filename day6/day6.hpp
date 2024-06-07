#pragma once

#include <vector>
#include <string>
#include <map>

namespace day6 {
    using Lanterfish = std::map<int, long>;
}

namespace {
const std::vector<int> extractNumbersBySeparator(const std::string& input, const char& sep);
}

namespace day6 {
const std::vector<int> extractDataFromFile(const std::string& path);
const Lanterfish groupFish(const std::vector<int> fish);
void processOneDay(Lanterfish& fish);
void processNDays(Lanterfish& fish, const unsigned int ndays);
const unsigned long countFish(const Lanterfish& fish);
}
