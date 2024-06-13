#include "day8.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace {
const std::string comboDigitsDivider{" | "};
const unsigned int numOfDigits{4};
}

namespace day8 {
const std::vector<std::string> extractDisplayDigitsFromInputFile(const std::string &filePath) {
    std::ifstream fd(filePath);
    if (fd.bad()) {
        std::cerr << "There was something wrong with specified file." << std::endl;
        fd.close();
        return {};
    }

    std::vector<std::string> digits;
    for (std::string line; std::getline(fd, line);) {
        digits.reserve(digits.size() + numOfDigits);
        if (auto found{line.find(comboDigitsDivider)}) {
            std::istringstream iss(line.substr(found+comboDigitsDivider.length()));
            for (std::string word; std::getline(iss, word, ' ');)
                digits.push_back(word);
        }
    }

    return digits;
}

const size_t countDigitsWithNSegments(const std::vector<std::string> &digits,
        const std::vector<size_t> &&segmentsCount)
{
    size_t sum{0};
    for (auto d : digits)
        for (auto &&sg : segmentsCount)
            if (d.length() == sg)
                ++sum;

    return sum;
}
}
