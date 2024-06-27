#include "day12.hpp"
#include "Caves.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>

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
            if (auto found{caveMap.find(nodes[i])}; found != caveMap.end()) {
                caveMap.at(nodes[i]).routes.push_back(other);
            }
            else {
                CaveType caveType;
                if (nodes[i]== "start")
                    caveType = CaveType::Start;
                else if (nodes[i] == "end")
                    caveType = CaveType::End;
                else if (isupper(nodes[i][0]))
                    caveType = CaveType::Big;
                else
                    caveType = CaveType::Small;
                caveMap.emplace(nodes[i], Cave{caveType, Routes{other}});
            }
        }
    }

    return caveMap;
}

void visitCave(std::string &id, day12::CaveMap map, Routes path, std::vector<Routes> &pathList) {
    auto &currentCave{map.at(id)};
    if (currentCave.caveType == CaveType::Small)
            currentCave.visited = true;

    path.push_back(id);

    const auto &possibleRoutes{currentCave.routes};
    if (possibleRoutes.size() != 0)
        for (auto r : possibleRoutes) {
            if (r == "end") {
                path.push_back("end");
                pathList.push_back(path);
                continue;
            }

            if (not map.at(r).visited)
                    visitCave(r, map, path, pathList);
        }
}

void visitCaveWithTwiceVisit(std::string &id, day12::CaveMap map, Routes path, std::vector<Routes> &pathList, bool markedForTwiceVisit = false) {
    auto &currentCave{map.at(id)};
    if (currentCave.caveType == CaveType::Small) {
        if (not markedForTwiceVisit)
            currentCave.visited = true;
    }
    else if (markedForTwiceVisit) {
        return;
    }

    path.push_back(id);

    const auto &possibleRoutes{currentCave.routes};
    if (possibleRoutes.size() != 0)
        for (auto r : possibleRoutes) {
            if (r == "end") {
                path.push_back("end");
                pathList.push_back(path);
                continue;
            }

            if (not map.at(r).visited) {
                if (not markedForTwiceVisit) {
                    visitCaveWithTwiceVisit(r, map, path, pathList, false);
                    visitCaveWithTwiceVisit(r, map, path, pathList, true);
                }
                else {
                    visitCave(r, map, path, pathList);
                }
            }
        }
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

const std::vector<Routes> findAllRoutes(CaveMap map) {
    std::vector<Routes> result;
    auto &startCave{map.at("start")};
    startCave.visited = true;
    Routes path{"start"}; 

    if (startCave.routes.size() != 0)
        for (auto r : startCave.routes)
            if (not map.at(r).visited)
                visitCave(r, map, path, result);

    return result;
}

const std::vector<Routes> findAllRoutesWithOneTwiceVisit(CaveMap map) {
    std::vector<Routes> result;
    auto &startCave{map.at("start")};
    startCave.visited = true;
    Routes path{"start"}; 

    if (startCave.routes.size() != 0)
        for (auto r : startCave.routes)
            if (not map.at(r).visited) {
                visitCaveWithTwiceVisit(r, map, path, result, false);
                visitCaveWithTwiceVisit(r, map, path, result, true);
            }

    std::set<Routes> tmpSet;
    for (auto r : result)
        tmpSet.emplace(r);
    result.clear();
    std::copy(tmpSet.begin(), tmpSet.end(), std::back_inserter(result));

    return result;
}
}
