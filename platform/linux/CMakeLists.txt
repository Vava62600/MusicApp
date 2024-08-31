cmake_minimum_required(VERSION 3.10)
project(MusicAppLinux)

set(CMAKE_CXX_STANDARD 17)

# Trouver Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Ajouter le wrapper PulsePipe
add_library(PulsePipeWrapper pulse_pipe_wrapper.cpp)

# Tests
enable_testing()

add_executable(PulsePipeWrapperTest pulse_pipe_wrapper_test.cpp)
target_link_libraries(PulsePipeWrapperTest GTest::GTest GTest::Main PulsePipeWrapper)
