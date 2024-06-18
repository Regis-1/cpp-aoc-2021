#include <gtest/gtest.h>

#include "day9.hpp"

/*
 * Plan:
 *  - look by line index as parameter and return vector of low points
 *  - in a loop check all data line by line and merge all low points
 *  - add 1 to all of results and sum them up
 */

namespace {
    const day9::Heightmap testHeightmap{
        {2,1,9,9,9,4,3,2,1,0},
        {3,9,8,7,8,9,4,9,2,1},
        {9,8,5,6,7,8,9,8,9,2},
        {8,7,6,7,8,9,6,7,8,9},
        {9,8,9,9,9,6,5,6,7,8}
    };

    struct LoadedTestHeightmapSystem : testing::Test {
        const day9::HeightmapSystem heightmapSystem{"../data/day9/input_test.txt"};
    };
}

TEST(HeightmapSystemClass, CreatingClassWithGivenHeightmapFile) {
    const std::string filepath{"../data/day9/input_test.txt"};

    const day9::HeightmapSystem heightmapSystem{filepath};
    EXPECT_EQ(testHeightmap, heightmapSystem.getHeightmap());
}

TEST_F(LoadedTestHeightmapSystem, FindingLowPointsInTopLine) {
    const std::vector<short> wantLowPoints{1,0};
    EXPECT_EQ(wantLowPoints, heightmapSystem.findLowPointsInLine(0));
}

TEST_F(LoadedTestHeightmapSystem, FindingAllLowPointsInHeightmap) {
    const std::vector<short> wantLowPoints{1, 0, 5, 5};
    EXPECT_EQ(wantLowPoints, heightmapSystem.findLowPoints());
}

TEST_F(LoadedTestHeightmapSystem, CalculateRiskLevels) {
    const std::vector<short> lowPoints{1, 0, 5, 5};
    const std::vector<short> wantRiskLevels{2, 1, 6, 6};
    EXPECT_EQ(wantRiskLevels, heightmapSystem.calculateRiskLevels(lowPoints));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
