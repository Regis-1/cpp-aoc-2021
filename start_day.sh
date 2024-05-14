#!/bin/bash

info_invalid_arg () {
    echo -e "USAGE: ./start_day.sh <day_number>"
}

if [[ $# -ne 1 ]]; then
    info_invalid_arg
    exit 1
fi

day_number=$1
stem=day${day_number}
capital_stem=Day${day_number}

mkdir -p day${day_number} data/day${day_number}

# main.cpp
echo -n "#include \"day${day_number}.hpp\"
#include <iostream>

int main (int argc, char *argv[]) {
    return 0;
}" > ${stem}/main.cpp

# test.cpp
echo -n "#include <gtest/gtest.h>

#include \"${stem}.hpp\"

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}" > ${stem}/test.cpp

# day specific .cpp
echo -n "#include \"${stem}.hpp\"" > ${stem}/${stem}.cpp

# day specific .cpp
echo -n "#pragma once" > ${stem}/${stem}.hpp

# CMakeLists.txt
echo -n "add_library(
    lib${capital_stem} STATIC
    \${CMAKE_CURRENT_LIST_DIR}/${stem}.cpp
)

target_include_directories(
    lib${capital_stem}
    PRIVATE \${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    ${stem}
    \${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    ${stem} PRIVATE lib${capital_stem}
)

add_executable(
    test${capital_stem}
    \${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    test${capital_stem}
    PRIVATE lib${capital_stem}
    PRIVATE gtest
)" > ${stem}/CMakeLists.txt

# add line to main CMakeLists.txt
echo "add_subdirectory(${stem})" >> CMakeLists.txt

# data for input test
touch data/${stem}/input_test.txt

echo "You are ready to start solving the next day.

**************
* Good luck! *
**************"
