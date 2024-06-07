#include "day6.hpp"

#include <sstream>
#include <iostream>
#include <fstream>

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
}

namespace day6 {
const Lanterfishes extractDataFromFile(const std::string& path) {
    std::ifstream fd{path};
    if (fd.bad())
        throw std::runtime_error{
            "Something is wrong with the file provided. Cannot open it."};

    std::string line;
    std::getline(fd, line);

    return extractNumbersBySeparator(line, ',');
}

void processOneDay(Lanterfishes& fishes) {
    int additionalFishes {0};
    for (auto& f : fishes) {
        if (--f < 0) {
            ++additionalFishes;
            f = 6;
        }
    }

    for (int i {0}; i < additionalFishes; ++i)
        fishes.push_back(8);
}

void processNDays(Lanterfishes &fishes, const unsigned int ndays) {
    for (auto i{0}; i < ndays; ++i)
        processOneDay(fishes);
}
}
