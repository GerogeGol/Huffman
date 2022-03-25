add_library(
    HUF_Utils
    utils/utils.h
    utils/utils.c

)
target_include_directories(HUF_Utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/utils")

add_library(
        ROB
        Kravchi_88/Robin_Bobin_Barabek.h
        Kravchi_88/Robin_Bobin_Barabek.c
)
target_include_directories(ROB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Kravchi_88")

add_library(
        PRIORITY
        priority_queue/priority_queue.h
        priority_queue/priority_queue.c
)
target_include_directories(PRIORITY PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/priority_queue")