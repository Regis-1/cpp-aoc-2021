add_library(
    libDay7 STATIC
    ${CMAKE_CURRENT_LIST_DIR}/day7.cpp
)

target_include_directories(
    libDay7
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    day7
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(
    day7 PRIVATE libDay7
)

add_executable(
    testDay7
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay7
    PRIVATE libDay7
    PRIVATE gtest
)