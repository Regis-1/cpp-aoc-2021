cmake_minimum_required(VERSION 3.22)

project (
    cpp-aoc-2021
    VERSION 1.0.0
    DESCRIPTION "Advent of Code 2021 solutions in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest)

add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
add_subdirectory(day4)
add_subdirectory(day5)
add_subdirectory(day6)
add_subdirectory(day7)
add_subdirectory(day8)
add_subdirectory(day9)
add_subdirectory(day10)
