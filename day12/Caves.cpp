#include "Caves.hpp"

StartCave::StartCave(Routes&& initRoutes)
    : routes(initRoutes)
{}

StartCave::StartCave(StartCave&& other)
    : routes(std::move(other.routes))
{}

void StartCave::addRoute(std::string r) {
    routes.push_back(r);
}

std::optional<Routes> StartCave::getRoutes() {
    return {routes};
}

BigCave::BigCave(BigCave&& other)
    : routes(std::move(other.routes))
{}

BigCave::BigCave(Routes&& initRoutes)
    : routes(initRoutes)
{}

void BigCave::addRoute(std::string r) {
    routes.push_back(r);
}

std::optional<Routes> BigCave::getRoutes() {
    return {routes};
}

SmallCave::SmallCave(SmallCave&& other)
    : routes(std::move(other.routes))
{}

SmallCave::SmallCave(Routes&& initRoutes)
    : routes(initRoutes)
{}

void SmallCave::addRoute(std::string r) {
    routes.push_back(r);
}

std::optional<Routes> SmallCave::getRoutes() {
    return {routes};
}
