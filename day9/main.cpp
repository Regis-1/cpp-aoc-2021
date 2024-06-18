#include "day9.hpp"
#include <iostream>
#include <numeric>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day9/input.txt"};
    const day9::HeightmapSystem heightmapSystem{filepath};

    const std::vector<short> riskLevels{heightmapSystem.calculateRiskLevels(heightmapSystem.findLowPoints())};
    std::cout
        << "The answer for the Day 5 (part one) is: "
        << std::accumulate(std::begin(riskLevels), std::end(riskLevels), 0)
        << std::endl;

    return 0;
}
