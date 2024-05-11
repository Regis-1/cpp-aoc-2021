#include <fstream>
#include <unordered_map>
#include <sstream>
#include "day3.hpp"

DiagData extractInputData(const std::string filePath) {
    std::ifstream fd(filePath);
    if (!fd)
        throw std::system_error(std::error_code(), "Invalid file or file path.");

    DiagData result;
    std::string line;

    getline(fd, line);
    for (char c : line) {
        result.push_back({c});
    }

    while (getline(fd, line)) {
        int i {0};
        for (char c : line) {
            result[i].push_back(c);
            ++i;
        }
    }

    fd.close();

    return std::move(result);
}

std::string getGammaRateFromData(DiagData& data) {
    std::string result {""};
    std::unordered_map<char, int> countMap {{'0', 0}, {'1', 0}};
    for (auto& col : data) {
        for (auto& c : col)
            countMap[c] = ++countMap[c];
        result += (countMap['0'] > countMap['1']) ? '0' : '1';
        countMap['0'] = 0; countMap['1'] = 0;
    }

    return result;
}

std::string getEpsilonRateFromGamma(const std::string& gammaRate) {
    std::vector<bool> bitVector;
    std::stringstream ss;
    bitVector.reserve(gammaRate.length());

    for (auto c : gammaRate)
        bitVector.push_back(static_cast<bool>(atoi(&c)));

    bitVector.flip();
    for (auto b : bitVector) ss << b;

    return ss.str();
}

const int binToDec(const std::string bin) {
    return stoi(bin, 0, 2);
}
