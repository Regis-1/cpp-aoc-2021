#include "day8.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string inputPath{"../data/day8/input.txt"};

    std::cout
        << "The answer to Day 8 (part one) is: "
        << day8::countDigitsWithNSegments(day8::extractDisplayDigitsFromInputFile(inputPath), {2, 3, 4, 7})
        << std::endl;

    return 0;
}
