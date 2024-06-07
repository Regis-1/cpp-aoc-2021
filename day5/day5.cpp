#include "day5.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace {
const std::vector<VentRange> loadInput(std::istream& is);
}

namespace day5 {
const std::vector<VentRange> loadInputFromFile(const std::string& filePath) {
    std::ifstream fd {filePath};
    if (fd.fail())
        throw std::runtime_error("There is something wrong with given file!");

    const auto input {loadInput(fd)};

    fd.close();
    return input;
}

const std::pair<int, int> getRangesMax(const std::vector<VentRange> &ranges) {
    int maxX = 0;
    int maxY = 0;
    for (const auto& vr : ranges) {
        if (vr.first[0] > maxX)
            maxX = vr.first[0];
        if (vr.second[0] > maxX)
            maxX = vr.second[0];

        if (vr.first[1] > maxY)
            maxY = vr.first[1];
        if (vr.second[1] > maxY)
            maxY = vr.second[1];
    }

    return {maxX+1, maxY+1};
}

const std::vector<int> createVentDiagram(const std::vector<VentRange> &ranges, CoordFunc &cfunc)
{
    auto [maxX, maxY] {getRangesMax(ranges)};
    std::vector<int> diagram(maxX*maxY, 0);

    for (const auto& r : ranges)
        for (const auto& coord : cfunc(r))
            ++diagram[coord.second*maxY + coord.first];

    return diagram;
}

const int countOverlapPoints(const std::vector<int> &completeVentDiagram) {
    int overlappedPoins {0};
    for (const auto& c : completeVentDiagram)
        if (c > 1) ++overlappedPoins;

    return overlappedPoins;
}

const std::vector<std::pair<int,int>> getCoordsHVOnly(const VentRange& range) {
    int deltaX {range.second[0] - range.first[0]};
    int deltaY {range.second[1] - range.first[1]};

    if (deltaX != 0 and deltaY != 0)
        return {};

    std::vector<std::pair<int,int>> coords;
    int min;
    int max;
    int constant;
    if (deltaX != 0) {
        min = (deltaX > 0 ) ? range.first[0] : range.second[0];
        max = (deltaX > 0 ) ? range.second[0] : range.first[0];
        constant = range.first[1];

        for (int i {min}; i <= max; ++i) {
            coords.push_back({i, constant});
        }
    }
    else if (deltaY != 0) {
        min = (deltaY > 0 ) ? range.first[1] : range.second[1];
        max = (deltaY > 0 ) ? range.second[1] : range.first[1];
        constant = range.first[0];

        for (int i {min}; i <= max; ++i) {
            coords.push_back({constant, i});
        }
    }

    return coords;
}

const std::vector<std::pair<int,int>> getCoordsDiagonals(const VentRange& range) {
    int deltaX {range.second[0] - range.first[0]};
    int deltaY {range.second[1] - range.first[1]};

    std::vector<std::pair<int,int>> coords;
    bool incX {(deltaX > 0) ? true : false};
    bool incY {(deltaY > 0) ? true : false};
    int posX {range.first[0]};
    int posY {range.first[1]};

    while (posX != range.second[0] or posY != range.second[1]) {
        coords.push_back({posX, posY});
        if (deltaX != 0) {
            if (incX) ++posX; else --posX;
        }
        if (deltaY != 0) {
            if (incY) ++posY; else --posY;
        }
    }
    coords.push_back({range.second[0], range.second[1]});

    return coords;
}
}

namespace {
void spaceOutNonNumeric(std::string& str) {
    for (auto& c : str)
        if (c != ' ' and !isdigit(c))
            c = ' ';
}

const std::vector<VentRange> loadInput(std::istream& is) {
    std::istringstream iss;
    std::vector<VentRange> ranges;

    VentRange vr;
    for (std::string line; std::getline(is, line); ) {
        spaceOutNonNumeric(line);
        iss.str(line);
        iss >> vr.first[0] >> vr.first[1];
        iss >> vr.second[0] >> vr.second[1];
        ranges.push_back(vr);
        iss.clear();
        iss.str("");
    }

    return ranges;
}
}
