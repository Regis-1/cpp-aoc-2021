cmake_minimum_required(VERSION 3.22)

project (
    cpp-aoc-2021
    VERSION 1.0.0
    DESCRIPTION "Advent of Code 2021 solutions in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest)

add_subdirectory(day1)

add_executable(
    tests
    ${CMAKE_SOURCE_DIR}/test.cpp
)

target_link_libraries(
    tests
    PRIVATE gtest
)
