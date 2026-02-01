#!/bin/bash
# quick_build.sh - Fast build for development
# Run from project root

cd "$(dirname "$0")"

# Clean and build
rm -rf build
mkdir build
cd build

# Configure and build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j4

# Run if app exists
if [ -f "app" ]; then
    echo "=== Running Application ==="
    ./app
fi

# Run tests if exist
if [ -f "runTests" ]; then
    echo "=== Running Tests ==="
    ./runTests
fi
