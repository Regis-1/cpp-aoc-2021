#include "day9.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>

namespace {
const day9::Heightmap convertFileHeightmapToNumeric(const std::string& fp);
}

namespace day9 {
HeightmapSystem::HeightmapSystem(const std::string &filepath)
    : heightmap(convertFileHeightmapToNumeric(filepath))
{
    auto [w, h] = getHmDimensions();
    hmWidth = w;
    hmHeight = h;
}

const Heightmap& HeightmapSystem::getHeightmap() const {
    return heightmap;
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


const std::pair<size_t, size_t> HeightmapSystem::getHmDimensions() {
    return {heightmap[0].size(), heightmap.size()};
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
}
