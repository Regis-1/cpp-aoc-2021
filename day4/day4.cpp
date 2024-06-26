#include "day4.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>

#include "BingoCard.hpp"

BingoSubsysOutput extractInput(std::istream& is) {
    std::string line;
    std::getline(is, line);
    const std::vector<int> numbers {utils::extractNumbersBySeparator(line, ',')};

    std::vector<BingoCard> cards;
    std::stringstream ss;
    while (std::getline(is, line))
        if (line == "") {
            for (auto i {0}; i < 5; ++i) {
                std::getline(is, line);
                ss << line << "\n";
            }
            cards.push_back({ss.str()});
            ss.str("");
        }

    return {numbers, cards};
}

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

BingoSubsysOutput getBingoAll(const std::string& input, const bool& isFilePath) {
    if (isFilePath) {
        std::ifstream fd(input);
        if (fd.fail() or fd.bad())
            throw std::system_error(std::error_code(), "Wrong filepath or the file is invalid!");

        return extractInput(fd);
    }
    else {
        std::istringstream iss(input);
        return extractInput(iss);
    }
}

const int evaluateGame(BingoSubsysOutput &bso, const bool& lastCardWin) {
    std::unordered_map<int, int> cardScores;
    int lastWon;
    int cardCounter {0};
    for (auto n : bso.first) {
        for (auto& bc : bso.second) {
            if (auto search {cardScores.find(cardCounter)}; search != std::end(cardScores)) {
                ++cardCounter;
                continue;
            }
            try {
                bc.markNum(n);
                if (bc.checkWin()) {
                    if (!lastCardWin) {
                        return bc.checkScore(n);
                    }
                    else {
                        cardScores[cardCounter] = bc.checkScore(n);
                        lastWon = cardCounter;
                    }
                }

            } catch (const std::exception& e) {}
            ++cardCounter;
        }
        cardCounter = 0;
    }

    if (lastCardWin)
        return cardScores[lastWon];

    return -1;
}
}
