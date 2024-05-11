#pragma once

#include <vector>
#include <string>

using DiagData = std::vector<std::vector<char>>;

DiagData extractInputData(const std::string);
std::string getGammaRateFromData(DiagData&);
std::string getEpsilonRateFromGamma(const std::string&);
const int binToDec(const std::string);
