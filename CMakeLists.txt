cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(graph)

option(ADD_TEST ON)

add_library(Core "src/graph.cpp" "src/solution.cpp")
target_include_directories(Core PUBLIC "include")

add_executable(main "src/main.cpp")

target_link_libraries(main PUBLIC Core)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${PROJECT_SOURCE_DIR}/graph.txt"   
    "$<TARGET_FILE_DIR:main>/graph.txt"
)

if (ADD_TEST)
    message(hi)
    enable_testing()
    add_subdirectory("tests")
endif()



