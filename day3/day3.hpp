#pragma once

#include <fstream>

std::vector<std::vector<char>> extractInputData(const std::string filePath) {
    std::ifstream fd(filePath);
    if (!fd)
        throw std::system_error(std::error_code(), "Invalid file or file path.");

    std::vector<std::vector<char>> result;
    std::string line;

    fd.close();

    return result;
}
