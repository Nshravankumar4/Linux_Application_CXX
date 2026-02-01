# **COMPLETE MASTER SCRIPT - DO EVERYTHING**

## **📁 `do_everything.sh` - Complete Project Setup & Build**

```bash
#!/bin/bash
# do_everything.sh - Complete project setup from scratch to GitHub
# Usage: ./do_everything.sh [project_name]
# If no name given, uses current directory

set -e  # Exit on error

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# ========== FUNCTIONS ==========
print_header() {
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}  $1${NC}"
    echo -e "${BLUE}========================================${NC}"
}

print_step() {
    echo -e "${GREEN}[$1] $2${NC}"
}

print_info() {
    echo -e "${YELLOW}➜ $1${NC}"
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

# ========== CHECK WSL ==========
print_header "WSL & UBUNTU CHECK"
print_step "1.1" "Checking WSL environment..."

# Check if we're in WSL
if ! grep -q Microsoft /proc/version 2>/dev/null; then
    print_error "Not running in WSL!"
    print_info "Please run this in WSL Ubuntu"
    exit 1
fi

print_success "Running in WSL"

# Check Ubuntu
print_step "1.2" "Checking Ubuntu..."
if [ -f /etc/os-release ]; then
    source /etc/os-release
    print_success "OS: $NAME $VERSION"
else
    print_error "Cannot detect OS"
fi

# Check user
print_step "1.3" "Checking user..."
USERNAME=$(whoami)
print_success "User: $USERNAME"
print_success "Home: $HOME"

# ========== UPDATE SYSTEM ==========
print_header "SYSTEM UPDATE"
print_step "2.1" "Updating package lists..."
sudo apt update

print_step "2.2" "Upgrading packages..."
sudo apt upgrade -y

print_step "2.3" "Cleaning up..."
sudo apt autoremove -y
sudo apt clean

# ========== INSTALL TOOLS ==========
print_header "INSTALLING DEVELOPMENT TOOLS"

print_step "3.1" "Installing build essentials..."
sudo apt install -y build-essential

print_step "3.2" "Installing CMake..."
sudo apt install -y cmake

print_step "3.3" "Installing Git..."
sudo apt install -y git

print_step "3.4" "Installing GoogleTest..."
sudo apt install -y libgtest-dev

print_step "3.5" "Installing clang..."
sudo apt install -y clang

print_step "3.6" "Installing extra tools..."
sudo apt install -y tree htop curl wget nano

# Build GTest
print_step "3.7" "Building GoogleTest libraries..."
cd /usr/src/gtest
sudo cmake . > /dev/null 2>&1
sudo make > /dev/null 2>&1
sudo cp lib/*.a /usr/lib/ > /dev/null 2>&1
cd -

print_success "All tools installed!"

# ========== VERIFY INSTALLATIONS ==========
print_header "VERIFICATION"

print_step "4.1" "Checking versions..."
echo -e "${CYAN}CMake:    $(cmake --version | head -1)${NC}"
echo -e "${CYAN}GCC:      $(gcc --version | head -1)${NC}"
echo -e "${CYAN}Git:      $(git --version)${NC}"
echo -e "${CYAN}Clang:    $(clang --version | head -1)${NC}"

# ========== PROJECT SETUP ==========
print_header "PROJECT SETUP"

# Get project name
if [ -z "$1" ]; then
    # Use current directory name
    PROJECT_NAME=$(basename "$(pwd)")
    print_info "No project name provided, using: $PROJECT_NAME"
    PROJECT_DIR="$(pwd)"
else
    PROJECT_NAME="$1"
    PROJECT_DIR="$HOME/projects/$PROJECT_NAME"
    mkdir -p "$PROJECT_DIR"
    cd "$PROJECT_DIR"
fi

print_step "5.1" "Setting up project: $PROJECT_NAME"
print_info "Location: $PROJECT_DIR"

# Create directory structure
print_step "5.2" "Creating project structure..."
mkdir -p include src tests build docs scripts

# ========== CREATE PROJECT FILES ==========
print_header "CREATING PROJECT FILES"

# 1. CMakeLists.txt
print_step "6.1" "Creating CMakeLists.txt..."
cat > CMakeLists.txt << EOF
cmake_minimum_required(VERSION 3.10)
project($PROJECT_NAME)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========== LIBRARY ==========
add_library(math_utils src/math_utils.cpp)
target_include_directories(math_utils PUBLIC include)

# ========== MAIN APP ==========
add_executable(app src/main.cpp)
target_link_libraries(app math_utils)

# ========== TESTING ==========
enable_testing()

find_package(GTest QUIET)

if(GTest_FOUND)
    message(STATUS "GTest found - building tests")
    add_executable(runTests tests/test_math.cpp)
    target_link_libraries(runTests math_utils GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(runTests)
else()
    message(WARNING "GTest not found - tests disabled")
endif()

# ========== INSTALL ==========
install(TARGETS app DESTINATION bin)
install(TARGETS math_utils DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
EOF

# 2. Header file
print_step "6.2" "Creating header file..."
cat > include/math_utils.h << 'EOF'
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

#endif
EOF

# 3. Source file
print_step "6.3" "Creating source file..."
cat > src/math_utils.cpp << 'EOF'
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) return 0; // Simple error handling
    return a / b;
}
EOF

# 4. Main program
print_step "6.4" "Creating main program..."
cat > src/main.cpp << 'EOF'
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << "================================\n";
    std::cout << "     MATH LIBRARY DEMO\n";
    std::cout << "================================\n\n";
    
    std::cout << "Basic Operations:\n";
    std::cout << "5 + 3  = " << add(5, 3) << "\n";
    std::cout << "5 - 3  = " << subtract(5, 3) << "\n";
    std::cout << "5 * 3  = " << multiply(5, 3) << "\n";
    std::cout << "6 / 3  = " << divide(6, 3) << "\n";
    std::cout << "5 / 0  = " << divide(5, 0) << " (handled)\n";
    
    std::cout << "\n================================\n";
    return 0;
}
EOF

# 5. Test file
print_step "6.5" "Creating test file..."
cat > tests/test_math.cpp << 'EOF'
#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
}

TEST(MathTest, SubtractTest) {
    EXPECT_EQ(subtract(5, 3), 2);
    EXPECT_EQ(subtract(0, 5), -5);
}

TEST(MathTest, MultiplyTest) {
    EXPECT_EQ(multiply(4, 3), 12);
    EXPECT_EQ(multiply(-2, 3), -6);
}

TEST(MathTest, DivideTest) {
    EXPECT_EQ(divide(6, 3), 2);
    EXPECT_EQ(divide(5, 2), 2); // Integer division
    EXPECT_EQ(divide(5, 0), 0); // Division by zero handled
}
EOF

# 6. README
print_step "6.6" "Creating README.md..."
cat > README.md << EOF
# $PROJECT_NAME

A C++ Math Library built with CMake and GoogleTest.

## 🚀 Quick Start

\`\`\`bash
# Build
./scripts/build.sh

# Run
./build/app

# Test
./build/runTests
\`\`\`

## 📁 Project Structure

\`\`\`
$PROJECT_NAME/
├── include/           # Header files
├── src/              # Source files
├── tests/            # Test files
├── build/            # Build output
├── scripts/          # Automation scripts
└── CMakeLists.txt    # Build configuration
\`\`\`

## 🔧 Requirements

- CMake 3.10+
- GCC/Clang
- GoogleTest (optional)

## 📄 License

MIT License
EOF

# ========== CREATE SCRIPTS ==========
print_header "CREATING AUTOMATION SCRIPTS"

print_step "7.1" "Creating build script..."
cat > scripts/build.sh << 'EOF'
#!/bin/bash
# Build script

echo "Building $PROJECT_NAME..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
echo "Build complete!"
EOF

print_step "7.2" "Creating run script..."
cat > scripts/run.sh << 'EOF'
#!/bin/bash
# Run script

cd build
if [ -f "app" ]; then
    ./app
else
    echo "Error: App not found. Run ./scripts/build.sh first"
    exit 1
fi
EOF

print_step "7.3" "Creating test script..."
cat > scripts/test.sh << 'EOF'
#!/bin/bash
# Test script

cd build
if [ -f "runTests" ]; then
    ./runTests
elif command -v ctest >/dev/null; then
    ctest --output-on-failure
else
    echo "No tests found"
fi
EOF

print_step "7.4" "Creating clean script..."
cat > scripts/clean.sh << 'EOF'
#!/bin/bash
# Clean script

echo "Cleaning build files..."
rm -rf build
rm -f *.o *.a *.so *.exe
echo "Clean complete!"
EOF

print_step "7.5" "Creating all-in-one script..."
cat > scripts/all.sh << 'EOF'
#!/bin/bash
# All-in-one script

echo "=== $PROJECT_NAME ==="
echo "1. Cleaning..."
./scripts/clean.sh
echo "2. Building..."
./scripts/build.sh
echo "3. Running..."
./scripts/run.sh
echo "4. Testing..."
./scripts/test.sh
echo "=== Complete! ==="
EOF

# Make scripts executable
chmod +x scripts/*.sh

# ========== BUILD PROJECT ==========
print_header "BUILDING PROJECT"

print_step "8.1" "Configuring CMake..."
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

print_step "8.2" "Compiling..."
make -j$(nproc)

print_success "Build successful!"

# ========== RUN TESTS ==========
print_header "RUNNING TESTS"

print_step "9.1" "Running unit tests..."
if [ -f "runTests" ]; then
    ./runTests
    print_success "Tests passed!"
else
    print_info "Tests not built (GTest might be missing)"
fi

# ========== RUN APPLICATION ==========
print_header "RUNNING APPLICATION"

print_step "10.1" "Running application..."
if [ -f "app" ]; then
    ./app
else
    print_error "Application not found!"
fi

cd ..

# ========== GIT SETUP ==========
print_header "GIT SETUP"

print_step "11.1" "Initializing Git repository..."
git init 2>/dev/null || print_info "Git already initialized"

print_step "11.2" "Creating .gitignore..."
cat > .gitignore << 'EOF'
# Build directories
build/
build-*/
cmake-build-*/
bin/
lib/

# Compiled files
*.o
*.obj
*.so
*.dll
*.exe
*.out
*.app

# CMake files
CMakeCache.txt
CMakeFiles/
cmake_install.cmake
Makefile
*.cmake

# IDE files
.vscode/
.idea/
*.swp
*.swo

# OS files
.DS_Store
Thumbs.db
EOF

print_step "11.3" "Adding files to Git..."
git add .

print_step "11.4" "Creating initial commit..."
git commit -m "Initial commit: $PROJECT_NAME project" 2>/dev/null || print_info "Commit already exists"

# ========== GITHUB SETUP ==========
print_header "GITHUB SETUP"

read -p "$(echo -e ${YELLOW}"Do you want to create a GitHub repository? (y/n): "${NC})" -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    print_step "12.1" "Checking GitHub CLI..."
    if ! command -v gh &> /dev/null; then
        print_info "Installing GitHub CLI..."
        sudo apt install -y gh
        gh auth login  # This will prompt for login
    fi
    
    print_step "12.2" "Creating GitHub repository..."
    GITHUB_USER=$(git config --global user.name || echo "yourusername")
    REPO_NAME="$PROJECT_NAME"
    
    echo -e "${CYAN}"
    echo "========================================"
    echo "MANUAL STEP REQUIRED:"
    echo "========================================"
    echo "1. Go to: https://github.com/new"
    echo "2. Repository name: $REPO_NAME"
    echo "3. DO NOT initialize with README"
    echo "4. Click 'Create repository'"
    echo "5. Copy the commands shown"
    echo "========================================"
    echo -e "${NC}"
    
    read -p "$(echo -e ${YELLOW}"Press Enter after creating repository..."${NC})"
    
    print_step "12.3" "Setting up remote..."
    echo -e "${CYAN}Paste the commands from GitHub (looks like):${NC}"
    echo -e "${PURPLE}git remote add origin https://github.com/username/$REPO_NAME.git${NC}"
    echo -e "${PURPLE}git branch -M main${NC}"
    echo -e "${PURPLE}git push -u origin main${NC}"
    echo
    print_info "Run these commands manually to complete GitHub setup"
fi

# ========== FINAL OUTPUT ==========
print_header "🎉 SETUP COMPLETE!"

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  PROJECT: $PROJECT_NAME${NC}"
echo -e "${GREEN}  LOCATION: $PROJECT_DIR${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""
echo -e "${CYAN}📁 Project Structure:${NC}"
tree -L 2
echo ""
echo -e "${CYAN}🚀 Available Commands:${NC}"
echo "  ./scripts/build.sh   - Build project"
echo "  ./scripts/run.sh     - Run application"
echo "  ./scripts/test.sh    - Run tests"
echo "  ./scripts/clean.sh   - Clean build files"
echo "  ./scripts/all.sh     - Do everything"
echo ""
echo -e "${CYAN}📦 Build Output:${NC}"
echo "  Application:  ./build/app"
echo "  Tests:        ./build/runTests"
echo ""
echo -e "${CYAN}🔧 Manual GitHub Setup:${NC}"
echo "  git remote add origin https://github.com/YOUR_USERNAME/$PROJECT_NAME.git"
echo "  git branch -M main"
echo "  git push -u origin main"
echo ""
echo -e "${GREEN}✅ Everything is ready! Happy coding! 🎉${NC}"

# ========== CREATE SHORTCUT ALIASES ==========
print_step "13.1" "Creating bash aliases..."

cat >> ~/.bashrc << EOF

# ========== PROJECT ALIASES ==========
alias pbuild='cd $PROJECT_DIR && ./scripts/build.sh'
alias prun='cd $PROJECT_DIR && ./scripts/run.sh'
alias ptest='cd $PROJECT_DIR && ./scripts/test.sh'
alias pclean='cd $PROJECT_DIR && ./scripts/clean.sh'
alias pall='cd $PROJECT_DIR && ./scripts/all.sh'
alias pstatus='cd $PROJECT_DIR && git status'
alias pcommit='cd $PROJECT_DIR && git add . && git commit -m'
alias ppush='cd $PROJECT_DIR && git push'
alias ppull='cd $PROJECT_DIR && git pull'

echo "Project aliases added for $PROJECT_NAME"
echo "  pbuild   - Build project"
echo "  prun     - Run application"
echo "  ptest    - Run tests"
echo "  pclean   - Clean build"
echo "  pall     - Do everything"
echo "  pstatus  - Git status"
echo "  pcommit  - Git commit"
echo "  ppush    - Git push"
echo "  ppull    - Git pull"
EOF

print_success "Aliases added to ~/.bashrc"
print_info "Run 'source ~/.bashrc' to activate aliases"

echo ""
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  NEXT STEPS:${NC}"
echo -e "${BLUE}========================================${NC}"
echo "1. Reload aliases: source ~/.bashrc"
echo "2. Try: pbuild (to build)"
echo "3. Try: prun (to run)"
echo "4. Set up GitHub (if not done)"
echo "5. Start coding!"
```

