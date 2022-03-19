add_library(
    HUF_Utils
    utils/utils.h
    utils/utils.c
)

target_include_directories(HUF_Utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/utils")