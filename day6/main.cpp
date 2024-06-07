#include "day6.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filepath{"../data/day6/input.txt"};
    day6::Lanterfishes fishes{day6::extractDataFromFile(filepath)};

    day6::processNDays(fishes, 80);
    std::cout
        << "The answer for Day 6 (part one) is: "
        << fishes.size()
        << std::endl;

    day6::Lanterfishes fishes2{day6::extractDataFromFile(filepath)};

    day6::processNDays(fishes, 256);
    std::cout
        << "The answer for Day 6 (part one) is: "
        << fishes2.size()
        << std::endl;

    return 0;
}
