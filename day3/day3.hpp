#pragma once

#include <vector>
#include <string>

using DiagData = std::vector<std::vector<char>>;

const DiagData extractInputData(const std::string);
const std::string getGammaRateFromData(const DiagData&);
const std::string getEpsilonRateFromGamma(const std::string&);
const int binToDec(const std::string);
const std::string getAdvancedRating(const DiagData&, const bool = false);
