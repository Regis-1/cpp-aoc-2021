add_library(
    libDay9 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day9.cpp
)

target_include_directories(
    libDay9
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day9
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day9 PRIVATE libDay9
)

add_executable(
    testDay9
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay9
    PRIVATE libDay9
    PRIVATE gtest
)