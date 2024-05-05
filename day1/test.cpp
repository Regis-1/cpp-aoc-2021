#include <gtest/gtest.h>

#include <vector>
#include "day1.hpp"

TEST(Day1_Input, GetInputValues_InputTest) {
    const std::string fileName{"../data/day1/input_test.txt"};
    std::vector<int> wantValues {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

    std::vector<int> gotValues {extractInputValues(fileName)};

    EXPECT_EQ(wantValues, gotValues);
}

TEST(Day1_Task, IncreaseCount_SimpleThreeValues) {
    std::vector<int> values {190, 200, 200, 199, 201};
    int wantCount {2};

    int gotCount {countIncreases(values)};

    EXPECT_EQ(wantCount, gotCount);
}

TEST(Day1_Task, IncreaseCount_AoCExample) {
    std::vector<int> values {extractInputValues("../data/day1/input_test.txt")};
    int wantCount {7};

    int gotCount {countIncreases(values)};

    EXPECT_EQ(wantCount, gotCount);
}
