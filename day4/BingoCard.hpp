#pragma once

#include <string>
#include <array>

namespace {
    const int BINGO_CARD_SIZE = 25;
}

using BingoNumbers = std::array<int, BINGO_CARD_SIZE>;
using BingoMarks = std::array<bool, BINGO_CARD_SIZE>;

class BingoCard {
public:
    BingoCard() = delete;
    BingoCard(const BingoNumbers&);
    BingoCard(const std::string&);
    ~BingoCard() = default;

    const int getNum(const int&, const int&) const;
    const bool checkNum(const int&, const int&) const;
    const bool checkNum(const int&) const;
    void setMark(const int&, const int&, const bool&);
    void markNum(const int&);
    const bool checkWin();
    const int checkScore(const int&);

private:
    const int findNum(const int&) const;

    BingoNumbers numbers{};
    BingoMarks marks{};
};

const bool operator==(const BingoCard&, const BingoCard&);
