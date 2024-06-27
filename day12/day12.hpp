#pragma once

#include "Caves.hpp"
#include <unordered_map>

namespace day12 {
using CaveMap = std::unordered_map<std::string, Cave>;

CaveMap extractCaveMapFromFile(const std::string &inputPath);
const std::vector<Routes> findAllRoutes(CaveMap map);
const std::vector<Routes> findAllRoutesWithOneTwiceVisit(CaveMap map);
}
