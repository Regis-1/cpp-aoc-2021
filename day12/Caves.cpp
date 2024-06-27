#include "Caves.hpp"

Cave::Cave(CaveType initialType, Routes &&initialRoutes)
    : caveType{initialType}, routes{initialRoutes}, visited{false}
{}
