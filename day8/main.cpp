#include "day8.hpp"
#include <iostream>
#include <numeric>

int main (int argc, char *argv[]) {
    const std::string inputPath{"../data/day8/input.txt"};

    std::cout
        << "The answer to Day 8 (part one) is: "
        << day8::countDigitsWithNSegments(day8::extractDisplayDigitsFromInputFile(inputPath), {2, 3, 4, 7})
        << std::endl;

    const auto decodedNumbers{day8::decodeSignals(day8::extractSignalsAndDigitsFromInputFile(inputPath))};
    std::cout
        << "The answer to Day 8 (part two) is: "
        << std::accumulate(std::begin(decodedNumbers), std::end(decodedNumbers), 0)
        << std::endl;

    return 0;
}
