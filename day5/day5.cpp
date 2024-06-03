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
    for (auto vr : ranges) {
        if (vr.first[0] > maxX)
            maxX = vr.first[0];
        if (vr.second[0] > maxX)
            maxX = vr.second[0];

        if (vr.first[1] > maxY)
            maxY = vr.first[1];
        if (vr.second[1] > maxY)
            maxY = vr.second[1];
    }

    return {maxX, maxY};
}

const std::vector<int> createVentDiagram(const std::vector<VentRange> &ranges) {
    auto [maxX, maxY] {getRangesMax(ranges)};
    std::vector<int> diagram(maxX*maxY, 0);

    for (auto r : ranges) {
        if (r.first[0] == r.second[0] or r.first[1] == r.second[1]) {
            //TODO!
        }
    }

    return {};
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
