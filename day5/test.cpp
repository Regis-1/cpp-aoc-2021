#include <gtest/gtest.h>

#include "day5.hpp"

namespace {
    const std::vector<VentRange> AocTestRanges {
        {{0,9}, {5,9}},
        {{8,0}, {0,8}},
        {{9,4}, {3,4}},
        {{2,2}, {2,1}},
        {{7,0}, {7,4}},
        {{6,4}, {2,0}},
        {{0,9}, {2,9}},
        {{3,4}, {1,4}},
        {{0,0}, {8,8}},
        {{5,5}, {8,2}},
    };
const std::vector<int> AocCompleteVentDiagram {
    0,0,0,0,0,0,0,1,0,0,
    0,0,1,0,0,0,0,1,0,0,
    0,0,1,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,1,0,0,
    0,1,1,2,1,1,1,2,1,1,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    2,2,2,1,1,1,0,0,0,0};
}

TEST(InputProcessing, LoadInputFromFileShouldThrowIfInvalidFile) {
    const std::string invalidPath {"../data/day5/wrong.txt"};

    EXPECT_THROW(day5::loadInputFromFile(invalidPath), std::runtime_error);
}

TEST(InputProcessing, LoadInputFromFileLoadAocTest) {
    const std::string testFilePath {"../data/day5/input_test.txt"};

    EXPECT_EQ(AocTestRanges, day5::loadInputFromFile(testFilePath));
}

TEST(Extra, GetDimensionsMax) {
    const std::string testFilePath {"../data/day5/input_test.txt"};
    const auto want {std::make_pair(9, 9)};

    EXPECT_EQ(want, day5::getRangesMax(AocTestRanges));
}

TEST(Diagram, CreateCompleteVentDiagram) {
    EXPECT_EQ(AocCompleteVentDiagram, day5::createVentDiagram(AocTestRanges));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
