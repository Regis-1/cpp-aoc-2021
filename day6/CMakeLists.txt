add_library(
    libDay6 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day6.cpp
)

target_include_directories(
    libDay6
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day6
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day6 PRIVATE libDay6
)

add_executable(
    testDay6
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay6
    PRIVATE libDay6
    PRIVATE gtest
)