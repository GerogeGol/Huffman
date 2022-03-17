cmake_minimum_required(VERSION 3.0.0)
project(huffman_code VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(huffman_code main.cpp Libs/Kravchi_88/Robin_Bobin_Barabek.c Libs/Kravchi_88/Robin_Bobin_Barabek.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
