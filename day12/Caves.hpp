#pragma once

#include <string>
#include <vector>

struct Cave {
    virtual const bool isVisitable() = 0;
};

struct StartCave : public Cave {
    StartCave(StartCave&& other);
    const bool isVisitable() override final { return false; }

    std::vector<std::string> routes;
};

struct EndCave : public Cave {
    const bool isVisitable() override final { return true; }
};

struct BigCave : public Cave {
    BigCave(BigCave&& other);
    const bool isVisitable() override final { return true; }

    std::vector<std::string> routes;
};

struct SmallCave : public Cave {
    SmallCave(SmallCave&& other);
    const bool isVisitable() override final { return !visited_; }

    std::vector<std::string> routes;

private:
    bool visited_{false};
};
