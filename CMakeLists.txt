cmake_minimum_required(VERSION 3.20)

project(InterviewPrep)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-g -O1 -fsanitize=address -fno-omit-frame-pointer)
add_link_options(-fsanitize=address)

include_directories(${PROJECT_SOURCE_DIR}/cpp_utils)

add_subdirectory(oa/numbers_station)
