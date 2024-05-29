#include <gtest/gtest.h>

#include "day4.hpp"
#include "BingoCard.hpp"

TEST(Day4Utils, ExtractNumbersBySeparator1) {
    const auto input {"12;15;-3;38"};
    const std::vector<int> want {12, 15, -3, 38};

    const auto got {utils::extractNumbersBySeparator(input, ';')};

    EXPECT_EQ(want, got);
}

TEST(Day4Utils, ExtractNumbersBySeparator2) {
    const auto input {"12,-15,3"};
    const std::vector<int> want {12, -15, 3};

    const auto got {utils::extractNumbersBySeparator(input, ',')};

    EXPECT_EQ(want, got);
}

TEST(Day4BingoCard, ShouldThrowWhenInvalidIdx) {
    BingoCard bc{BingoNumbers{}};

    EXPECT_THROW(bc.getNum(18, 5), std::out_of_range);
    EXPECT_THROW(bc.checkNum(10, 5), std::out_of_range);
    EXPECT_THROW(bc.setMark(8, 9, true), std::out_of_range);
}

TEST(Day4BingoCard, NumberShouldBeTrueAfterMark) {
    BingoCard bc{BingoNumbers{}};
    bc.setMark(3, 2, true);

    EXPECT_TRUE(bc.checkNum(3, 2));
}

TEST(Day4BingoCard, CreateBingoCardFromArray) {
    const BingoCard bc {BingoNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}};

    EXPECT_EQ(2, bc.getNum(0,1));
    EXPECT_EQ(9, bc.getNum(1,3));
    EXPECT_EQ(19, bc.getNum(3,3));
}

TEST(Day4BingoCard, CreateBingoCardFromString1) {
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

TEST(Day4BingoCard, CreateBingoCardFromString2) {
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

TEST(Day4BingoCard, FindAndMarkGivenNumber) {
    BingoCard bc {BingoNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}};
    bc.setMark(1, 3, true);
    const int numToBeChecked {9};

    const int numToBeMarked {16};
    bc.markNum(numToBeMarked);

    EXPECT_TRUE(bc.checkNum(numToBeChecked));
    EXPECT_TRUE(bc.checkNum(numToBeMarked));
}

TEST(Day4BingoCard, CheckWinShouldFalse) {
    BingoCard bc {BingoNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}};

    EXPECT_FALSE(bc.checkWin());
}

TEST(Day4BingoCard, CheckWinShouldTrue) {
    BingoCard bc {BingoNumbers{14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23,
        26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7}};

    bc.markNum(14); bc.markNum(21); bc.markNum(17);
    bc.markNum(4); bc.markNum(9); bc.markNum(23);
    bc.markNum(11); bc.markNum(5); bc.markNum(2);
    bc.markNum(0); bc.markNum(7);
    bc.markNum(24);

    EXPECT_TRUE(bc.checkWin());
}

TEST(Day4BingoCard, EvaluateWinScore) {
    BingoCard bc {BingoNumbers{14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23,
        26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7}};
    const int want {4512};

    bc.markNum(14); bc.markNum(21); bc.markNum(17);
    bc.markNum(4); bc.markNum(9); bc.markNum(23);
    bc.markNum(11); bc.markNum(5); bc.markNum(2);
    bc.markNum(0); bc.markNum(7);
    bc.markNum(24);

    EXPECT_EQ(want, bc.checkScore(24));
}

TEST(Day4ExtractInput, SimpleInput) {
    const std::string input {R"(23,11,17,8,9,10

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

11 12 13 14 15
16 17 18 19 110
111 112 113 114 115
116 117 118 119 120
121 122 123 124 125)"};
    BingoSubsysOutput got {utils::getBingoAll(input, false)}; 

    EXPECT_EQ(6, got.first.size());
    EXPECT_EQ(2, got.second.size());
}

TEST(Day4ExtractInput, AoCTestInput) {
    const std::string input {"../data/day4/input_test.txt"};
    BingoSubsysOutput got {utils::getBingoAll(input, true)}; 

    EXPECT_EQ(27, got.first.size());
    EXPECT_EQ(3, got.second.size());
}

TEST(Day4TestScenario, EvaluateGame) {
    const std::string input {"../data/day4/input_test.txt"};
    BingoSubsysOutput bso {utils::getBingoAll(input, true)}; 
    const int want {4512};

    const auto got {utils::evaluateGame(bso)};
    EXPECT_EQ(want, got);
}

TEST(Day4TestScenario, EvaluateGameDayTwo) {
    const std::string input {"../data/day4/input_test.txt"};
    BingoSubsysOutput bso {utils::getBingoAll(input, true)}; 
    const int want {1924};

    const auto got {utils::evaluateGame(bso, true)};
    EXPECT_EQ(want, got);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
