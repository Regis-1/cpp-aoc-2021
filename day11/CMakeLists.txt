add_library(
    libDay11 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day11.cpp
)

target_include_directories(
    libDay11
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day11
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day11 PRIVATE libDay11
)

add_executable(
    testDay11
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay11
    PRIVATE libDay11
    PRIVATE gtest
)