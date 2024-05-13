#include <gtest/gtest.h>

#include "day3.hpp"

void checkGammaRate(const std::string want, const DiagData& data) {
    EXPECT_EQ(want, getGammaRateFromData(data));
}

void checkEpsilonRate(const std::string want, const std::string gamma) {
    EXPECT_EQ(want, getEpsilonRateFromGamma(gamma));
}

void checkBinConversion(const int want, const std::string bin) {
    EXPECT_EQ(want, binToDec(bin));
}

void checkFilterDiag(const std::string want, const DiagData& data, const bool mostCommonMode) {
    EXPECT_EQ(want, getAdvancedRating(data, mostCommonMode));
}

TEST(Day3_PartOne, InputExtraction_WrongFilePath) {
    const std::string filePath {"../data/day3/wrong.txt"};

    EXPECT_THROW(extractInputData(filePath), std::system_error);
}

TEST(Day3_PartOne, InputExtraction_ExtractTestData) {
    const std::string filePath {"../data/day3/input_test.txt"};
    size_t expectedRows {12};
    size_t expectedCols {5};

    DiagData data {extractInputData(filePath)};
    
    ASSERT_EQ(expectedCols, data.size());
    ASSERT_EQ(expectedRows, data[0].size());
    EXPECT_EQ('1', data[3][3]);
}

TEST(Day3_PartOne, TaskResolution_GetGammaRateBinarySimple) {
    const DiagData data {
        {'1', '0', '1'}, {'0', '1', '1'}, {'0', '0', '0'}};
    checkGammaRate("110", data);
}

TEST(Day3_PartOne, TaskResolution_GetGammaRateBinaryAoCTest) {
    checkGammaRate("10110", extractInputData("../data/day3/input_test.txt"));
}

TEST(Day3_PartOne, TaskResolution_GetEpsilonRateFromGammaSimple) {
    checkEpsilonRate("001", "110");
}

TEST(Day3_PartOne, TaskResolution_GetEpsilonRateFromGammaAoCTest) {
    checkEpsilonRate("01001", "10110");
}

TEST(Day3_PartOne, TranslateBinaryToDecimalOne) {
    checkBinConversion(22, "10110");
}

TEST(Day3_PartOne, TranslateBinaryToDecimalTwo) {
    checkBinConversion(9, "01001");
}

TEST(Day3_PartTwo, FilterDiagO2Simple) {
    const DiagData data {
        {'1', '0', '1', '1'}, {'0', '1', '1', '0'}, {'0', '0', '0', '1'}};
    checkFilterDiag("101", data, true);
}

TEST(Day3_PartTwo, FilterDiagO2AoCTest) {
    const DiagData data {extractInputData("../data/day3/input_test.txt")};
    checkFilterDiag("10111", data, true);
}

TEST(Day3_PartTwo, FilterDiagCO2Simple) {
    const DiagData data {
        {'1', '0', '1', '1'}, {'0', '1', '1', '0'}, {'0', '0', '0', '1'}};
    checkFilterDiag("010", data, false);
}

TEST(Day3_PartTwo, FilterDiagCO2AoCTest) {
    checkFilterDiag("01010", extractInputData("../data/day3/input_test.txt"), false);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
