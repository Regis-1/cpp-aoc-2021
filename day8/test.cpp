#include <gtest/gtest.h>

#include "day8.hpp"

namespace {
const std::vector<std::string> testDigits{
    "fdgacbe", "cefdb", "cefbgd", "gcbe", "fcgedb", "cgb", "dgebacf", "gc",
    "cg", "cg", "fdcagb", "cbg", "efabcd", "cedba", "gadfec", "cb",
    "gecf", "egdcabf", "bgf", "bfgea", "gebdcfa", "ecba", "ca", "fadegcb",
    "cefg", "dcbef", "fcge", "gbcadfe", "ed", "bcgafe", "cdgba", "cbgef",
    "gbdfcae", "bgc", "cg", "cgb", "fgae", "cfgab", "fg", "bagce"
};
}

TEST(ExtractingDisplayDigits, GettingAllDigitsSeparated) {
    const std::string inputPath{"../data/day8/input_test.txt"};
    EXPECT_EQ(testDigits, day8::extractDisplayDigitsFromInputFile(inputPath));
}

TEST(CountingDigitsBySegments, CountingDigitsWith2Segments) {
    const size_t  wantCount{8};
    EXPECT_EQ(wantCount, day8::countDigitsWithNSegments(testDigits, {2}));
}

TEST(CountingDigitsBySegments, CountingDigitsFromAocTest) {
    const size_t wantCount{26};
    EXPECT_EQ(wantCount, day8::countDigitsWithNSegments(testDigits, {2, 3, 4, 7}));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
