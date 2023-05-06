cmake_minimum_required(VERSION 3.5)

project(misc_utils)

set(srcs 
    src/mfile.c
)

set(include_dir 
    "include"
)

add_library(misc_utils ${srcs})
include_directories(${include_dir})


