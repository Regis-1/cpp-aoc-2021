#include "day5.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filePath {"../data/day5/input.txt"};
    const auto completeVentDiagram {
        day5::createVentDiagram(day5::loadInputFromFile(filePath))
    };

    std::cout
        << "The answer for the Day5 (part one is: "
        << day5::countOverlapPoints(completeVentDiagram)
        << std::endl;

    return 0;
}
