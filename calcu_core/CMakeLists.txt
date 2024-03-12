cmake_minimum_required(VERSION 3.22)

project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./output)

aux_source_directory(./srcs/ DIR_SRCS)

add_executable(test ${DIR_SRCS})
