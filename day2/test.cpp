#include <gtest/gtest.h>

#include "day2.hpp"

TEST(Day2_Task, ExtractingInputCommands_WrongFilePath) {
    const std::string filePath {"../data/day2/wrong_file.txt"};
    EXPECT_THROW(extractInputCommands(filePath), std::system_error);
}

TEST(Day2_Task, ExtractingInputCommands_TestInput) {
    const std::string filePath {"../data/day2/input_test.txt"};
    std::vector<Command> wantCommands {
        {Move::Forward, 5}, {Move::Down, 5}, {Move::Forward, 8},
        {Move::Up, 3}, {Move::Down, 8}, {Move::Forward, 2}
    };
    
    std::vector<Command> gotCommands {extractInputCommands(filePath)};

    EXPECT_EQ(wantCommands.size(), gotCommands.size());
    EXPECT_EQ(wantCommands[0].move, gotCommands[0].move);
    EXPECT_EQ(wantCommands[0].amount, gotCommands[0].amount);
}

TEST(Day2_Task, ExecutingCommands_ExecuteOneCommand) {
    Submarine sbm;
    Command cmd {Move::Forward, 3};
    sbm.ExecuteMoveCommand(cmd);

    EXPECT_EQ(3, sbm.GetPosition());
}

TEST(Day2_Task, ExecutingCourse_AoCCourse) {
    const std::string filePath {"../data/day2/input_test.txt"};
    unsigned int wantPosition {15};
    unsigned int wantDepth {10};
    auto courseCommands {extractInputCommands(filePath)};
    Submarine sbm;
    sbm.ExecutePlannedCourse(courseCommands);
    auto gotPosition = sbm.GetPosition();
    auto gotDepth = sbm.GetDepth();

    EXPECT_EQ(wantPosition, gotPosition);
    EXPECT_EQ(wantDepth, gotDepth);
}

TEST(Day2_Task, AimedSubmarine_AoCCourse) {
    const std::string filePath {"../data/day2/input_test.txt"};
    unsigned int wantPosition {15};
    unsigned int wantDepth {60};
    auto courseCommands {extractInputCommands(filePath)};
    AimedSubmarine sbm;
    sbm.ExecutePlannedCourse(courseCommands);
    auto gotPosition = sbm.GetPosition();
    auto gotDepth = sbm.GetDepth();

    EXPECT_EQ(wantPosition, gotPosition);
    EXPECT_EQ(wantDepth, gotDepth);
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
