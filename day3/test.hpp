#include <gtest/gtest.h>

#include "day3.hpp"

TEST(Day3_Task, InputExtraction_WrongFilePath) {
    const std::string filePath {"../data/day3/wrong.txt"};

    EXPECT_THROW(extractInputData(filePath), std::system_error);
}

TEST(Day3_Task, InputExtraction_ExtractTestData) {
    const std::string filePath {"../data/day3/input_test.txt"};
    size_t expectedRows {12};
    size_t expectedCols {5};

    std::vector<std::vector<char>> data {extractInputData(filePath)};
    
    EXPECT_EQ(expectedRows, data.size());
    EXPECT_EQ(expectedCols, data[0].size());
    EXPECT_EQ('1', data[3][3]);
}
