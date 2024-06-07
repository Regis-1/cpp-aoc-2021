#pragma once

#include <functional>
#include <utility>
#include <array>
#include <string>
#include <vector>

using VentRange = std::pair<std::array<int,2>, std::array<int, 2>>;
using CoordFunc = const std::function<const std::vector<std::pair<int, int>>(const VentRange&)>;

namespace day5 {
const std::vector<VentRange> loadInputFromFile(const std::string& filePath);
const std::pair<int, int> getRangesMax(const std::vector<VentRange>& ranges);
const std::vector<int> createVentDiagram(const std::vector<VentRange>& ranges, CoordFunc& cfunc);
const int countOverlapPoints(const std::vector<int>& completeVentDiagram);
const std::vector<std::pair<int,int>> getCoordsHVOnly(const VentRange& range);
const std::vector<std::pair<int,int>> getCoordsDiagonals(const VentRange& range);
}
