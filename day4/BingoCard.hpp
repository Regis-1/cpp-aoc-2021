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
    ~BingoCard() = default;

    const int getNum(const int&, const int&) const;
    const bool checkNum(const int&, const int&) const;
    const bool checkNum(const int&) const;
    void setMark(const int&, const int&, const bool&);
    void markNum(const int&);

private:
    const int findNum(const int&) const;

    BingoNumbers numbers{};
    BingoMarks marks{};
};

const bool operator==(const BingoCard&, const BingoCard&);
