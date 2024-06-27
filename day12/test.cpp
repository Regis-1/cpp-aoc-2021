#include <gtest/gtest.h>

#include "Caves.hpp"
#include "day12.hpp"

namespace {
day12::CaveMap makeTestCaveMap() {
    day12::CaveMap resMap;
    resMap.emplace("start", Cave{CaveType::Start, Routes{"A", "b"}});
    resMap.emplace("A", Cave{CaveType::Big, Routes{"start", "c", "b", "end"}});
    resMap.emplace("b", Cave{CaveType::Small, Routes{"start", "A", "d", "end"}});
    resMap.emplace("c", Cave{CaveType::Small, Routes{"A"}});
    resMap.emplace("d", Cave{CaveType::Small, Routes{"b"}});
    resMap.emplace("end", Cave{CaveType::End, Routes{"A", "b"}});

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
        EXPECT_EQ(c.second.routes, gotMap.at(c.first).routes);
}

TEST(Pathfinding, FindAllPossibleTestRoutes) {
    day12::CaveMap wantMap{makeTestCaveMap()};
    const std::vector<Routes> gotAllRoutes{day12::findAllRoutes(wantMap)};

    EXPECT_EQ(allTestRoutes.size(), gotAllRoutes.size());
}

TEST(Pathfinding, FindAllPossibleTestRoutesWithOneTwiceVisit) {
    day12::CaveMap wantMap{makeTestCaveMap()};
    const std::vector<Routes> gotAllRoutes{day12::findAllRoutesWithOneTwiceVisit(wantMap)};

    EXPECT_EQ(36, gotAllRoutes.size());
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
