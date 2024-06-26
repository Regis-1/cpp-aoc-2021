#pragma once

#include <vector>
#include <string>
#include <utility>
#include "BingoCard.hpp"

using BingoSubsysOutput = std::pair<const std::vector<int>, std::vector<BingoCard>>;

namespace utils {
    const std::vector<int> extractNumbersBySeparator(const std::string&, const char&);
    BingoSubsysOutput getBingoAll(const std::string&, const bool&);
    const int evaluateGame(BingoSubsysOutput& bso, const bool& = false);
}
