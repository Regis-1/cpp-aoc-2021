#include <gtest/gtest.h>

#include "day4.hpp"
#include "BingoCard.hpp"

TEST(Day4PartOne, ExtractNumbersBySeparator1) {
    const auto input {"12;15;-3;38"};
    const std::vector<int> want {12, 15, -3, 38};

    const auto got {utils::extractNumbersBySeparator(input, ';')};

    EXPECT_EQ(want, got);
}

TEST(Day4PartOne, ExtractNumbersBySeparator2) {
    const auto input {"12,-15,3"};
    const std::vector<int> want {12, -15, 3};

    const auto got {utils::extractNumbersBySeparator(input, ',')};

    EXPECT_EQ(want, got);
}

TEST(Day4PartOne, CreateBingoCardFromArray) {
    const BingoCard bc {BingoNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}};

    EXPECT_EQ(2, bc.getNum(0,1));
    EXPECT_EQ(9, bc.getNum(1,3));
    EXPECT_EQ(19, bc.getNum(3,3));
}

TEST(Day4PartOne, CreateBingoCardFromString) {
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

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
