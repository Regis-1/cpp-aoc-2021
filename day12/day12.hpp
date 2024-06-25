#pragma once

#include "Caves.hpp"
#include <memory>
#include <unordered_map>

namespace day12 {
using CaveMap = std::unordered_map<std::string, std::unique_ptr<Cave>>;
CaveMap extractCaveMapFromFile(const std::string &inputPath);
}
