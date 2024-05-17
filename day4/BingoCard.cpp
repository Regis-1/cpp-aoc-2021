#include "BingoCard.hpp"
#include <sstream>

BingoCard::BingoCard(const BingoNumbers& initNums) : numbers(std::move(initNums)) {
}

BingoCard::BingoCard(const std::string& input) {
}

const int BingoCard::getNum(const int& row, const int& col) const {
    return numbers[row * 5 + col];
}

const bool operator==(const BingoCard& lhs, const BingoCard& rhs) {
    return false;
}
