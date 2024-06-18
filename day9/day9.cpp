#include "day9.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>

namespace {
using Coords = std::pair<size_t, size_t>;
const size_t BORDER_VALUE{9};

const day9::Heightmap convertFileHeightmapToNumeric(const std::string& fp);
inline void hashCombine(std::size_t& seed, std::size_t value);
}

namespace day9 {

std::size_t PairHasher::operator()(const std::pair<size_t, size_t>& p) const noexcept {
    std::size_t seed = 0;
    hashCombine(seed, p.first);
    hashCombine(seed, p.second);
    return seed;
}

HeightmapSystem::HeightmapSystem(const std::string &filepath)
    : heightmap{convertFileHeightmapToNumeric(filepath)}, basinsCount{0}
{
    auto [w, h] = getHmDimensions();
    hmWidth = w;
    hmHeight = h;
}

const Heightmap& HeightmapSystem::getHeightmap() const {
    return heightmap;
}

const BasinMap& HeightmapSystem::getBasinMap() const {
    return basinMap;
}

const std::vector<size_t> HeightmapSystem::getBasinsSizes() const {
    std::vector<size_t> sizes(basinsCount, 0);
    for (const auto& bm : basinMap)
        ++sizes[bm.second];
    return sizes;
}

const std::vector<short> HeightmapSystem::findLowPointsInLine(const size_t idx) const {
    if (idx >= hmHeight) {
        std::cerr << "Given heightmap index exceeds available size." << std::endl;
        return {};
    }

    std::vector<short> lowPoints;
    std::vector<short> directions(4, SHRT_MAX); //up, down, prev, next
    for (auto i{0}; i < hmWidth; ++i) {
        if (idx != 0)
            directions[0] = heightmap[idx-1][i];
        if (idx != hmHeight-1)
            directions[1] = heightmap[idx+1][i];
        if (i != 0)
            directions[2] = heightmap[idx][i-1];
        if (i != hmWidth-1)
            directions[3] = heightmap[idx][i+1];

        const auto lowest{heightmap[idx][i]};
        bool isLowest{true};
        for (const auto& d : directions)
            if (lowest >= d)
                isLowest = false;

        if (isLowest)
            lowPoints.push_back(lowest);

        directions = {SHRT_MAX, SHRT_MAX, SHRT_MAX, SHRT_MAX};
    }

    return lowPoints;
}

const std::vector<short> HeightmapSystem::findLowPoints() const {
    std::vector<short> allLowPoints;

    for (auto row{0}; row < hmHeight; ++row) {
        const auto rowLowPoints{findLowPointsInLine(row)};
        allLowPoints.insert(std::end(allLowPoints), std::begin(rowLowPoints),
            std::end(rowLowPoints));
    }

    return allLowPoints;
}

const std::vector<short> HeightmapSystem::calculateRiskLevels(const std::vector<short> lowPoints) const {
    std::vector<short> plusOneVec(lowPoints.size(), 1);

    std::transform(std::begin(lowPoints), std::end(lowPoints),
        std::begin(plusOneVec), std::begin(plusOneVec), std::plus<short>()); 

    return plusOneVec;
}

void HeightmapSystem::findBasins() {
    size_t basinNumber{0};
    for (auto row{0}; row < hmHeight; ++row)
        for (auto col{0}; col < hmWidth; ++col) {
            if (heightmap[row][col] == BORDER_VALUE)
                continue;

            const std::pair<size_t, size_t> coords{row, col};
            try {
                basinMap.at(coords);
            }
            catch (const std::exception &e) {
                mapEntireBasin(coords, basinNumber);
            }
        }

    basinsCount = basinNumber;
}

const std::pair<size_t, size_t> HeightmapSystem::getHmDimensions() {
    return {heightmap[0].size(), heightmap.size()};
}

void HeightmapSystem::mapEntireBasin(const std::pair<size_t, size_t> &coords, size_t &basinNumber) {
    std::queue<std::pair<size_t, size_t>> coordsQ;
    std::vector<std::pair<size_t, size_t>> directions;
    coordsQ.push(coords);

    for (; coordsQ.size() != 0; coordsQ.pop()) {
        auto c{coordsQ.front()};
        basinMap[c] = basinNumber;

        if (c.first != 0 and heightmap[c.first - 1][c.second] != 9)
            directions.push_back({c.first - 1, c.second});
        if (c.first != hmHeight-1 and heightmap[c.first + 1][c.second] != 9)
            directions.push_back({c.first + 1, c.second});
        if (c.second != 0 and heightmap[c.first][c.second - 1] != 9)
            directions.push_back({c.first, c.second - 1});
        if (c.second != hmWidth-1 and heightmap[c.first][c.second + 1] != 9)
            directions.push_back({c.first, c.second + 1});

        for (const auto &d : directions)
            try {
                basinMap.at(d);
                continue;
            }
            catch (const std::exception &e) {
                coordsQ.push(d);
            }
        directions.clear();
    }

    ++basinNumber;
}
}

namespace {
const day9::Heightmap convertFileHeightmapToNumeric(const std::string& fp) {
    std::ifstream fd{fp};
    if (fd.bad() or fd.fail()) {
        fd.close();
        std::cerr << "Cannot opened the file given with the filepath: " << fp << std::endl;
        return {};
    }

    day9::Heightmap result;
    for (std::string line; std::getline(fd, line); ) {
        short idx{0};
        std::vector<short> numericLine(line.length());
        for (const auto& c : line)
            numericLine[idx++] = c - '0';
        result.push_back(std::move(numericLine));
    }

    return result;
}

inline void hashCombine(std::size_t& seed, std::size_t value) {
    seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
}
