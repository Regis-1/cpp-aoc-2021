#include "day1.hpp"

int main(int argc, char* argv[]) {
    auto inputValues {extractInputValues("../data/day1/input.txt")};

    int increaseCount {countIncreases(inputValues)};
    std::cout
        << "The answer for the Day1 (part one) is: " << increaseCount << "."
        << std::endl;

    int slidingWindowCount {countIncreases(inputValues, 3)};
    std::cout
        << "The answer for the Day1 (part one) is: " << slidingWindowCount << "."
        << std::endl;

    return 0;
}
