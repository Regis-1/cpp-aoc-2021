#include "day1.hpp"

int main(int argc, char* argv[]) {
    auto inputValues {extractInputValues("../data/day1/input.txt")};
    int increaseCount {countIncreases(inputValues)};

    std::cout
        << "The answer for the Day1 is: " << increaseCount << "."
        << std::endl;

    return 0;
}
