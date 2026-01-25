

# 📘 **Complete WSL + CMake + C++ Project Guide**
## **From Zero to Professional Development Setup**

---


## **📋 TABLE OF CONTENTS**
1. [🚀 **WSL INSTALLATION**](#1-wsl-installation)
2. [🔧 **UBUNTU SETUP**](#2-ubuntu-setup)
3. [📁 **LINUX FILE COMMANDS**](#3-linux-file-commands)
4. [⚙️ **DEV TOOLS INSTALLATION**](#4-dev-tools-installation)
5. [💻 **PROJECT CREATION**](#5-project-creation)
6. [🏗️ **CMake BUILD SYSTEM**](#6-cmake-build-system)
7. [📊 **GIT & GITHUB**](#7-git--github)
8. [🔄 **GITHUB ACTIONS CI/CD**](#8-github-actions-cicd)
9. [🛠️ **DAILY WORKFLOW**](#9-daily-workflow)

---

## **1. 🚀 WSL INSTALLATION**

### **Step 1: Open PowerShell as Administrator**
1. Press `Windows + X`
2. Select **"Windows Terminal (Admin)"** or **"PowerShell (Admin)"**
3. Click **"Yes"** if prompted by User Account Control

### **Step 2: Install WSL**
```powershell
# Copy and paste this command:
wsl --install
```

**What happens:**
- ✅ Enables Windows Subsystem for Linux
- ✅ Enables Virtual Machine Platform  
- ✅ Downloads Ubuntu Linux
- ✅ Sets up everything automatically

### **Step 3: RESTART COMPUTER**
- **Must restart** when prompted
- Installation completes after restart

### **Step 4: Ubuntu First-Time Setup**
After restart, Ubuntu opens automatically:

```
Installing, this may take a few minutes...
Please create a default UNIX user account. The username does not need to match your Windows username.
For more information visit: https://aka.ms/wslusers

Enter new UNIX username: shravannunsavath
New password: [type password - no stars shown]
Retype new password: [type same password]
```

### **Step 5: Verify Installation**
```bash
# In Ubuntu terminal:
whoami
# Output: shravannunsavath

pwd
# Output: /home/shravannunsavath

wsl --list --verbose
# Should show Ubuntu running
```


```bash
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX$ ls
CMakeLists.txt  README.md  Scripts  Setup_Repo.bat  include  src  tests
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX$ mkdir build
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX$ cd build/
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ ls
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ cmake ..
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/lib/x86_64-linux-gnu/cmake/GTest/GTestConfig.cmake (found version "1.14.0")
-- Configuring done (1.5s)
-- Generating done (0.0s)
-- Build files have been written to: /mnt/d/Linux/Linux-Application_CXX/build
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ make
[ 16%] Building CXX object CMakeFiles/math_utils.dir/src/math_utils.cpp.o
[ 33%] Linking CXX static library libmath_utils.a
[ 33%] Built target math_utils
[ 50%] Building CXX object CMakeFiles/app.dir/src/main.cpp.o
[ 66%] Linking CXX executable app
[ 66%] Built target app
[ 83%] Building CXX object CMakeFiles/runTests.dir/tests/test_math.cpp.o
[100%] Linking CXX executable runTests
[100%] Built target runTests
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ ls
 CMakeCache.txt   CTestTestfile.cmake   app                   libmath_utils.a  'runTests[1]_include.cmake'
 CMakeFiles       Makefile              cmake_install.cmake   runTests         'runTests[1]_tests.cmake'
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ ./runTests
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from MathTest
[ RUN      ] MathTest.AddTest
[       OK ] MathTest.AddTest (0 ms)
[ RUN      ] MathTest.SubTest
[       OK ] MathTest.SubTest (0 ms)
[----------] 2 tests from MathTest (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (2 ms total)
[  PASSED  ] 2 tests.
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX/build$ ./app
Hello from WSL + CMake!
add(5, 3) = 8
sub(5, 3) = 2
```
```bash
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX$ ./Scripts/build_run.sh main
================================
  Building: Linux-Application_CXX
================================
[1/5] Cleaning previous build...
[2/5] Creating build directory...
[3/5] Configuring CMake...
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /usr/lib/x86_64-linux-gnu/cmake/GTest/GTestConfig.cmake (found version "1.14.0")
-- Configuring done (1.4s)
-- Generating done (0.0s)
-- Build files have been written to: /mnt/d/Linux/Linux-Application_CXX/build
[4/5] Building project...
[ 12%] Building CXX object CMakeFiles/Main_Utils.dir/src/math_utils.cpp.o
[ 25%] Building CXX object CMakeFiles/Main_Utils.dir/src/Class_Object.cpp.o
[ 37%] Linking CXX static library libMain_Utils.a
[ 37%] Built target Main_Utils
[ 50%] Building CXX object CMakeFiles/runTests.dir/tests/test_math.cpp.o
[ 62%] Building CXX object CMakeFiles/app.dir/src/main.cpp.o
[ 75%] Building CXX object CMakeFiles/runTests.dir/tests/Class_Object_Test.cpp.o
[ 87%] Linking CXX executable app
[ 87%] Built target app
[100%] Linking CXX executable runTests
[100%] Built target runTests
[5/5] Running...
--------------------------------
Running application:
Hello from WSL + CMake!
add(5, 3) = 8
sub(5, 3) = 2
divide(4, 2) = 2
mul(6, 3) = 12
This Program is about Class and Object
10 is Even
3 is Odd
--------------------------------
Running tests:
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 5 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from MathTest
[ RUN      ] MathTest.AddTest
[       OK ] MathTest.AddTest (0 ms)
[ RUN      ] MathTest.SubTest
[       OK ] MathTest.SubTest (0 ms)
[ RUN      ] MathTest.DivideTest
[       OK ] MathTest.DivideTest (0 ms)
[ RUN      ] MathTest.MulTest
[       OK ] MathTest.MulTest (0 ms)
[----------] 4 tests from MathTest (1 ms total)

[----------] 1 test from MyClassTest
[ RUN      ] MyClassTest.EvenOrOddCheck
[       OK ] MyClassTest.EvenOrOddCheck (0 ms)
[----------] 1 test from MyClassTest (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 2 test suites ran. (2 ms total)
[  PASSED  ] 5 tests.
================================
Build completed successfully!
Project: /mnt/d/Linux/Linux-Application_CXX
Build:   /mnt/d/Linux/Linux-Application_CXX/build
================================
shravannunsavath@DESKTOP-9ASPK4E:/mnt/d/Linux/Linux-Application_CXX$
```


---

## **2. 🔧 UBUNTU SETUP**

### **Update System:**
```bash
# Always start with update
sudo apt update

# Upgrade all packages
sudo apt upgrade -y

# Clean up
sudo apt autoremove -y
```

### **Basic Linux Setup:**
```bash
# Set your name/email (for Git later)
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# Create project directory
mkdir ~/projects
cd ~/projects
```

---

## **3. 📁 LINUX FILE COMMANDS CHEAT SHEET**

### **📍 NAVIGATION**
```bash
pwd                   # Print current directory
ls                    # List files
ls -la                # List all files with details
cd folder             # Enter folder
cd ..                 # Go back one level
cd ~                  # Go to home directory
cd /                  # Go to root directory
```

### **📄 FILE OPERATIONS**
```bash
# CREATE
touch file.txt        # Create empty file
mkdir folder          # Create directory
mkdir -p a/b/c        # Create nested directories

# VIEW
cat file.txt          # Show entire file content
head file.txt         # Show first 10 lines
tail file.txt         # Show last 10 lines
less file.txt         # View file page by page (q to quit)

# EDIT
nano file.txt         # Simple text editor (Ctrl+X to save)
# In nano: Ctrl+O = Save, Ctrl+X = Exit

# COPY/MOVE/RENAME
cp file1.txt file2.txt           # Copy file
cp -r folder1 folder2            # Copy folder recursively
mv oldname.txt newname.txt       # Rename file
mv file.txt folder/              # Move file to folder

# DELETE
rm file.txt           # Delete file
rm -r folder          # Delete folder recursively
rm -rf folder         # Force delete (careful!)

# SEARCH
find . -name "*.txt"          # Find files by name
grep "text" file.txt          # Search text in file
grep -r "text" .              # Search recursively
```

### **📊 FILE INFORMATION**
```bash
file filename         # Show file type
stat filename         # Show file details
wc -l file.txt        # Count lines in file
du -sh folder         # Show folder size
df -h                 # Show disk space
```

### **💾 PERMISSIONS**
```bash
chmod +x script.sh    # Make file executable
chmod 755 file.txt    # Set specific permissions
chown user:group file # Change ownership
```

### **🔗 LINKS**
```bash
ln -s target linkname    # Create symbolic link
ln target hardlink       # Create hard link
```

---

## **4. ⚙️ DEV TOOLS INSTALLATION**

### **Install All Development Tools:**
```bash
# Update first
sudo apt update

# Install essential build tools
sudo apt install -y build-essential

# Install CMake (build system)
sudo apt install -y cmake

# Install Git (version control)
sudo apt install -y git

# Install GoogleTest (unit testing)
sudo apt install -y libgtest-dev

# Install clang (alternative compiler)
sudo apt install -y clang

# Install extra useful tools
sudo apt install -y tree htop curl wget

# Verify installations
cmake --version    # Should show 3.10+
gcc --version      # Should show GCC version
git --version      # Should show Git version
```

### **Build GoogleTest Libraries:**
```bash
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib
```

---

## **5. 💻 PROJECT CREATION**

### **Create Project Structure:**
```bash
# Go to projects directory
cd ~/projects

# Create new project
mkdir my_math_project
cd my_math_project

# Create standard C++ project structure
mkdir -p include src tests build docs

# Create README
echo "# Math Library Project" > README.md

# See what you created
tree
```

### **Project Structure:**
```
my_math_project/
├── include/           # Header files (.h)
├── src/              # Source files (.cpp)
├── tests/            # Test files
├── build/            # Build outputs (auto-generated)
├── docs/             # Documentation
└── README.md         # Project description
```

---

## **6. 🏗️ CMake BUILD SYSTEM**

### **Create CMakeLists.txt:**
```bash
# Create CMake configuration file
cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.10)
project(MathProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create math library
add_library(math_utils src/math_utils.cpp)
target_include_directories(math_utils PUBLIC include)

# Create main executable
add_executable(math_app src/main.cpp)
target_link_libraries(math_app math_utils)

# Enable testing
enable_testing()

# Add tests if GTest is found
find_package(GTest QUIET)
if(GTest_FOUND)
    add_executable(run_tests tests/test_math.cpp)
    target_link_libraries(run_tests math_utils GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(run_tests)
endif()
EOF
```

### **Create Source Files:**
```bash
# Create header file
cat > include/math_utils.h << 'EOF'
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int subtract(int a, int b);

#endif
EOF

# Create implementation
cat > src/math_utils.cpp << 'EOF'
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
EOF

# Create main program
cat > src/main.cpp << 'EOF'
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << "Math Operations:\n";
    std::cout << "5 + 3 = " << add(5, 3) << "\n";
    std::cout << "5 - 3 = " << subtract(5, 3) << "\n";
    return 0;
}
EOF

# Create tests
cat > tests/test_math.cpp << 'EOF'
#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathTest, Add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(MathTest, Subtract) {
    EXPECT_EQ(subtract(5, 3), 2);
}
EOF
```

### **Build Your Project:**
```bash
# Step 1: Configure build
cmake -B build

# Step 2: Compile everything
cmake --build build

# Step 3: Run your program
./build/math_app

# Step 4: Run tests
cd build && ctest --output-on-failure
```

**Expected Output:**
```
Math Operations:
5 + 3 = 8
5 - 3 = 2
```

---

## **7. 📊 GIT & GITHUB**

### **Initialize Git Repository:**
```bash
# Initialize git in project
git init

# Create .gitignore for C++ projects
cat > .gitignore << 'EOF'
# Build directories
build/
cmake-build-*/

# Compiled files
*.o
*.obj
*.exe
*.out

# CMake files
CMakeCache.txt
CMakeFiles/
Makefile
*.cmake

# IDE files
.vscode/
.idea/

# OS files
.DS_Store
Thumbs.db
EOF

# Add all files to git
git add .

# Create first commit
git commit -m "Initial commit: Math library project"
```

### **Connect to GitHub:**
1. Go to [GitHub.com](https://github.com)
2. Click **"New repository"**
3. Name: `my_math_project`
4. **DO NOT** initialize with README
5. Click **"Create repository"**

### **Link Local to GitHub:**
```bash
# Copy commands from GitHub page (looks like this):
git remote add origin https://github.com/YOUR_USERNAME/my_math_project.git
git branch -M main
git push -u origin main
```

---

## **8. 🔄 GITHUB ACTIONS CI/CD**

### **Create CI/CD Pipeline:**
```bash
# Create workflows directory
mkdir -p .github/workflows

# Create CI/CD configuration
cat > .github/workflows/cmake.yml << 'EOF'
name: CMake Build and Test

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v4
    
    - name: Install dependencies
      run: |
        sudo apt-get update
        sudo apt-get install -y build-essential cmake libgtest-dev
    
    - name: Configure CMake
      run: cmake -B build
    
    - name: Build
      run: cmake --build build
    
    - name: Test
      run: |
        cd build
        ctest --output-on-failure || echo "Tests completed"
EOF
```

### **Push to GitHub:**
```bash
git add .
git commit -m "Add GitHub Actions CI/CD"
git push
```

### **Check CI/CD Status:**
1. Go to your GitHub repository
2. Click **"Actions"** tab
3. Watch your build run automatically
4. Green check = Success ✅
5. Red X = Failure ❌ (check logs)

---

## **9. 🛠️ DAILY WORKFLOW**

### **Morning Start:**
```bash
# Open WSL Ubuntu
# Start Menu → Type "Ubuntu"

# Go to project
cd ~/projects/my_math_project

# Check for updates
git pull origin main

# Clean previous build
rm -rf build
```

### **Make Changes:**
```bash
# Edit a file
nano src/math_utils.cpp

# Add new function
# Save: Ctrl+O, Enter
# Exit: Ctrl+X
```

### **Test Locally:**
```bash
# Rebuild
cmake -B build && cmake --build build

# Run tests
cd build && ctest

# Run your app
./math_app
```

### **Commit Changes:**
```bash
# Check what changed
git status

# Add changes
git add .

# Commit with message
git commit -m "Added multiply function"

# Push to GitHub
git push origin main
```

### **Monitor CI/CD:**
1. Open browser to GitHub repo
2. Go to **"Actions"** tab
3. Watch build progress
4. Fix any failures immediately

---

## **🎯 QUICK COMMAND REFERENCE**

### **Project Setup:**
```bash
mkdir project && cd project
mkdir -p include src tests build
```

### **Build Cycle:**
```bash
cmake -B build              # Configure
cmake --build build         # Compile
./build/my_app             # Run
cd build && ctest          # Test
```

### **Git Cycle:**
```bash
git status                 # Check changes
git add .                  # Stage all
git commit -m "message"    # Commit
git push                   # Upload
git pull                   # Download
```

---

## **🚨 TROUBLESHOOTING**

### **WSL Issues:**
```powershell
# Reset WSL
wsl --shutdown
wsl

# Reinstall Ubuntu
wsl --unregister Ubuntu
wsl --install -d Ubuntu
```

### **CMake Issues:**
```bash
# Clean and rebuild
rm -rf build
cmake -B build
```

### **Git Issues:**
```bash
# Fix remote URL
git remote set-url origin https://github.com/user/repo.git

# Force push (careful!)
git push -f origin main
```

---

## **✅ COMPLETION CHECKLIST**

- [ ] WSL installed and Ubuntu running
- [ ] `whoami` shows "shravannunsavath"
- [ ] `cmake --version` shows 3.10+
- [ ] `gcc --version` shows compiler
- [ ] Project builds with `cmake -B build`
- [ ] Program runs with `./build/math_app`
- [ ] Tests pass with `ctest`
- [ ] Git repository initialized
- [ ] Code pushed to GitHub
- [ ] GitHub Actions shows green check

---

## **📞 NEED HELP?**

### **Common Issues & Solutions:**

1. **"Command not found"**
   ```bash
   sudo apt update
   sudo apt install [package-name]
   ```

2. **Permission denied**
   ```bash
   sudo chown -R $USER:$USER .
   ```

3. **Git authentication failed**
   ```bash
   git config --global credential.helper store
   ```

4. **CMake can't find GTest**
   ```bash
   sudo apt install libgtest-dev
   cd /usr/src/gtest && sudo cmake . && sudo make
   ```

---

## **🎉 CONGRATULATIONS!**

You now have a **complete professional development environment** with:
- ✅ **WSL** - Linux on Windows
- ✅ **CMake** - Cross-platform builds  
- ✅ **Git** - Version control
- ✅ **GitHub** - Code hosting
- ✅ **CI/CD** - Automated testing
- ✅ **GoogleTest** - Unit testing

**Next Steps:**
1. Add more math functions
2. Create a GUI version
3. Add documentation
4. Share with others

**Remember:** Every professional project starts with this foundation! 🚀



