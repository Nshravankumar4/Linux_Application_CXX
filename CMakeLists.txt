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
# AUTOSAR / clang-tidy configuration
# (ADD THIS BLOCK HERE — after project & C++ standard)
# ==================================================
find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY
        ${CLANG_TIDY_EXE};
        -warnings-as-errors=autosar-*
    )
else()
    message(WARNING "clang-tidy not found!")
endif()

# ==================================================
# LIBRARY SECTION
# ==================================================
# Create a static/shared library named Main_Utils
# This library contains reusable source files
# --------------------------------------------------
add_library(Main_Utils
    Src/math_utils.cpp
    Src/Class_Object.cpp
    Src/EncapsulationBankAccount.cpp
    Src/BankAccount.cpp
    Src/InheritanceVehicleCar.cpp
)

# --------------------------------------------------
# Specify include directory for the library
# PUBLIC means:
#  - Used by Main_Utils
#  - Also visible to targets linking this library
# --------------------------------------------------
target_include_directories(Main_Utils PUBLIC Include)

# ==================================================
# MAIN APPLICATION
# ==================================================
# Create executable named "app"
# This is the main program
# --------------------------------------------------
add_executable(app
    Src/main.cpp
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
        Test/main_test.cpp
        Test/test_math.cpp
        Test/Class_Object_Test.cpp
        Test/EncapsulationBankAccount_Test.cpp
        Test/BankAccount_Test.cpp
        Test/InheritanceVehicleCar_Test.cpp
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
        Test/main_test.cpp
        Test/test_math.cpp
        Test/Class_Object_Test.cpp
        Test/EncapsulationBankAccount_Test.cpp
        Test/BankAccount_Test.cpp
        Test/InheritanceVehicleCar_Test.cpp
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
