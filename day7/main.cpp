#include "day7.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day7/input.txt"};
    const day7::CrabsPositions crabs{day7::extractCrabsPositions(filepath)};

    std::cout
        << "The answer for Day 7 (part one) is: "
        << day7::evaluateFuelLinear(crabs, day7::getOptimalPosition(crabs, day7::MethodType::MEDIAN))
        << std::endl;

    std::cout
        << "The answer for Day 7 (part two) is: "
        << day7::evaluateFuelNonLin(crabs, day7::getOptimalPosition(crabs, day7::MethodType::MEAN))
        << std::endl;

    return 0;
}
