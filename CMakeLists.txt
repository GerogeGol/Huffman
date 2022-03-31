cmake_minimum_required(VERSION 3.0.0)
project(huffman_code VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Libs)
add_executable(huffman_code main.c)

target_link_libraries(huffman_code PUBLIC ROB priority_queue HUF_Utils )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
