add_executable(
    day1
    ${CMAKE_CURRENT_LIST_DIR}/day1.cpp
)

target_include_directories(
    day1
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    testDay1
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay1 PRIVATE gtest
)
