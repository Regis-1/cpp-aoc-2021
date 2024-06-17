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

const std::vector<day8::SignalsAndDigits> testSignalsAndDigits{
    {{"be", "cfbegad", "cbdgef", "fgaecd", "cgeb", "fdcge", "agebfd", "fecdb", "fabcd", "edb"}, {"fdgacbe", "cefdb", "cefbgd", "gcbe"}},
    {{"edbfga", "begcd", "cbg", "gc", "gcadebf", "fbgde", "acbgfd", "abcde", "gfcbed", "gfec"}, {"fcgedb", "cgb", "dgebacf", "gc"}},
    {{"fgaebd", "cg", "bdaec", "gdafb", "agbcfd", "gdcbef", "bgcad", "gfac", "gcb", "cdgabef"}, {"cg", "cg", "fdcagb", "cbg"}},
    {{"fbegcd", "cbd", "adcefb", "dageb", "afcb", "bc", "aefdc", "ecdab", "fgdeca", "fcdbega"}, {"efabcd", "cedba", "gadfec", "cb"}},
    {{"aecbfdg", "fbg", "gf", "bafeg", "dbefa", "fcge", "gcbea", "fcaegb", "dgceab", "fcbdga"}, {"gecf", "egdcabf", "bgf", "bfgea"}},
    {{"fgeab", "ca", "afcebg", "bdacfeg", "cfaedg", "gcfdb", "baec", "bfadeg", "bafgc", "acf"}, {"gebdcfa", "ecba", "ca", "fadegcb"}},
    {{"dbcfg", "fgd", "bdegcaf", "fgec", "aegbdf", "ecdfab", "fbedc", "dacgb", "gdcebf", "gf"}, {"cefg", "dcbef", "fcge", "gbcadfe"}},
    {{"bdfegc", "cbegaf", "gecbf", "dfcage", "bdacg", "ed", "bedf", "ced", "adcbefg", "gebcd"}, {"ed", "bcgafe", "cdgba", "cbgef"}},
    {{"egadfb", "cdbfeg", "cegd", "fecab", "cgb", "gbdefca", "cg", "fgcdab", "egfdb", "bfceg"}, {"gbdfcae", "bgc", "cg", "cgb"}},
    {{"gcafb", "gcf", "dcaebfg", "ecagb", "gf", "abcdeg", "gaef", "cafbge", "fdbac", "fegbdc"}, {"fgae", "cfgab", "fg", "bagce"}}
};
}

TEST(Extracting, GettingAllDigitsSeparated) {
    const std::string inputPath{"../data/day8/input_test.txt"};
    EXPECT_EQ(testDigits, day8::extractDisplayDigitsFromInputFile(inputPath));
}

TEST(Extracting, GettingAllSignalsAndDigits) {
    const std::string inputPath{"../data/day8/input_test.txt"};
    EXPECT_EQ(testSignalsAndDigits, day8::extractSignalsAndDigitsFromInputFile(inputPath));
}

TEST(CountingDigitsBySegments, CountingDigitsWith2Segments) {
    const size_t  wantCount{8};
    EXPECT_EQ(wantCount, day8::countDigitsWithNSegments(testDigits, {2}));
}

TEST(CountingDigitsBySegments, CountingDigitsFromAocTest) {
    const size_t wantCount{26};
    EXPECT_EQ(wantCount, day8::countDigitsWithNSegments(testDigits, {2, 3, 4, 7}));
}

TEST(AnalyzingSignals, DecodingSignalValuesLine) {
    const day8::SignalsAndDigits inputLine{
        {"acedgfb", "cdfbe", "gcdfa", "fbcad", "dab", "cefabd", "cdfgeb", "eafb", "cagedb", "ab"}, {"cdfeb", "fcadb", "cdfeb", "cdbaf"}
    };
    const int want{5353};
    EXPECT_EQ(want, day8::decodeSignalLine(inputLine));
}

TEST(AnalyzingSignals, DecodingAllTestSignals) {
    const std::vector<int> wantDecoded{8394 ,9781 ,1197 ,9361 ,4873 ,8418 ,4548 ,1625 ,8717 ,4315};
    EXPECT_EQ(wantDecoded, day8::decodeSignals(testSignalsAndDigits));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
