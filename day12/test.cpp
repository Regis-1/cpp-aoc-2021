#include <gtest/gtest.h>

#include "day12.hpp"

/*
 * Plan:
 *  1. Use polimorphism:
 *   - Cave super class and derived StartCave, EndCave, SmallCave, BigCave
 *   - Each extracted cave will have routes to other caves and identifier and flag isVisited (e.g.)
 *  2. Map caves in unordered map as a storage of them for simple lookup
 *  3. Start pathfinding from StartCave
 *  4. Need to create copies of the state of pathfinding to then have clear routes
 */

namespace {
day12::CaveMap testCaveMap{
};
}

TEST(Input, ExtractCaveMapShouldThrowIfInvalidFile) {
    const std::string wrongPath{"../data/day12/wrong_file.txt"};

    EXPECT_THROW(day12::extractCaveMapFromFile(wrongPath), std::runtime_error);
}

TEST(Input, ExtractCaveMapFromInputFile) {
    const std::string inputPath{"../data/day12/input_test.txt"};
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
