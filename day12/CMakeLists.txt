add_library(
    libDay12 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day12.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Caves.cpp
)

target_include_directories(
    libDay12
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day12
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day12 PRIVATE libDay12
)

add_executable(
    testDay12
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay12
    PRIVATE libDay12
    PRIVATE gtest
)
