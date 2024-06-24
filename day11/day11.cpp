#include "day11.hpp"

#include <fstream>

namespace {
const day11::OctopusGrid extractDigitsFromStream(std::istream &is) {
    day11::OctopusGrid resultArr;
    
    std::string l;
    for (size_t row{0}; getline(is, l); ++row) {
        size_t col{0};
        for (const char &c : l) {
            resultArr[row*10 + col] = (c - '0');
            ++col;
        }
    }

    return resultArr;
}

//TODO: working handleFlash: propagation + resetting to 0
void handleFlash(day11::OctopusGrid &og, size_t &r, size_t &c) {
    og[r*10 + c] = 0;

    if (r != 0) {
        if (c != 0) ++og[(r-1)*10 + c-1];
        ++og[(r-1)*10 + c];
        if (c != 9) ++og[(r-1)*10 + c+1];
    }

    if (c != 0) ++og[r*10 + c-1];
    if (c != 9) ++og[r*10 + c+1];

    if (r != 9) {
        if (c != 0) ++og[(r+1)*10 + c-1];
        ++og[(r+1)*10 + c];
        if (c != 9) ++og[(r+1)*10 + c+1];
    }
}

void processStep(day11::OctopusGrid &octoGrid) {
    for (size_t row{0}; row < 10; ++row)
        for (size_t col{0}; col < 10; ++col)
            ++octoGrid[row*10 + col];

    for (size_t row{0}; row < 10; ++row)
        for (size_t col{0}; col < 10; ++col)
            if (octoGrid[row*10 + col] > 9)
                handleFlash(octoGrid, row, col);
}
}

namespace day11 {
const OctopusGrid extractOctopusGridFromFile(const std::string &filepath) {
    std::ifstream fd(filepath);
    if (fd.fail())
        throw std::runtime_error("Given file is invalid or does not exist.");

    const OctopusGrid octoGrid{extractDigitsFromStream(fd)};
    return octoGrid;
}

void runCycle(OctopusGrid &octoGrid, const unsigned int &steps) {
    for (auto s{0}; s < steps; ++s)
        processStep(octoGrid);
}
}
