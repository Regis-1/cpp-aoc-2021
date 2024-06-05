#pragma once

#include <utility>
#include <array>
#include <string>
#include <vector>

using VentRange = std::pair<std::array<int,2>, std::array<int, 2>>;

namespace day5 {
const std::vector<VentRange> loadInputFromFile(const std::string& filePath);
const std::pair<int, int> getRangesMax(const std::vector<VentRange>& ranges);
const std::vector<int> createVentDiagram(const std::vector<VentRange>& ranges);
const int countOverlapPoints(const std::vector<int>& completeVentDiagram);
}
