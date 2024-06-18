#pragma once

#include <string>
#include <utility>
#include <vector>

namespace day9 {
using Heightmap = std::vector<std::vector<short>>;

class HeightmapSystem {
public:
    const Heightmap& getHeightmap() const;
    const std::vector<short> findLowPointsInLine(const size_t idx) const;
    const std::vector<short> findLowPoints() const;
    const std::vector<short> calculateRiskLevels(const std::vector<short> lowPoints) const;
    
    HeightmapSystem() = delete;
    HeightmapSystem(const std::string &filepath);
    ~HeightmapSystem() = default;

private:
    const std::pair<size_t, size_t>getHmDimensions();

    const Heightmap heightmap;
    size_t hmWidth;
    size_t hmHeight;
};
}
