add_library(
    libDay10 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day10.cpp
)

target_include_directories(
    libDay10
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day10
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day10 PRIVATE libDay10
)

add_executable(
    testDay10
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay10
    PRIVATE libDay10
    PRIVATE gtest
)