#include "BingoCard.hpp"
#include <algorithm>
#include <iterator>
#include <sstream>

BingoCard::BingoCard(const BingoNumbers& initNums) : numbers(std::move(initNums)) {
}

BingoCard::BingoCard(const std::string& input) {
    std::istringstream iss(input);
    int num;
    size_t idx{0};
    for (iss >> num; !iss.fail(); iss >> num) {
        numbers[idx] = num;
        ++idx;
        if (idx == BINGO_CARD_SIZE) break;
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

const bool BingoCard::checkNum(const int& numToBeChecked) const {
    return marks[findNum(numToBeChecked)];
}

void BingoCard::setMark(const int& row, const int& col, const bool& value) {
    auto idx {row * 5 + col};
    if (idx >= marks.size()) throw std::out_of_range("Invalid idx for number");

    marks[row * 5 + col] = value;
}

void BingoCard::markNum(const int& numToBeMarked) {
    marks[findNum(numToBeMarked)] = true;
}

const int BingoCard::findNum(const int& numToBeFound) const {
    const auto findResult {std::find(std::begin(numbers), std::end(numbers), numToBeFound)};

    if (findResult == std::end(numbers))
        throw std::logic_error("Searched number is not on the BingoCard!");

    return std::distance(std::begin(numbers), findResult);
}

const bool BingoCard::checkWin() {
    std::array<int, 10> sums{0};
    for (auto i {0}; i < 5; ++i)
        for (auto j {0}; j < 5; ++j)
            if (checkNum(j, i)) {
                sums[i]++;
                sums[j+5]++;
            }

    for (auto s : sums)
        if (s == 5)
            return true;

    return false;
}

const int BingoCard::checkScore(const int& lastNum) {
    int sum {0};
    for (auto i {0}; i < 5; ++i)
        for (auto j {0}; j < 5; ++j) 
            if (!checkNum(j, i))
                sum += getNum(j, i);

    return sum*lastNum;
}

const bool operator==(const BingoCard& lhs, const BingoCard& rhs) {
    return false;
}
