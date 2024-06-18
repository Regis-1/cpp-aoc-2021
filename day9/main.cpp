#include "day9.hpp"
#include <iostream>
#include <numeric>
#include <ranges>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day9/input.txt"};
    day9::HeightmapSystem heightmapSystem{filepath};

    const std::vector<short> riskLevels{heightmapSystem.calculateRiskLevels(heightmapSystem.findLowPoints())};
    std::cout
        << "The answer for the Day 5 (part one) is: "
        << std::accumulate(std::begin(riskLevels), std::end(riskLevels), 0)
        << std::endl;

    heightmapSystem.findBasins();
    std::vector<size_t> basinsSizes{heightmapSystem.getBasinsSizes()};
    std::sort(std::begin(basinsSizes), std::end(basinsSizes), std::greater<size_t>());
    const auto top3BasinsSizesView{std::views::all(basinsSizes) | std::views::take(3)};
    std::cout
        << "The answer for the Day 5 (part two) is: "
        << std::accumulate(std::begin(top3BasinsSizesView), std::end(top3BasinsSizesView), 1, std::multiplies<size_t>())
        << std::endl;

    return 0;
}
