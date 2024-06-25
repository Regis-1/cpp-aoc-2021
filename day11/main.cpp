#include "day11.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string inputPath{"../data/day11/input.txt"};
    auto octoGrid{day11::extractOctopusGridFromFile(inputPath)};

    std::cout
        << "The answer for the Day 11 (part one) is: "
        << day11::runCycle(octoGrid, 100)
        << std::endl;

    octoGrid = day11::extractOctopusGridFromFile(inputPath);
    std::cout
        << "The answer for the Day 11 (part two) is: "
        << day11::runCycleUntilFlashCount(octoGrid, 100)
        << std::endl;

    return 0;
}
