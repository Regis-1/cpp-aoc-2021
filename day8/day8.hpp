#pragma once

#include <string>
#include <vector>

namespace day8 {
const std::vector<std::string> extractDisplayDigitsFromInputFile(const std::string &filePath);
const size_t countDigitsWithNSegments(const std::vector<std::string> &digits,
        const std::vector<size_t> &&segmentsCount);
}
