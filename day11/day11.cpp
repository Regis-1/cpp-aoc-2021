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

void handleFlash(day11::OctopusGrid &og, size_t r, size_t c, size_t * const flashCount = nullptr) {
    og[r*10 + c] = 0;
    if (flashCount) ++(*flashCount);

    if (r != 0 and c != 0) {    // above left
        uint8_t &p{og[(r-1)*10 + c-1]};
        if (p != 0 and ++p > 9) handleFlash(og, r-1, c-1, flashCount);
    }
    if (r != 0) {
        uint8_t &p{og[(r-1)*10 + c]}; // above
        if (p != 0 and ++p > 9) handleFlash(og, r-1, c, flashCount);
    }
    if (r != 0 and c != 9) {
        uint8_t &p{og[(r-1)*10 + c+1]}; // above right
        if (p != 0 and ++p > 9) handleFlash(og, r-1, c+1, flashCount);
    }

    if (c != 0) {
        uint8_t &p{og[r*10 + c-1]}; // left
        if (p != 0 and ++p > 9) handleFlash(og, r, c-1, flashCount);
    }
    if (c != 9) {
        uint8_t &p{og[r*10 + c+1]}; // right
        if (p != 0 and ++p > 9) handleFlash(og, r, c+1, flashCount);
    }

    if (r != 9 and c != 0) {
        uint8_t &p{og[(r+1)*10 + c-1]}; // below left
        if (p != 0 and ++p > 9) handleFlash(og, r+1, c-1, flashCount);
    }
    if (r != 9) {
        uint8_t &p{og[(r+1)*10 + c]}; // below
        if (p != 0 and ++p > 9) handleFlash(og, r+1, c, flashCount);
    }
    if (r != 9 and c != 9) {
        uint8_t &p{og[(r+1)*10 + c+1]}; // below right
        if (p != 0 and ++p > 9) handleFlash(og, r+1, c+1, flashCount);
    }
}

const size_t processStep(day11::OctopusGrid &octoGrid) {
    size_t flashCount{0};

    for (size_t row{0}; row < 10; ++row)
        for (size_t col{0}; col < 10; ++col)
            ++octoGrid[row*10 + col];

    for (size_t row{0}; row < 10; ++row)
        for (size_t col{0}; col < 10; ++col)
            if (octoGrid[row*10 + col] > 9)
                handleFlash(octoGrid, row, col, &flashCount);

    return flashCount;
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

const size_t runCycle(OctopusGrid &octoGrid, const unsigned int &steps) {
    size_t flashCountTotal{0};

    for (auto s{0}; s < steps; ++s)
        flashCountTotal += processStep(octoGrid);

    return flashCountTotal;
}

const size_t runCycleUntilFlashCount(OctopusGrid &octoGrid, const unsigned int &flashCount) {
    size_t step{0};

    for (size_t stepFlashCount{0}; stepFlashCount != flashCount; ++step)
        stepFlashCount = processStep(octoGrid);

    return step;
}
}
