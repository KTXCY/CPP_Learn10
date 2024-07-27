cmake_minimum_required(VERSION 3.28)
project(CPP_Learn10)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_executable(test01 src/test01.c)