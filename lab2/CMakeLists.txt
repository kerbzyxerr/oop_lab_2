cmake_minimum_required(VERSION 3.12)
project(Lab2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(lib src/five.cpp)

add_executable(lab2 src/main.cpp)
target_link_libraries(lab2 lib)

find_package(GTest REQUIRED)

add_executable(tests tests/tests.cpp)
target_link_libraries(tests lib GTest::GTest GTest::Main)

enable_testing()
add_test(NAME tests COMMAND tests)