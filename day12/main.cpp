#include "day12.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string inputPath{"../data/day12/input.txt"};
    day12::CaveMap inputCaveMap{day12::extractCaveMapFromFile(inputPath)};

    const std::vector<Routes> allPossibleRoutes{day12::findAllRoutes(inputCaveMap)};
    std::cout
        << "The answer for the Day 12 (part one) is: "
        << allPossibleRoutes.size()
        << std::endl;

    day12::CaveMap inputCaveMap2{day12::extractCaveMapFromFile(inputPath)};
    const std::vector<Routes> allPossibleRoutes2{day12::findAllRoutesWithOneTwiceVisit(inputCaveMap)};
    std::cout
        << "The answer for the Day 12 (part two) is: "
        << allPossibleRoutes2.size()
        << std::endl;

    return 0;
}
