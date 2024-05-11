add_executable(
    day2
    ${CMAKE_CURRENT_LIST_DIR}/day2.cpp
)

target_include_directories(
    day2
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
    testDay2
    ${CMAKE_CURRENT_LIST_DIR}/test.cpp
)

target_link_libraries(
    testDay2 PRIVATE gtest
)
