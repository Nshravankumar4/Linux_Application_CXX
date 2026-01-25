cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Library
# -----------------------------
add_library(Main_Utils 
	src/math_utils.cpp
	src/Class_Object.cpp
	src/EncapsulationBankAccount.cpp)

target_include_directories(Main_Utils PUBLIC include)

# -----------------------------
# Main executable
# -----------------------------
add_executable(app 
	src/main.cpp)
target_link_libraries(app Main_Utils)

# -----------------------------
# Testing - TWO OPTIONS:
# -----------------------------

# OPTION 1: Use system GTest on Linux, FetchContent on Windows
enable_testing()

if(WIN32)
    # Windows: Use FetchContent with URL (not git tag)
    include(FetchContent)
    
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    
    add_executable(runTests 
		tests/test_math.cpp
		tests/Class_Object_Test.cpp
		tests/EncapsulationBankAccount_Test.cpp)
    target_link_libraries(runTests 
      gtest_main 
      Main_Utils
    )
    
    include(GoogleTest)
    gtest_discover_tests(runTests)
else()
    # Linux: Use system-installed GTest
    find_package(GTest REQUIRED)
    
    add_executable(runTests 
		tests/test_math.cpp
		tests/Class_Object_Test.cpp
		tests/EncapsulationBankAccount_Test.cpp)
    target_link_libraries(runTests 
      GTest::gtest_main 
      Main_Utils
    )
    
    include(GoogleTest)
    gtest_discover_tests(runTests)
endif()
