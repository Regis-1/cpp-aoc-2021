#include "day6.hpp"

#include <sstream>
#include <iostream>
#include <fstream>

namespace {
const int numOfCycleDays {8};
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
const std::vector<int> extractDataFromFile(const std::string& path) {
    std::ifstream fd{path};
    if (fd.bad())
        throw std::runtime_error{
            "Something is wrong with the file provided. Cannot open it."};

    std::string line;
    std::getline(fd, line);

    return extractNumbersBySeparator(line, ',');
}

const Lanterfish groupFish(const std::vector<int> fish) {
    Lanterfish lf;
    for (auto i{0}; i <= numOfCycleDays; ++i)
        lf[i] = 0;

    for (const auto f : fish) {
        if (auto found {lf.find(f)}; found != lf.end()) {
            lf[f] += 1;
        }
    }

    return lf;
}

void processOneDay(Lanterfish& fish) {
    unsigned long newborn{0};
    for (auto& [k, v] : fish) {
        if (k == 0) {
            newborn = fish[k];
            v = fish[k+1];
        }
        else if (k == 6) {
            v = fish[k+1] + newborn;
        }
        else if (k == 8) {
            v = newborn;
        }
        else {
            v = fish[k+1];
        }
    }
}

void processNDays(Lanterfish &fish, const unsigned int ndays) {
    for (auto i{0}; i < ndays; ++i)
        processOneDay(fish);
}

const unsigned long countFish(const Lanterfish &fish) {
    unsigned long sum{0};
    for (const auto [k, v] : fish)
        sum += v;
    return sum;
}
}
