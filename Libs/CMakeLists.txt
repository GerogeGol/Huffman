add_library(
        priority_queue
        priority_queue/priority_queue.h
        priority_queue/priority_queue.c
)
target_include_directories(priority_queue PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/priority_queue")

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

# add_library(
#         Kamysh
#         Kamysh/iak_source.c
#         Kamysh/iak_header.h
# )
# target_include_directories(ROB PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Kamysh")
