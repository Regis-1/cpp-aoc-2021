#pragma once

#include <string>
#include <vector>

namespace day8 {
using SignalsAndDigits = std::pair<std::vector<std::string>, std::vector<std::string>>;

const std::vector<std::string> extractDisplayDigitsFromInputFile(const std::string &filePath);
const std::vector<SignalsAndDigits> extractSignalsAndDigitsFromInputFile(const std::string &filePath);
const size_t countDigitsWithNSegments(const std::vector<std::string> &digits,
        const std::vector<size_t> &&segmentsCount);
const int decodeSignalLine(const SignalsAndDigits &sg);
const std::vector<int> decodeSignals(const std::vector<SignalsAndDigits> &sgs);
}
