#include <gtest/gtest.h>

#include "day7.hpp"

TEST(ExtractInput, getAllCrabsPositions) {
    const std::string filepath{"../data/day7/input_test.txt"};
    const day7::CrabsPositions want{16,1,2,0,4,2,7,1,2,14};
    
    EXPECT_EQ(want, day7::extractCrabsPositions(filepath));
}

TEST(FindingOptimalPosition, gettingMedianaFromAllPosAocTest) {
    const day7::CrabsPositions crabs{16,1,2,0,4,2,7,1,2,14};
    const unsigned int want{2};
    EXPECT_EQ(want, day7::getOptimalPosition(crabs, day7::MethodType::MEDIAN));
}

TEST(FindingOptimalPosition, gettingMeanOptimalFromAocTest) {
    const day7::CrabsPositions crabs{16,1,2,0,4,2,7,1,2,14};
    const unsigned int want{5};
    EXPECT_EQ(want, day7::getOptimalPosition(crabs, day7::MethodType::MEAN));
}

TEST(FindingOptimalPosition, calculatingFuelAocTest) {
    const day7::CrabsPositions crabs{16,1,2,0,4,2,7,1,2,14};
    const unsigned int pos{2};
    const unsigned int wantFuel{37};
    EXPECT_EQ(wantFuel, day7::evaluateFuelLinear(crabs, pos));
}

TEST(AllComponents, FullMedianFlowAocTest) {
    const std::string filepath{"../data/day7/input_test.txt"};
    const unsigned int wantFuel{37};

    const day7::CrabsPositions cpos{day7::extractCrabsPositions(filepath)};
    const unsigned int gotFuel{day7::evaluateFuelLinear(cpos, day7::getOptimalPosition(cpos, day7::MethodType::MEDIAN))};
    EXPECT_EQ(wantFuel, gotFuel);
}

TEST(AllComponents, FullMeanFlowAocTest) {
    const std::string filepath{"../data/day7/input_test.txt"};
    const unsigned int wantFuel{168};

    const day7::CrabsPositions cpos{day7::extractCrabsPositions(filepath)};
    const unsigned int gotFuel{day7::evaluateFuelNonLin(cpos, day7::getOptimalPosition(cpos, day7::MethodType::MEAN))};
    EXPECT_EQ(wantFuel, gotFuel);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
