#include "day4.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filePath {"../data/day4/input.txt"};
    BingoSubsysOutput bso {utils::getBingoAll(filePath, true)}; 

    std::cout
        << "The answer for the Day4 (part one) is: "
        << utils::evaluateGame(bso)
        << std::endl;

    std::cout
        << "The answer for the Day4 (part two) is: "
        << utils::evaluateGame(bso, true)
        << std::endl;

    return 0;
}
