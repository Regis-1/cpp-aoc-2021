#include <fstream>
#include <unordered_map>
#include <sstream>
#include "day3.hpp"

const DiagData extractInputData(const std::string filePath) {
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

const std::string getGammaRateFromData(const DiagData& data) {
    std::string result {""};
    std::unordered_map<char, int> countMap {{'0', 0}, {'1', 0}};
    for (auto& col : data) {
        for (auto& c : col)
            countMap[c] += 1;
        result += (countMap['0'] > countMap['1']) ? '0' : '1';
        countMap['0'] = 0; countMap['1'] = 0;
    }

    return result;
}

const std::string getEpsilonRateFromGamma(const std::string& gammaRate) {
    std::vector<bool> bitVector;
    std::stringstream ss;
    bitVector.reserve(gammaRate.length());

    for (auto c : gammaRate)
        bitVector.push_back(c == '0' ? false : true);

    bitVector.flip();
    for (auto b : bitVector) ss << b;

    return ss.str();
}

const int binToDec(const std::string bin) {
    return stoi(bin, 0, 2);
}

const DiagData filterDiagData(const DiagData& data, const bool& mostCommonMode, int idx = 0) {
    if (data.size() <= 1 or idx >= data[0].size())
        return data;

    std::unordered_map<char, int> countMap {{'0', 0}, {'1', 0}};

    for (auto row {0}; row < data.size(); ++row) {
        countMap[data[row][idx]] += 1;
    }
    char keyBit;
    if (mostCommonMode) {
        if (countMap['0'] == countMap['1']) keyBit = '1';
        else keyBit = (countMap['0'] < countMap['1']) ? '1' : '0';
    } 
    else {
        if (countMap['0'] == countMap['1']) keyBit = '0';
        else keyBit = (countMap['0'] < countMap['1']) ? '0' : '1';
    }

    DiagData _data;
    for (auto row : data)
        if (row[idx] == keyBit)
            _data.push_back(row);

    return filterDiagData(_data, mostCommonMode, ++idx);
}

const DiagData transposeDiagData(const DiagData& data) {
    DiagData result;
    for (auto row {0}; row < data[0].size(); ++row) {
        result.push_back({});
        for (auto col {0}; col < data.size(); ++col)
            result[row].push_back(data[col][row]);
    }
    return std::move(result);
}

const std::string getAdvancedRating(const DiagData& data, const bool mostCommonMode) {
    const DiagData _data {filterDiagData(transposeDiagData(data), mostCommonMode)};
    std::string result;
    for (auto c : _data[0]) result += c;
    return result;
}
