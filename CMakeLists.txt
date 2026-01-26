# --------------------------------------------------
# Minimum CMake version required
# This ensures CMake has the needed features
# --------------------------------------------------
cmake_minimum_required(VERSION 3.14)

# --------------------------------------------------
# Project name
# --------------------------------------------------
project(MyProject)

# --------------------------------------------------
# Set C++ standard to C++17
# REQUIRED means build will fail if compiler
# does not support C++17
# --------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==================================================
# LIBRARY SECTION
# ==================================================
# Create a static/shared library named Main_Utils
# This library contains reusable source files
# --------------------------------------------------
add_library(Main_Utils
    src/math_utils.cpp
    src/Class_Object.cpp
    src/EncapsulationBankAccount.cpp
    src/BankAccount.cpp
)

# --------------------------------------------------
# Specify include directory for the library
# PUBLIC means:
#  - Used by Main_Utils
#  - Also visible to targets linking this library
# --------------------------------------------------
target_include_directories(Main_Utils PUBLIC include)

# ==================================================
# MAIN APPLICATION
# ==================================================
# Create executable named "app"
# This is the main program
# --------------------------------------------------
add_executable(app
    src/main.cpp
)

# --------------------------------------------------
# Link Main_Utils library to app executable
# --------------------------------------------------
target_link_libraries(app Main_Utils)

# ==================================================
# TESTING SECTION
# ==================================================
# Enable CTest support
# Allows running tests using: ctest
# --------------------------------------------------
enable_testing()

# --------------------------------------------------
# Platform-specific configuration
# --------------------------------------------------
if(WIN32)

    # =============================================
    # WINDOWS: Download GoogleTest automatically
    # =============================================
    include(FetchContent)

    # Declare GoogleTest dependency
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )

    # Required for MSVC runtime compatibility
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Download and make GoogleTest available
    FetchContent_MakeAvailable(googletest)

    # ---------------------------------------------
    # Test executable
    # ---------------------------------------------
    add_executable(runTests
        tests/main_test.cpp
        tests/test_math.cpp
        tests/Class_Object_Test.cpp
        tests/EncapsulationBankAccount_Test.cpp
	tests/BankAccount_Test.cpp
    )

    # Link GoogleTest and project library
    target_link_libraries(runTests
        gtest
        Main_Utils
    )

else()

    # =============================================
    # LINUX / WSL: Use system-installed GoogleTest
    # =============================================
    find_package(GTest REQUIRED)

    # ---------------------------------------------
    # Test executable
    # ---------------------------------------------
    add_executable(runTests
        tests/main_test.cpp
        tests/test_math.cpp
        tests/Class_Object_Test.cpp
        tests/EncapsulationBankAccount_Test.cpp
        tests/BankAccount_Test.cpp
    )

    # Link GoogleTest and project library
    target_link_libraries(runTests
        GTest::gtest
        Main_Utils
    )

endif()

# --------------------------------------------------
# Automatically discover and register test cases
# No need to manually add tests
# --------------------------------------------------
include(GoogleTest)
gtest_discover_tests(runTests)
