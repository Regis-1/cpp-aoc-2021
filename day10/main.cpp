#include "day10.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day10/input.txt"};
    const std::vector<std::string> navigationCode{day10::extractNavigationCode(filepath)};

    const day10::ErrorLines errorScores{day10::checkNavigationCodeErrors(navigationCode)};
    const int total{std::accumulate(errorScores.begin(), errorScores.end(), 0,
        [](unsigned int result, day10::ErrorLine item){
            return result + item.second;
        }
    )};

    std::cout
        << "The answer for the Day 10 (part one) is: "
        << total
        << std::endl;

    const day10::IncompleteLines incmpLines{day10::checkNavigationCodeIncomplete(navigationCode)};
    std::vector<unsigned long> autocmpTotals;
    for (const auto& l : incmpLines)
        autocmpTotals.push_back(day10::calculateAutocmpScores(l.second));
    std::sort(autocmpTotals.begin(), autocmpTotals.end());

    std::cout
        << "The answer for the Day 10 (part two) is: "
        << autocmpTotals[autocmpTotals.size()/2]
        << std::endl;

}
