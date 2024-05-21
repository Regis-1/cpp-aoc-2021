#include "day4.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "BingoCard.hpp"

namespace utils {
    const std::vector<int> extractNumbersBySeparator(const std::string& input, const char& sep) {
        std::istringstream iss(input);
        std::vector<int> result;

        for (std::string token; getline(iss, token, sep);) {
            try {
                result.push_back(std::stoi(token));
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return result;
            }
        }

        return result;
    }

    BingoSubsysOutput extractBingoOrderAndCards(const std::string& filePath) {
        std::ifstream fd(filePath);
        if (fd.fail() or fd.bad())
            throw std::system_error(std::error_code(), "Wrong filepath or the file is invalid!");

        std::vector<BingoCard> cards;
        const auto numbers {extractNumbersBySeparator("", ',')};

        return {numbers, cards};
    }
}
