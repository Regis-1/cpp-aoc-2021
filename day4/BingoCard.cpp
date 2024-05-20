#include "BingoCard.hpp"
#include <sstream>
#include <iostream>

BingoCard::BingoCard(const BingoNumbers& initNums) : numbers(std::move(initNums)) {
}

BingoCard::BingoCard(const std::string& input) {
    std::istringstream iss(input);
    int num;
    size_t idx{0};
    for (iss >> num; !iss.fail(); iss >> num) {
        numbers[idx] = num;
        ++idx;
    }
}

const int BingoCard::getNum(const int& row, const int& col) const {
    auto idx {row * 5 + col};
    if (idx >= numbers.size()) throw std::out_of_range("Invalid idx for number");

    return numbers[row * 5 + col];
}

const bool BingoCard::checkNum(const int& row, const int& col) const {
    auto idx {row * 5 + col};
    if (idx >= numbers.size()) throw std::out_of_range("Invalid idx for number");

    return marks[row * 5 + col];
}

void BingoCard::markNum(const int& row, const int& col, const bool& value) {
    auto idx {row * 5 + col};
    if (idx >= marks.size()) throw std::out_of_range("Invalid idx for number");

    marks[row * 5 + col] = value;
}

const bool operator==(const BingoCard& lhs, const BingoCard& rhs) {
    return false;
}
