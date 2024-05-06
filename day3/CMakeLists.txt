add_executable(
    day3
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_include_directories(
    day3
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)
