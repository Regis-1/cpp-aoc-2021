#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace day9 {

struct PairHasher {
    std::size_t operator()(const std::pair<size_t, size_t>& p) const noexcept; 
};

using Heightmap = std::vector<std::vector<short>>;
using BasinMap = std::unordered_map<std::pair<size_t, size_t>, size_t, PairHasher>;

class HeightmapSystem {
public:
    const Heightmap& getHeightmap() const;
    const BasinMap& getBasinMap() const;
    const std::vector<short> findLowPointsInLine(const size_t idx) const;
    const std::vector<short> findLowPoints() const;
    const std::vector<short> calculateRiskLevels(const std::vector<short> lowPoints) const;
    void findBasins();
    
    HeightmapSystem() = delete;
    HeightmapSystem(const std::string &filepath);
    ~HeightmapSystem() = default;

private:
    const std::pair<size_t, size_t>getHmDimensions();

    const Heightmap heightmap;
    BasinMap basinMap;
    size_t hmWidth;
    size_t hmHeight;
};
}
