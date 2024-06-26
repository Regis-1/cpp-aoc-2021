#include <gtest/gtest.h>
#include <memory>

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
day12::CaveMap makeTestCaveMap() {
    day12::CaveMap resMap;
    resMap["start"] = std::make_unique<StartCave>(Routes{"A", "b"});
    resMap["A"] = std::make_unique<BigCave>(Routes{"start", "c", "b", "end"});
    resMap["b"] = std::make_unique<SmallCave>(Routes{"start", "A", "d", "end"});
    resMap["c"] = std::make_unique<SmallCave>(Routes{"A"});
    resMap["d"] = std::make_unique<SmallCave>(Routes{"b"});
    resMap["end"] = std::make_unique<EndCave>();

    return resMap;
};

std::vector<Routes> allTestRoutes{
    {"start","A","b","A","c","A","end"},
    {"start","A","b","A","end"},
    {"start","A","b","end"},
    {"start","A","c","A","b","A","end"},
    {"start","A","c","A","b","end"},
    {"start","A","c","A","end"},
    {"start","A","end"},
    {"start","b","A","c","A","end"},
    {"start","b","A","end"},
    {"start","b","end"},
};
}

TEST(Input, ExtractCaveMapShouldThrowIfInvalidFile) {
    const std::string wrongPath{"../data/day12/wrong_file.txt"};

    EXPECT_THROW(day12::extractCaveMapFromFile(wrongPath), std::runtime_error);
}

TEST(Input, ExtractCaveMapFromInputFile) {
    const day12::CaveMap wantMap{makeTestCaveMap()};
    const std::string inputPath{"../data/day12/input_test.txt"};
    const day12::CaveMap gotMap{day12::extractCaveMapFromFile(inputPath)};

    ASSERT_EQ(wantMap.size(), gotMap.size());
    for (auto& c : wantMap)
        EXPECT_EQ(c.second->getRoutes(), gotMap.at(c.first)->getRoutes());
}

TEST(Pathfinding, FindAllPossibleRoutes) {
    const day12::CaveMap wantMap{makeTestCaveMap()};
    const std::vector<Routes> gotAllRoutes{day12::findAllRoutes()};

    EXPECT_EQ(allTestRoutes, gotAllRoutes);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