## **🚀 HOW TO USE:**

### **1. Download the script:**
```bash
# Go to where you want your project
cd ~/projects

# Download the script
curl -o do_everything.sh https://raw.githubusercontent.com/example/do_everything.sh
# OR create it manually with nano
```

### **2. Make it executable:**
```bash
chmod +x do_everything.sh
```

### **3. Run it:**
```bash
# Option A: Create new project
./do_everything.sh MyMathProject

# Option B: Setup in current directory
cd /mnt/d/Linux/Linux-Application_CXX
./do_everything.sh

# Option C: With specific directory
./do_everything.sh ~/myproject
```

## **🎯 WHAT THIS SCRIPT DOES:**

1. ✅ **Checks WSL environment**
2. ✅ **Updates Ubuntu system**
3. ✅ **Installs all development tools** (CMake, GCC, Git, GTest)
4. ✅ **Creates complete project structure**
5. ✅ **Generates all source files** (headers, source, tests)
6. ✅ **Creates automation scripts** (build, run, test, clean)
7. ✅ **Builds the project** with CMake
8. ✅ **Runs tests and application**
9. ✅ **Sets up Git repository**
10. ✅ **Guides through GitHub setup**
11. ✅ **Creates helpful bash aliases**
12. ✅ **Shows next steps**

## **📁 AFTER RUNNING:**

Your project will have:
```
MyMathProject/
├── scripts/
│   ├── build.sh
│   ├── run.sh
│   ├── test.sh
│   ├── clean.sh
│   └── all.sh
├── include/
│   └── math_utils.h
├── src/
│   ├── main.cpp
│   └── math_utils.cpp
├── tests/
│   └── test_math.cpp
├── build/
│   ├── app          # Your executable
│   └── runTests    # Test runner
├── CMakeLists.txt
├── README.md
└── .gitignore
```

## **⚡ QUICK COMMANDS AFTER SETUP:**

```bash
# After reloading bashrc
pbuild    # Build project
prun      # Run application
ptest     # Run tests
pclean    # Clean build
pall      # Do everything
```

**This one script does everything from WSL setup to GitHub!** 🚀
