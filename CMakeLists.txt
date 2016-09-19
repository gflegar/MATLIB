cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(MATLIB CXX)

enable_testing()

set(warnings "-Wall -Wextra -Werror")
set(GTEST_DIR vendor/googletest/googletest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/${GTEST_DIR}/include)

add_subdirectory(${GTEST_DIR} gtest)

add_executable(unit-test test/matrix_test.cpp)
target_link_libraries(unit-test gtest gtest_main)

add_test(unitTest unit-test)

