add_library(
    libDay3 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day3.cpp
)

target_include_directories(
    libDay3
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day3
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day3 PRIVATE libDay3
)

add_executable(
    testDay3
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay3
    PRIVATE libDay3
    PRIVATE gtest
)
