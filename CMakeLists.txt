cmake_minimum_required(VERSION 3.20)

project(InterviewPrep)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-g -O1 -fsanitize=address -fno-omit-frame-pointer)
add_link_options(-fsanitize=address)

include_directories(${PROJECT_SOURCE_DIR}/cpp_utils)

add_subdirectory("cpp_utils")
add_subdirectory("oa/numbers_station")
add_subdirectory("leetcode/146-lru-cache")
add_subdirectory("leetcode/460-lfu-cache")
add_subdirectory("leetcode/489-robot-room-cleaner")
add_subdirectory("leetcode/2466-count-ways-to-build-good-strings")
add_subdirectory("leetcode/2771-longest-non-decreasing-subarray-from-two-arrays")
add_subdirectory("leetcode/124-binary-tree-maximum-path-sum")
add_subdirectory("leetcode/528-random-pick-with-weight")
