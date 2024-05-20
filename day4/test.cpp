#include <gtest/gtest.h>

#include "day4.hpp"
#include "BingoCard.hpp"

TEST(Day4PartOne, ShouldThrowWhenInvalidIdx) {
    BingoCard bc{BingoNumbers{}};

    EXPECT_THROW(bc.getNum(18, 5), std::out_of_range);
    EXPECT_THROW(bc.checkNum(10, 5), std::out_of_range);
    EXPECT_THROW(bc.markNum(8, 9, true), std::out_of_range);
}

TEST(Day4PartOne, CreateBingoCardFromArray) {
    const BingoCard bc {BingoNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}};

    EXPECT_EQ(2, bc.getNum(0,1));
    EXPECT_EQ(9, bc.getNum(1,3));
    EXPECT_EQ(19, bc.getNum(3,3));
}

TEST(Day4PartOne, CreateBingoCardFromString1) {
    const std::string input {R"(
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25)"};

    const BingoCard bc {input};

    EXPECT_EQ(2, bc.getNum(0,1));
    EXPECT_EQ(9, bc.getNum(1,3));
    EXPECT_EQ(19, bc.getNum(3,3));
}

TEST(Day4PartOne, CreateBingoCardFromString2) {
    const std::string input {R"(
11 12 13 14 15
16 17 18 19 110
111 112 113 114 115
116 117 118 119 120
121 122 123 124 125)"};

    const BingoCard bc {input};

    EXPECT_EQ(12, bc.getNum(0,1));
    EXPECT_EQ(19, bc.getNum(1,3));
    EXPECT_EQ(119, bc.getNum(3,3));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
