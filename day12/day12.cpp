#include "day12.hpp"
#include <fstream>

namespace {
const day12::CaveMap extractCaveMapFromIStream(std::istream &is) {
    day12::CaveMap caveMap;

    for (std::string l; std::getline(is, l);) {
    }

    return caveMap;
}
}

namespace day12 {
CaveMap extractCaveMapFromFile(const std::string &inputPath) {
    std::ifstream fd(inputPath);

    if (fd.fail())
        throw std::runtime_error("Given file is invalid or does not exists.");

    CaveMap caveMap{extractCaveMapFromIStream(fd)};
    fd.close();
    return caveMap;
}
}
