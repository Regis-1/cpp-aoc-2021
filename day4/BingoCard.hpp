#pragma once

#include <string>
#include <array>

using BingoNumbers = std::array<int, 25>;
using BingoMarks = std::array<bool, 25>;

class BingoCard {
public:
    BingoCard() = delete;
    BingoCard(const BingoNumbers&);
    BingoCard(const std::string&);

    const int getNum(const int&, const int&) const;

private:
    BingoNumbers numbers{};
    BingoMarks marks{};
};

const bool operator==(const BingoCard&, const BingoCard&);
