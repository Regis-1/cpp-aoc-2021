#include "day4.hpp"

#include <sstream>
#include <string>
#include <iostream>

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
}
