# Google Test Integration - Implementation Guide

## Overview
This document explains how Google Test was integrated into the project with a **custom test runner**, providing full control over test execution.

---

## What Was Implemented

✅ **Custom Google Test main function** (`tests/main_test.cpp`)  
✅ **Updated CMakeLists.txt** to link with `gtest` instead of `gtest_main`  
✅ **Clean separation** between application and test code  
✅ **Cross-platform support** (Linux/WSL and Windows)

---

## Files Modified/Created

### 1. **Created: `tests/main_test.cpp`**

**Purpose:** Custom entry point for Google Test execution

```cpp
// Include Google Test framework
#include <gtest/gtest.h>

/*
 * Custom main() function for Google Test
 * 
 * This replaces the default gtest_main library.
 * Gives us full control over test initialization.
 */
int main(int argc, char **argv)
{
    // Initialize Google Test
    // Parses command-line arguments (e.g., --gtest_filter)
    ::testing::InitGoogleTest(&argc, argv);
    
    // Run all registered test cases
    // Returns 0 if all tests pass, non-zero otherwise
    return RUN_ALL_TESTS();
}
```

**What this does:**
- Replaces Google Test's default `main()` function
- Allows custom initialization before tests run
- Provides explicit control over test execution flow

---

### 2. **Updated: `CMakeLists.txt`**

#### **Key Changes Made:**

##### ❌ **OLD** (using `gtest_main`):
```cmake
add_executable(runTests 
    tests/test_math.cpp
    tests/Class_Object_Test.cpp
    tests/EncapsulationBankAccount_Test.cpp)

target_link_libraries(runTests 
    GTest::gtest_main    # ← Google Test provides main()
    Main_Utils
)
```

##### ✅ **NEW** (using custom `main()`):
```cmake
add_executable(runTests
    tests/main_test.cpp              # ← NEW: Our custom main()
    tests/test_math.cpp
    tests/Class_Object_Test.cpp
    tests/EncapsulationBankAccount_Test.cpp
)

target_link_libraries(runTests
    GTest::gtest        # ← Changed: No longer using gtest_main
    Main_Utils
)
```

**Changes Summary:**
1. ➕ **Added** `tests/main_test.cpp` to test executable sources
2. 🔄 **Changed** link library from `GTest::gtest_main` → `GTest::gtest`
3. ✅ Applied changes to **both** Windows and Linux configurations

---

## Why This Approach?

| Aspect | `gtest_main` (Old) | Custom `main()` (New) |
|--------|-------------------|----------------------|
| **Control** | Limited | Full control |
| **Initialization** | Automatic | Explicit |
| **Flexibility** | None | Can add custom setup |
| **Understanding** | Hidden | Clear and visible |
| **Professional** | Beginner-friendly | Industry standard |

---

## How It Works

### Execution Flow:

```
1. User runs: ./runTests
         ↓
2. Our main() in main_test.cpp executes
         ↓
3. InitGoogleTest() initializes framework
         ↓
4. RUN_ALL_TESTS() discovers and runs all TEST() cases
         ↓
5. Returns exit code (0 = pass, non-zero = fail)
```

---

## Build and Run

### Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

### Run tests:
```bash
./runTests                          # Run all tests
./runTests --gtest_filter=*Math*    # Run specific tests
ctest                                # Run via CTest
```

---

## Platform Support

### **Linux / WSL:**
- Uses system-installed Google Test
- Links with `GTest::gtest`

### **Windows:**
- Downloads Google Test automatically via `FetchContent`
- Links with `gtest`

Both configurations use the **same custom `main_test.cpp`** file.

---

## Critical Rule

⚠️ **You MUST choose ONE:**

| If you... | Then link with... |
|-----------|------------------|
| Write your own `main()` | `gtest` only |
| Use Google Test's `main()` | `gtest_main` |

**Never link both** `gtest` and `gtest_main` together → causes "multiple definition of main" error.

---

## Summary

✅ **Created** custom test runner in `tests/main_test.cpp`  
✅ **Updated** CMakeLists.txt to use `gtest` instead of `gtest_main`  
✅ **Maintained** clean separation between app and tests  
✅ **Enabled** cross-platform compatibility  
✅ **Achieved** professional, industry-standard setup

---

## Interview One-Liner

> *"I integrated Google Test with a custom `main()` function instead of using `gtest_main`, giving me explicit control over test initialization and execution while maintaining clean, cross-platform CMake configuration."*

---

## Further Enhancements (Optional)

Consider adding:
- Custom test fixtures (`SetUp()` / `TearDown()`)
- Test parameterization
- Custom test listeners
- Performance benchmarking
- CI/CD integration

---

**Project:** Linux-Application_CXX  
**Author:** Shravan Kumar  
**Last Updated:** January 2026
