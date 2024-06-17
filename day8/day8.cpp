#include "day8.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <unordered_map>

namespace {
const std::vector<std::string> sevenSegmentEncoding {
    "1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011"
};
const std::string comboDigitsDivider{" | "};
const unsigned int numOfDigits{4};
const unsigned int numOfSignals{10};

const std::vector<std::string> extractAllDigitsFromIfstream(std::ifstream &is);
const std::vector<day8::SignalsAndDigits> extractAllSignalsAndDigitsFromIfstream(std::ifstream &is);
const std::optional<std::ifstream> openFile(const std::string &filePath);
void findAbsoluteMappings(std::vector<char> &sm, const day8::SignalsAndDigits &sg);
void findRestMappings(std::vector<char> &sm, const day8::SignalsAndDigits &sg);
const int decodeLineDigits(std::vector<char> &sm, const day8::SignalsAndDigits &sg);
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

const int decodeSignalLine(const SignalsAndDigits &sg) {
    std::vector<char> sigMapping(7, '.');
    findAbsoluteMappings(sigMapping, sg);
    findRestMappings(sigMapping, sg);
    return decodeLineDigits(sigMapping, sg);
}

const std::vector<int> decodeSignals(const std::vector<SignalsAndDigits> &sgs) {
    std::vector<int> results;
    for (const auto &sg : sgs)
        results.push_back(decodeSignalLine(sg));

    return results;
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

void findAbsoluteMappings(std::vector<char> &sm, const day8::SignalsAndDigits &sg) {
    std::unordered_map<char, int> sigCounter;
    for (const auto &signals : sg.first)
        for (const auto &s : signals)
            try {
                (sigCounter.at(s))++;
            }
            catch (const std::exception &e) {
                sigCounter[s] = 1;
            }

    for (const auto &c : sigCounter)
        switch (c.second) {
        case 4:
            sm[4] = c.first;
            break;
        case 6:
            sm[1] = c.first;
            break;
        case 9:
            sm[5] = c.first;
        }
}

void findRestMappings(std::vector<char> &sm, const day8::SignalsAndDigits &sg) {
    for (auto s : sg.first) { //from 1
        if (s.length() == 2) {
            s.erase(std::remove_if(s.begin(), s.end(), [&sm](char c){
                return c == sm[5];
            }));
            sm[2] = s[0];
        }
    }

    for (auto s : sg.first) { //from 4
        if (s.length() == 4) {
            s.erase(std::remove_if(s.begin(), s.end(), [&sm](char c){
                return c == sm[1] or c == sm[2] or c == sm[5];
            }));
            sm[3] = s[0];
        }
    }

    for (auto s : sg.first) { //from 7
        if (s.length() == 3) {
            s.erase(std::remove_if(s.begin(), s.end(), [&sm](char c){
                return c == sm[2] or c == sm[5];
            }));
            sm[0] = s[0];
        }
    }

    for (auto s : sg.first) { //from 8
        if (s.length() == 7) {
            s.erase(std::remove_if(std::begin(s), std::end(s), [&sm](char c){
                return c == sm[0] or c == sm[1] or c == sm[2] or c == sm[3] or c == sm[4] or c == sm[5];
            }));
            sm[6] = s[0];
        }
    }
}

const int decodeLineDigits(std::vector<char> &sm, const day8::SignalsAndDigits &sg) {
    std::ostringstream oss;
    std::stringstream ss;
    for (const auto &digits : sg.second) {
        std::vector<short> sigBits(7,0);
        for (const auto &digit : digits) {
            const auto pos{std::find(std::begin(sm), std::end(sm), digit)};
            sigBits[std::distance(std::begin(sm), pos)] = 1;
        }
        
        for (const auto sb : sigBits)
            oss << sb;

        const auto pos{std::find(std::begin(sevenSegmentEncoding), std::end(sevenSegmentEncoding), oss.str())};
        ss << std::distance(std::begin(sevenSegmentEncoding), pos);

        oss.clear(); oss.str("");
    }

    int result;
    ss >> result;

    return result;
}
}
