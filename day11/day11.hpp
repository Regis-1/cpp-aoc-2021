#pragma once

#include <cstdint>
#include <array>
#include <string>

namespace day11 {
using OctopusGrid = std::array<uint8_t, 100>;

const OctopusGrid extractOctopusGridFromFile(const std::string &filepath);
const size_t runCycle(OctopusGrid &octoGrid, const unsigned int &steps);
const size_t runCycleUntilFlashCount(OctopusGrid &octoGrid, const unsigned int &flashCount);
}
