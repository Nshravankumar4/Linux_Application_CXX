#!/bin/bash
# build_run.sh - Build, test and run existing project
# Place this in your project root and run: ./build_run.sh

set -e  # Exit on error

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PROJECT_DIR=$(pwd)
BUILD_DIR="$PROJECT_DIR/build"

echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}  Building: $(basename $PROJECT_DIR)${NC}"
echo -e "${BLUE}================================${NC}"

# Check if CMakeLists.txt exists
if [ ! -f "CMakeLists.txt" ]; then
    echo -e "${RED}Error: CMakeLists.txt not found!${NC}"
    exit 1
fi

# Clean previous build
echo -e "${GREEN}[1/5] Cleaning previous build...${NC}"
rm -rf "$BUILD_DIR"

# Create build directory
echo -e "${GREEN}[2/5] Creating build directory...${NC}"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure CMake
echo -e "${GREEN}[3/5] Configuring CMake...${NC}"
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build project
echo -e "${GREEN}[4/5] Building project...${NC}"
make -j$(nproc)

# Run tests and application
echo -e "${GREEN}[5/5] Running...${NC}"
echo -e "${YELLOW}--------------------------------${NC}"
echo -e "${YELLOW}Running application:${NC}"
if [ -f "app" ]; then
    ./app
else
    echo -e "${RED}Application 'app' not found!${NC}"
    # Try to find any executable
    find . -maxdepth 1 -type f -executable ! -name "*.so" ! -name "*.a" | head -5
fi

echo -e "${YELLOW}--------------------------------${NC}"
echo -e "${YELLOW}Running tests:${NC}"
if [ -f "runTests" ]; then
    ./runTests
elif [ -f "tests" ]; then
    ./tests
else
    echo -e "${YELLOW}Running ctest:${NC}"
    ctest --output-on-failure
fi

echo -e "${BLUE}================================${NC}"
echo -e "${GREEN}Build completed successfully!${NC}"
echo -e "Project: $PROJECT_DIR"
echo -e "Build:   $BUILD_DIR"
echo -e "${BLUE}================================${NC}"
