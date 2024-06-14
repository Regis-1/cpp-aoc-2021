#include "day8.hpp"
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>

namespace {
const std::string comboDigitsDivider{" | "};
const unsigned int numOfDigits{4};
const unsigned int numOfSignals{10};

const std::vector<std::string> extractAllDigitsFromIfstream(std::ifstream &is);
const std::vector<day8::SignalsAndDigits> extractAllSignalsAndDigitsFromIfstream(std::ifstream &is);
const std::optional<std::ifstream> openFile(const std::string &filePath);
}

namespace day8 {
const std::vector<std::string> extractDisplayDigitsFromInputFile(const std::string &filePath) {
    auto fd{openFile(filePath)};

    if (not fd.has_value()) {
        return {};
    }

    return extractAllDigitsFromIfstream(fd.value());
}

const std::vector<SignalsAndDigits> extractSignalsAndDigitsFromInputFile(const std::string &filePath) {
    auto fd{openFile(filePath)};

    if (not fd.has_value()) {
        return {};
    }

    return extractAllSignalsAndDigitsFromIfstream(fd.value());
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

namespace {
const std::vector<std::string> extractAllDigitsFromIfstream(std::ifstream &is) {
    std::vector<std::string> digits;
    for (std::string line; std::getline(is, line);) {
        digits.reserve(digits.size() + numOfDigits);
        if (auto found{line.find(comboDigitsDivider)}) {
            std::istringstream iss(line.substr(found+comboDigitsDivider.length()));
            for (std::string word; std::getline(iss, word, ' ');)
                digits.push_back(word);
        }
    }

    is.close();
    return digits;
}

const std::vector<day8::SignalsAndDigits> extractAllSignalsAndDigitsFromIfstream(std::ifstream &is) {
    std::vector<day8::SignalsAndDigits> output;
    std::vector<std::string> signals;
    std::vector<std::string> digits;

    for (std::string line; std::getline(is, line);) {
        if (auto found{line.find(comboDigitsDivider)}) {
            std::stringstream ss(line.substr(0, found));
            for (std::string word; std::getline(ss, word, ' ');)
                signals.push_back(word);

            ss.clear();
            ss.str(line.substr(found+comboDigitsDivider.length()));
            for (std::string word; std::getline(ss, word, ' ');)
                digits.push_back(word);
        }

        output.push_back({signals, digits});
        signals.clear();
        digits.clear();
    }

    is.close();
    return output;
}

const std::optional<std::ifstream> openFile(const std::string &filePath) {
    std::ifstream fd(filePath);
    if (fd.bad()) {
        std::cerr << "There was something wrong with specified file." << std::endl;
        fd.close();
        return std::nullopt;
    }
    
    return fd;
}
}
