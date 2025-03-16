
add_executable(tmain tests.cpp)

target_link_libraries(tmain PRIVATE Core)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tmain PRIVATE GTest::gtest)

add_test(NAME tst COMMAND tmain)

