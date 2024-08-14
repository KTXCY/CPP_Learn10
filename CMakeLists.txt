cmake_minimum_required(VERSION 3.28)
project(CPP_Learn10)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_executable(test01 src/test01.c)


add_executable(test05 src/test05.c)
add_executable(test04 src/test04.c)
add_executable(test03 src/test03.c)

add_executable(test02 src/test02.c)

add_executable(test06 src/test06.c)

add_executable(test07 src/test07.c)

add_executable(test08
        src/test08.c)

add_executable(test09
        src/test09.c
)

add_executable(test10 src/test10.c)
add_executable(test11 src/test11.c)
add_executable(test12 src/test12.c)