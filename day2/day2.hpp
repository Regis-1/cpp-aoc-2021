#pragma once

#include <vector>
#include <fstream>
#include <exception>
#include <iostream>

enum Move {
    Forward,
    Down,
    Up
};

struct Command {
    Move move;
    unsigned int amount;

    Command(Move m, unsigned int a) : move(m), amount(a) {}
    Command(std::string m, unsigned int a) : amount(a) {
        if (m == "forward")
            move = Move::Forward;
        else if (m == "down")
            move = Move::Down;
        else if (m == "up")
            move = Move::Up;
    }
};

class Submarine {
public:
    Submarine() = default;
    ~Submarine() = default;

    virtual void ExecuteMoveCommand(Command& cmd);
    virtual void ExecutePlannedCourse(std::vector<Command>& commands);

    unsigned int GetPosition() const {return position_;}
    unsigned int GetDepth() const {return depth_;}

protected:
    unsigned int position_ {0};
    unsigned int depth_ {0};
};

void Submarine::ExecuteMoveCommand(Command& cmd) {
    if (cmd.move == Move::Forward)
        position_ += cmd.amount;
    else if (cmd.move == Move::Down)
        depth_ += cmd.amount;
    else if (cmd.move == Move::Up)
        depth_ -= cmd.amount;
}

void Submarine::ExecutePlannedCourse(std::vector<Command>& commands) {
    for (auto& cmd : commands)
        ExecuteMoveCommand(cmd);
}

class AimedSubmarine : public Submarine {
public:
    void ExecuteMoveCommand(Command& cmd) override {
        if (cmd.move == Move::Forward) {
            position_ += cmd.amount;
            depth_ += aim_ * cmd.amount;
        }
        else if (cmd.move == Move::Down)
            aim_ += cmd.amount;
        else if (cmd.move == Move::Up)
            aim_ -= cmd.amount;
    }
private:
    unsigned int aim_ {0};
};

std::vector<Command> extractInputCommands(const std::string filePath) {
    std::ifstream fd(filePath);
    if (!fd)
        throw std::system_error(std::error_code(),
                "Invalid file path or there is something wrong with the file itself.");

    std::vector<Command> commands;
    std::string move;
    unsigned int amount;
    for(fd >> move >> amount; fd;) {
        commands.push_back({move, amount});
        fd >> move >> amount;
    }

    return commands; 
}
