cmake_minimum_required(VERSION 3.23)

project(c_test_expected)

add_subdirectory(unity)
add_subdirectory(../c_expected/src/fifo fifo_src)
add_subdirectory(src)