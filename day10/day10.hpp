#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

namespace day10 {
using ErrorLine = std::pair<unsigned int, unsigned short>;
using ErrorLines = std::vector<ErrorLine>;
using IncompleteLine = std::pair<unsigned int, std::vector<unsigned short>>;
using IncompleteLines = std::vector<IncompleteLine>;

const std::unordered_map<char, unsigned short> SyntaxErrorScoringMap{
    {')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
const std::unordered_map<char, unsigned short> AutocompleteScoringMap{
    {')', 1}, {']', 2}, {'}', 3}, {'>', 4}};

const std::vector<std::string> extractNavigationCode(const std::string &filepath);
const unsigned short checkLineErrors(const std::string &line);
const std::vector<unsigned short> checkLineIncomplete(const std::string &line);
const ErrorLines checkNavigationCodeErrors(const std::vector<std::string> &navCode);
const IncompleteLines checkNavigationCodeIncomplete(const std::vector<std::string> &navCode);
const unsigned long calculateAutocmpScores(const std::vector<unsigned short> &ps);
}
