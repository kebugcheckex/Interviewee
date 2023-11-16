get_filename_component(target_name "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
add_executable(${target_name} test.cpp)
target_link_libraries(${target_name} gtest gtest_main utils)
