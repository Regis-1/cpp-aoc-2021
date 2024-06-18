#include <gtest/gtest.h>
#include <algorithm>
#include <ranges>

#include "day9.hpp"

/*
 * Plan:
 *  - take a first point and check if it wasn't already checked
 *  - if not run filler for all basin:
 *      - check all directions you can move from that point, and check if they are not in queue
 *      - if you can move to those directions add them to queue
 *      - after that add current point to basins map and to other point from queue
 *      - if queue is empty then the whole basin is filled and you can start searching for next basin
 *  - after all basins are found return via another functions all basin sizes
 *  - multiply those sizes by themselves to get the final score
 */

namespace {
    const day9::Heightmap testHeightmap{
        {2,1,9,9,9,4,3,2,1,0},
        {3,9,8,7,8,9,4,9,2,1},
        {9,8,5,6,7,8,9,8,9,2},
        {8,7,6,7,8,9,6,7,8,9},
        {9,8,9,9,9,6,5,6,7,8}
    };

    struct LoadedConstTestHeightmapSystem : testing::Test {
        const day9::HeightmapSystem heightmapSystem{"../data/day9/input_test.txt"};
    };

    struct LoadedTestHeightmapSystem : testing::Test {
        day9::HeightmapSystem heightmapSystem{"../data/day9/input_test.txt"};
    };
}

TEST(HeightmapSystemClass, CreatingClassWithGivenHeightmapFile) {
    const std::string filepath{"../data/day9/input_test.txt"};

    const day9::HeightmapSystem heightmapSystem{filepath};
    EXPECT_EQ(testHeightmap, heightmapSystem.getHeightmap());
}

TEST_F(LoadedConstTestHeightmapSystem, FindingLowPointsInTopLine) {
    const std::vector<short> wantLowPoints{1,0};
    EXPECT_EQ(wantLowPoints, heightmapSystem.findLowPointsInLine(0));
}

TEST_F(LoadedConstTestHeightmapSystem, FindingAllLowPointsInHeightmap) {
    const std::vector<short> wantLowPoints{1, 0, 5, 5};
    EXPECT_EQ(wantLowPoints, heightmapSystem.findLowPoints());
}

TEST_F(LoadedConstTestHeightmapSystem, CalculateRiskLevels) {
    const std::vector<short> lowPoints{1, 0, 5, 5};
    const std::vector<short> wantRiskLevels{2, 1, 6, 6};
    EXPECT_EQ(wantRiskLevels, heightmapSystem.calculateRiskLevels(lowPoints));
}

TEST_F(LoadedConstTestHeightmapSystem, InitialInstanceShouldReturnEmptyBasinMap) {
    EXPECT_EQ(0, heightmapSystem.getBasinMap().size());
}

TEST_F(LoadedTestHeightmapSystem, TestHighmapShouldGive35Points) {
    heightmapSystem.findBasins();
    EXPECT_EQ(35, heightmapSystem.getBasinMap().size());
}

TEST_F(LoadedTestHeightmapSystem, TestHighmapShouldGive4Basins) {
    heightmapSystem.findBasins();
    const auto basinsSizes{heightmapSystem.getBasinsSizes()};

    EXPECT_EQ(4, basinsSizes.size());
    EXPECT_EQ(14, basinsSizes[2]);
}

TEST_F(LoadedTestHeightmapSystem, Top3LargestBasinSizes) {
    heightmapSystem.findBasins();
    auto basinsSizes{heightmapSystem.getBasinsSizes()};
    std::sort(std::begin(basinsSizes), std::end(basinsSizes), std::greater<size_t>());
    const auto top3LargestSizes{std::views::all(basinsSizes) | std::views::take(3)};

    EXPECT_EQ(3, top3LargestSizes.size());
    EXPECT_EQ(14, top3LargestSizes[0]);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
