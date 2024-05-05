#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

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

int countIncreases(const std::vector<int>& values) {
    int totalCount {0};
    auto begIter {std::begin(values)};
    auto endIter {std::end(values)};

    int prevValue {*begIter};
    for (auto it {++begIter}; it != endIter; ++it) {
        if (*it > prevValue)
            ++totalCount;
        prevValue = *it;
    }

    return totalCount;
}
