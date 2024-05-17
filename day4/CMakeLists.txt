add_library(
    libDay4 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day4.cpp
    ${CMAKE_CURRENT_LIST_DIR}/BingoCard.cpp
)

target_include_directories(
    libDay4
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day4
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day4 PRIVATE libDay4
)

add_executable(
    testDay4
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay4
    PRIVATE libDay4
    PRIVATE gtest
)
