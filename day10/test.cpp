#include <gtest/gtest.h>

#include "day10.hpp"

namespace {
    const std::vector<std::string> testNavigationCode{
        "[({(<(())[]>[[{[]{<()<>>",
        "[(()[<>])]({[<{<<[]>>(",
        "{([(<{}[<>[]}>{[]{[(<()>",
        "(((({<>}<{<{<>}{[]{[]{}",
        "[[<[([]))<([[{}[[()]]]",
        "[{[{({}]{}}([{[{{{}}([]",
        "{<[[]]>}<{[{[{[]{()[[[]",
        "[<(<(<(<{}))><([]([]()",
        "<{([([[(<>()){}]>(<<{{",
        "<{([{{}}[<[[[<>{}]]]>[]]"
    };

    const std::vector<std::vector<unsigned short>> testAutocompleteLines{
        {3,3,2,2,1,3,1,2},
        {1,3,4,2,3,1},
        {3,3,4,3,4,1,1,1,1},
        {2,2,3,3,2,3,2,3,4},
        {2,1,3,4},
    };
} 

TEST(ExtractingInput, GetLinesFromInputFile) {
    const std::string filepath{"../data/day10/input_test.txt"};
    EXPECT_EQ(testNavigationCode, day10::extractNavigationCode(filepath));
}

TEST(CheckingLines, CheckOneInvalidLineErrors) {
    const std::string &invalidLine{testNavigationCode[2]};
    const std::string &incompleteLine{testNavigationCode[0]};

    EXPECT_EQ(1197, day10::checkLineErrors(invalidLine));
    EXPECT_EQ(0, day10::checkLineErrors(incompleteLine));
}

TEST(CheckingCode, CheckAllNavigationCodeErrors) {
    const std::vector<unsigned short> wantScores{3, 3, 57, 1197, 25137};
    const auto errorLines{day10::checkNavigationCodeErrors(testNavigationCode)};

    ASSERT_EQ(wantScores.size(), errorLines.size());
    for (auto i{0}; i < errorLines.size(); ++i)
        EXPECT_EQ(wantScores[i], errorLines[i].second);
}

TEST(CheckingCode, CheckAllNavigationCodeIncomplete) {
    const auto incompleteLines{day10::checkNavigationCodeIncomplete(testNavigationCode)};

    ASSERT_EQ(testAutocompleteLines.size(), incompleteLines.size());
    for (auto i{0}; i < incompleteLines.size(); ++i)
        EXPECT_EQ(testAutocompleteLines[i], incompleteLines[i].second);
}

TEST(CheckingCode, CalculatingTotalAutocompleteScore) {
    const std::vector<unsigned int> wantScores{288957, 5566, 1480781, 995444, 294};
    for (auto i{0}; i < wantScores.size(); ++i)
        EXPECT_EQ(wantScores[i], day10::calculateAutocmpScores(testAutocompleteLines[i]));
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
