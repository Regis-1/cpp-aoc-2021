#include "Caves.hpp"

StartCave::StartCave(StartCave&& other)
    : routes(std::move(other.routes))
{}

BigCave::BigCave(BigCave&& other)
    : routes(std::move(other.routes))
{}

SmallCave::SmallCave(SmallCave&& other)
    : routes(std::move(other.routes))
{}
