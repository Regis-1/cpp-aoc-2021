#include "day7.hpp"

#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

namespace {
const std::vector<int> extractNumbersBySeparator(const std::string& input, const char& sep) {
    std::istringstream iss(input);
    std::vector<int> result;

    for (std::string token; getline(iss, token, sep);) {
        try {
            result.push_back(std::stoi(token));
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return result;
        }
    }

    return result;
}

const float calculateMedian(std::vector<int> v) {
    const auto size{v.size()};
    std::sort(std::begin(v), std::end(v));

    if (size % 2 == 0)
        return (v[size/2] + v[(size/2) - 1])/2.f;
    else
        return v[size/2];
}

const float calculateMean(std::vector<int> v) {
    return std::accumulate(std::begin(v), std::end(v), 0)/static_cast<float>(v.size());
}
}

namespace day7 {
const CrabsPositions extractCrabsPositions(const std::string& path) {
    std::ifstream fd{path};
    if (fd.bad())
        throw std::runtime_error{
            "Something is wrong with the file provided. Cannot open it."};

    std::string line;
    std::getline(fd, line);

    return extractNumbersBySeparator(line, ',');
}

const unsigned int getOptimalPosition(const CrabsPositions &cpos, const MethodType& method) {
    switch (method) {
        case MethodType::MEDIAN:
            return static_cast<unsigned int>(calculateMedian(cpos));
        case MethodType::MEAN:
            return static_cast<unsigned int>(round(calculateMean(cpos)));
    }

    return 0;
}

const unsigned int evaluateFuelLinear(const CrabsPositions &cpos, const unsigned int &dest) {
    return std::accumulate(std::begin(cpos), std::end(cpos), 0,
        [&dest](unsigned int result, unsigned int cp) {
            return result + abs(static_cast<int>(cp - dest));
        });
}

const unsigned int evaluateFuelNonLin(const CrabsPositions& cpos, const unsigned int& dest) {
    unsigned int fuelSum{0};
    for (const auto cp : cpos) {
        const auto dist = abs(static_cast<int>(cp - dest));
        for (auto i{1}; i<=dist; ++i) {
            fuelSum += i;
        }
    }

    return fuelSum;
}
}
