#include "day10.hpp"
#include <algorithm>
#include <fstream>
#include <stack>
#include <vector>

namespace {
const std::unordered_map<char, char> ChunkClosingMap{
    {'(',')'}, {'[',']'}, {'{','}'}, {'<','>'}};

const std::vector<std::string> extractLinesFromFile(std::ifstream &fd) {
    std::vector<std::string> lines;

    for (std::string line; std::getline(fd, line);)
        lines.push_back(line);

    fd.close();
    return lines;
}
}

namespace day10 {
const std::vector<std::string> extractNavigationCode(const std::string &filepath) {
    std::ifstream fd(filepath);

    if (fd.bad()) {
        throw std::runtime_error("There is something wrong with given file.");
    }

    return extractLinesFromFile(fd);
}

const unsigned short checkLineErrors(const std::string &line) {
    std::stack<char> symbolStack;
    unsigned short retValue{0};
    for (const auto &c : line)
        if (ChunkClosingMap.find(c) != ChunkClosingMap.end()) {
            ChunkClosingMap.at(c);
            symbolStack.push(c);
        }
        else {
            if (!symbolStack.empty() and c == ChunkClosingMap.at(symbolStack.top())) {
                symbolStack.pop();
            }
            else {
                retValue = SyntaxErrorScoringMap.at(c);
                break;
            }
        }

    return retValue;
}

const ErrorLines checkNavigationCodeErrors(const std::vector<std::string> &navCode) {
    ErrorLines errorLines;

    unsigned int idx{0};
    for (const auto& line : navCode) {
        errorLines.push_back({idx, checkLineErrors(line)});
        ++idx;
    }

    std::sort(errorLines.begin(), errorLines.end(),
        [](const ErrorLine &a, const ErrorLine &b) {
            return a.second < b.second;
        }
    );

    errorLines.erase(std::remove_if(errorLines.begin(), errorLines.end(),
        [](const ErrorLine &l) {
            return l.second == 0;
        }),
        errorLines.end()
    );

    return errorLines;
}

const std::vector<unsigned short> checkLineIncomplete(const std::string &line) {
    std::stack<char> symbolStack;
    std::vector<unsigned short> retVec;
    for (const auto &c : line)
        if (ChunkClosingMap.find(c) != ChunkClosingMap.end()) {
            ChunkClosingMap.at(c);
            symbolStack.push(c);
        }
        else {
            if (!symbolStack.empty() and c == ChunkClosingMap.at(symbolStack.top())) {
                symbolStack.pop();
            }
            else {
                return {};
            }
        }

    for (char opening; !symbolStack.empty();) {
        opening = symbolStack.top();
        retVec.push_back(AutocompleteScoringMap.at(ChunkClosingMap.at(opening)));
        symbolStack.pop();
    }

    return retVec;
}

const IncompleteLines checkNavigationCodeIncomplete(const std::vector<std::string> &navCode) {
    IncompleteLines incompleteLines;

    unsigned int idx{0};
    for (const auto& line : navCode) {
        incompleteLines.push_back({idx, checkLineIncomplete(line)});
        ++idx;
    }

    incompleteLines.erase(std::remove_if(incompleteLines.begin(), incompleteLines.end(),
        [](const IncompleteLine &l) {
            return l.second.size() == 0;
        }),
        incompleteLines.end()
    );

    return incompleteLines;
}

const unsigned long calculateAutocmpScores(const std::vector<unsigned short> &ps) {
    unsigned long sum{0};
    for (const auto &p : ps) {
        sum *= 5;
        sum += p;
    }
    return sum;
}
}
