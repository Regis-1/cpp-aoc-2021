#include <gtest/gtest.h>

#include "day6.hpp"

TEST(ExtractingInput, ExtractInputFromAocTest) {
    const std::string path {"../data/day6/input_test.txt"};
    const day6::Lanterfishes want {3, 4, 3, 1, 2};

    EXPECT_EQ(want, day6::extractDataFromFile(path));
}

TEST(LifeCycle, Handling1DayWithoutNewFish) {
    day6::Lanterfishes fishes {3, 4, 3, 1, 2};
    const day6::Lanterfishes want {2, 3, 2, 0, 1};

    day6::processOneDay(fishes);
    EXPECT_EQ(want, fishes);
}

TEST(LifeCycle, Handling1DayWithNewFish) {
    day6::Lanterfishes fishes {2, 3, 2, 0, 1};
    const day6::Lanterfishes want {1, 2, 1, 6, 0, 8};

    day6::processOneDay(fishes);
    EXPECT_EQ(want, fishes);
}

TEST(LifeCycle, Handling18Days) {
    day6::Lanterfishes fishes {3, 4, 3, 1, 2};
    day6::Lanterfishes want {6,0,6,4,5,6,0,1,1,2,6,0,1,1,1,2,2,3,3,4,6,7,8,8,8,8};

    day6::processNDays(fishes, 18);
    EXPECT_EQ(want, fishes);
}

TEST(LifeCycle, Handling80Days) {
    day6::Lanterfishes fishes {3, 4, 3, 1, 2};
    unsigned int wantSize {5934};

    day6::processNDays(fishes, 80);
    EXPECT_EQ(wantSize, fishes.size());
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
