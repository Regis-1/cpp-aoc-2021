#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <numeric>

std::vector<int> extractInputValues(const std::string fileName) {
    std::ifstream fd(fileName);
    if (!fd) {
        std::cout << "ERROR: Invalid filename or the file itself!" << std::endl;
        return {};
    }

    std::istream_iterator<int> begIter(fd);
    std::istream_iterator<int> endIter;

    std::vector<int> inputValues;
    for (auto cIter {begIter}; cIter != endIter; ++cIter)
        inputValues.push_back(*cIter);

    return inputValues;
}

int countIncreases(const std::vector<int>& values, unsigned int windowSize = 1) {
    if (values.size() == 0 || windowSize >= values.size())
        return 0;

    if (windowSize == 0)
        throw std::invalid_argument("Sliding window size cannot be less or equal to 0.");

    int totalCount {0};
    auto begIter {std::begin(values)};
    auto winEndIter {std::begin(values) + windowSize};
    auto endIter {std::end(values)};

    int prevValue {std::accumulate(begIter, winEndIter, 0)};
    for (auto it {++begIter}; winEndIter != endIter; ++it) {
        ++winEndIter;
        int currValue = std::accumulate(it, winEndIter, 0);
        if (currValue > prevValue)
            ++totalCount;
        prevValue = currValue;
    }

    return totalCount;
}
