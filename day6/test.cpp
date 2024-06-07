#include <gtest/gtest.h>

#include "day6.hpp"

TEST(ExtractingInput, ExtractInputFromAocTest) {
    const std::string path {"../data/day6/input_test.txt"};
    const std::vector<int> want {3, 4, 3, 1, 2};

    EXPECT_EQ(want, day6::extractDataFromFile(path));
}

TEST(ExtractingInput, GroupingFish) {
    const std::vector<int> fish {3, 4, 3, 1, 2};
    const day6::Lanterfish want {{0,0},{1,1},{2,1},{3,2},{4,1},{5,0},{6,0},{7,0},{8,0}};
    EXPECT_EQ(want, day6::groupFish(fish));
}

TEST(LifeCycle, Handling1DayWithoutNewFish) {
    day6::Lanterfish fish {{0,0},{1,1},{2,1},{3,2},{4,1},{5,0},{6,0},{7,0},{8,0}};
    const day6::Lanterfish want {{0,1},{1,1},{2,2},{3,1},{4,0},{5,0},{6,0},{7,0},{8,0}};

    day6::processOneDay(fish);
    EXPECT_EQ(want, fish);
}

TEST(LifeCycle, Handling1DayWithNewFish) {
    day6::Lanterfish fish {{0,1},{1,1},{2,2},{3,1},{4,0},{5,0},{6,0},{7,0},{8,0}};
    const day6::Lanterfish want {{0,1},{1,2},{2,1},{3,0},{4,0},{5,0},{6,1},{7,0},{8,1}};

    day6::processOneDay(fish);
    EXPECT_EQ(want, fish);
}

TEST(LifeCycle, Handling18Days) {
    day6::Lanterfish fish {{0,0},{1,1},{2,1},{3,2},{4,1},{5,0},{6,0},{7,0},{8,0}};
    day6::Lanterfish want {{0,3},{1,5},{2,3},{3,2},{4,2},{5,1},{6,5},{7,1},{8,4}};

    day6::processNDays(fish, 18);
    EXPECT_EQ(want, fish);
}

TEST(LifeCycle, Handling80Days) {
    day6::Lanterfish fish {{0,0},{1,1},{2,1},{3,2},{4,1},{5,0},{6,0},{7,0},{8,0}};
    unsigned int wantSize {5934};

    day6::processNDays(fish, 80);
    EXPECT_EQ(wantSize, day6::countFish(fish));
}

TEST(LifeCycle, Handling256Days) {
    day6::Lanterfish fish {{0,0},{1,1},{2,1},{3,2},{4,1},{5,0},{6,0},{7,0},{8,0}};
    unsigned long wantSize {26984457539};

    day6::processNDays(fish, 256);
    EXPECT_EQ(wantSize, day6::countFish(fish));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
