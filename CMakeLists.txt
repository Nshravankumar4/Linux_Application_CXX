cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# -----------------------------
# Library
# -----------------------------
add_library(math_utils
    src/math_utils.cpp
)

target_include_directories(math_utils
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# -----------------------------
# Main executable
# -----------------------------
add_executable(app
    src/main.cpp
)

target_link_libraries(app math_utils)

# -----------------------------
# GoogleTest
# -----------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Prevent overriding parent project compiler options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# -----------------------------
# Test executable
# -----------------------------
add_executable(runTests
    tests/test_math.cpp
)

target_link_libraries(runTests
    gtest_main
    math_utils
)

include(GoogleTest)
gtest_discover_tests(runTests)
