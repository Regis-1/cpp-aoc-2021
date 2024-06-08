#pragma once

#include <vector>
#include <string>

namespace day7 {
    using CrabsPositions = std::vector<int>;
    enum class MethodType {
        MEDIAN,
        MEAN
    };
}

namespace {
    const std::vector<int> extractNumbersBySeparator(const std::string& input, const char& sep);
}

namespace day7 {
    const CrabsPositions extractCrabsPositions(const std::string& path);
    const unsigned int getOptimalPosition(const CrabsPositions& cpos, const MethodType& method);
    const unsigned int evaluateFuelLinear(const CrabsPositions& cpos, const unsigned int& dest);
    const unsigned int evaluateFuelNonLin(const CrabsPositions& cpos, const unsigned int& dest);
}
