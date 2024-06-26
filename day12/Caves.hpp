#pragma once

#include <string>
#include <vector>
#include <optional>

using Routes = std::vector<std::string>;

struct Cave {
    virtual const bool isVisitable() = 0;
    virtual void addRoute(std::string r) = 0;
    virtual std::optional<Routes> getRoutes() = 0;
};

struct StartCave : public Cave {
    StartCave(Routes&& initRoutes);
    StartCave(StartCave&& other);
    const bool isVisitable() override final { return false; }
    void addRoute(std::string r) override final;
    std::optional<Routes> getRoutes() override final;

    Routes routes;
};

struct EndCave : public Cave {
    const bool isVisitable() override final { return true; }
    void addRoute(std::string r) override final {}
    std::optional<Routes> getRoutes() override final { return {}; }
};

struct BigCave : public Cave {
    BigCave(Routes&& initRoutes);
    BigCave(BigCave&& other);
    const bool isVisitable() override final { return true; }
    void addRoute(std::string r) override final;
    std::optional<Routes> getRoutes() override final;

    Routes routes;
};

struct SmallCave : public Cave {
    SmallCave() = default;
    SmallCave(Routes&& initRoutes);
    SmallCave(SmallCave&& other);
    const bool isVisitable() override final { return !visited_; }
    void addRoute(std::string r) override final;
    std::optional<Routes> getRoutes() override final;

    Routes routes;

private:
    bool visited_{false};
};
