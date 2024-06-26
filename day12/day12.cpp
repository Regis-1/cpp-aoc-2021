#include "day12.hpp"
#include <cctype>
#include <fstream>

namespace {
const day12::CaveMap extractCaveMapFromIStream(std::istream &is) {
    day12::CaveMap caveMap;

    std::vector<std::string> nodes{"", ""};
    for (std::string l; std::getline(is, l);) {
        const auto delimPos{l.find('-')};
        nodes[0] = l.substr(0, delimPos);
        nodes[1] = l.substr(delimPos+1);

        for (auto i{0}; i < nodes.size(); ++i) {
            std::string other{i == 0 ? nodes[1] : nodes[0]};
            if (auto found{caveMap.find(nodes[i])}; found != caveMap.end())
                caveMap.at(nodes[i])->addRoute(other);
            else
                if (nodes[i]== "start")
                    caveMap[nodes[i]] = std::make_shared<StartCave>(Routes{other});
                else if (nodes[i] == "end")
                    caveMap[nodes[i]] = std::make_shared<EndCave>();
                else if (isupper(nodes[i][0]))
                    caveMap[nodes[i]] = std::make_shared<BigCave>(Routes{other});
                else
                    caveMap[nodes[i]] = std::make_shared<SmallCave>(Routes{other});
        }
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

const std::vector<Routes> findAllRoutes(CaveMap &map) {
    std::vector<Routes> result;
    // 1. start at "start"
    std::optional<Routes> startRoutes{map.at("start")->getRoutes()};
    Routes path{"start"};
    if (startRoutes.has_value())
        for (auto r : startRoutes.value()) {
            //TODO: make this happen baby...
            //visitCave(r, map, 
        }
    // 2. go to others with history
    // 3. repeat until "end"
    return result;
}
}
