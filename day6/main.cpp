#include "day6.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day6/input.txt"};
    day6::Lanterfish fish{day6::groupFish(day6::extractDataFromFile(filepath))};

    day6::processNDays(fish, 80);
    std::cout
        << "The answer for Day 6 (part one) is: "
        << day6::countFish(fish)
        << std::endl;

    day6::Lanterfish fish2{day6::groupFish(day6::extractDataFromFile(filepath))};

    day6::processNDays(fish2, 256);
    std::cout
        << "The answer for Day 6 (part one) is: "
        << day6::countFish(fish2)
        << std::endl;

    return 0;
}
