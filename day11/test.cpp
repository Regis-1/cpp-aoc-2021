#include <gtest/gtest.h>

#include "day11.hpp"

namespace {
const day11::OctopusGrid testOctopusGrid{
5,4,8,3,1,4,3,2,2,3,
2,7,4,5,8,5,4,7,1,1,
5,2,6,4,5,5,6,1,7,3,
6,1,4,1,3,3,6,1,4,6,
6,3,5,7,3,8,5,4,7,8,
4,1,6,7,5,2,4,6,4,5,
2,1,7,6,8,4,1,7,2,1,
6,8,8,2,8,8,1,1,3,4,
4,8,4,6,8,4,8,5,5,4,
5,2,8,3,7,5,1,5,2,6
};
}

TEST(Input, ExtractingShouldThrowWhenInvalidFile) {
    const std::string invalidPath{"../wrongFile.txt"};
    EXPECT_THROW(day11::extractOctopusGridFromFile(invalidPath), std::runtime_error);
}

TEST(Input, ExtractingInputFromTestFile) {
    const std::string filepath{"../data/day11/input_test.txt"};
    const auto gotExtracted{day11::extractOctopusGridFromFile(filepath)};

    EXPECT_EQ(testOctopusGrid, gotExtracted);
}

TEST(OctopusCycle, OneStep) {
    day11::OctopusGrid initialGrid{testOctopusGrid};
    const day11::OctopusGrid wantAfter1Step{
        6,5,9,4,2,5,4,3,3,4, 3,8,5,6,9,6,5,8,2,2, 6,3,7,5,6,6,7,2,8,4,
        7,2,5,2,4,4,7,2,5,7, 7,4,6,8,4,9,6,5,8,9, 5,2,7,8,6,3,5,7,5,6,
        3,2,8,7,9,5,2,8,3,2, 7,9,9,3,9,9,2,2,4,5, 5,9,5,7,9,5,9,6,6,5,
        6,3,9,4,8,6,2,6,3,7};

    day11::runCycle(initialGrid, 1);
    EXPECT_EQ(wantAfter1Step, initialGrid);
}

TEST(OctopusCycle, TwoSteps) {
    day11::OctopusGrid initialGrid{testOctopusGrid};
    const day11::OctopusGrid wantAfter2Steps{
    8,8,0,7,4,7,6,5,5,5, 5,0,8,9,0,8,7,0,5,4, 8,5,9,7,8,8,9,6,0,8,
    8,4,8,5,7,6,9,6,0,0, 8,7,0,0,9,0,8,8,0,0, 6,6,0,0,0,8,8,9,8,9,
    6,8,0,0,0,0,5,9,4,3, 0,0,0,0,0,0,7,4,5,6, 9,0,0,0,0,0,0,8,7,6,
    8,7,0,0,0,0,6,8,4,8,};

    day11::runCycle(initialGrid, 2);
    EXPECT_EQ(wantAfter2Steps, initialGrid);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
