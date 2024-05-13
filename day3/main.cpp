#include "day3.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string filePath {"../data/day3/input.txt"};
    DiagData data {extractInputData(filePath)};

    const std::string gammaRateBin {getGammaRateFromData(data)};
    const std::string epsilonRateBin {getEpsilonRateFromGamma(gammaRateBin)};

    std::cout
        << "The answer for the Day3 (part one) is: "
        << binToDec(gammaRateBin) * binToDec(epsilonRateBin)
        << std::endl;

    const std::string O2Rating {getAdvancedRating(data, true)};
    const std::string CO2Rating {getAdvancedRating(data, false)};
    std::cout
        << "The answer for the Day3 (part two) is: "
        << binToDec(O2Rating) * binToDec(CO2Rating)
        << std::endl;
    
    return 0;
}
