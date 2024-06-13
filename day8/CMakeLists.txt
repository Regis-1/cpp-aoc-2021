add_library(
    libDay8 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day8.cpp
)

target_include_directories(
    libDay8
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day8
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day8 PRIVATE libDay8
)

add_executable(
    testDay8
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay8
    PRIVATE libDay8
    PRIVATE gtest
)