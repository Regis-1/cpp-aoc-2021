#include "day2.hpp"

int main (int argc, char *argv[]) {
    const std::string filePath {"../data/day2/input.txt"};
    auto courseCommands {extractInputCommands(filePath)};

    Submarine sbm;
    sbm.ExecutePlannedCourse(courseCommands);
    std::cout
        << "The answer for the Day2 (part one) is: "
        << sbm.GetPosition() * sbm.GetDepth()
        << std::endl;
    
    AimedSubmarine asbm;
    asbm.ExecutePlannedCourse(courseCommands);
    std::cout
        << "The answer for the Day2 (part two) is: "
        << asbm.GetPosition() * asbm.GetDepth()
        << std::endl;
    
    return 0;
}
