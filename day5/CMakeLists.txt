add_library(
    libDay5 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day5.cpp
)

target_include_directories(
    libDay5
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day5
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day5 PRIVATE libDay5
)

add_executable(
    testDay5
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay5
    PRIVATE libDay5
    PRIVATE gtest
)