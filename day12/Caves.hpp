#pragma once

#include <string>
#include <vector>

using Routes = std::vector<std::string>;

enum CaveType {
    Start,
    Small,
    Big,
    End
};

struct Cave {
    Cave() = delete;
    Cave(CaveType initialType, Routes &&initialRoutes);

    CaveType caveType;
    Routes routes;
    bool visited;
};
