#include "day5.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filePath {"../data/day5/input.txt"};
    const auto completeVentDiagramHV {
        day5::createVentDiagram(day5::loadInputFromFile(filePath), day5::getCoordsHVOnly)
    };
    const auto completeVentDiagramDiag {
        day5::createVentDiagram(day5::loadInputFromFile(filePath), day5::getCoordsDiagonals)
    };

    std::cout
        << "The answer for the Day5 (part one) is: "
        << day5::countOverlapPoints(completeVentDiagramHV)
        << std::endl;

    std::cout
        << "The answer for the Day5 (part two) is: "
        << day5::countOverlapPoints(completeVentDiagramDiag)
        << std::endl;

    return 0;
}
