#!/bin/bash
# wsl_setup.sh - Setup WSL for C++ development

echo "🚀 Setting up WSL for C++ development..."
echo "========================================"

# Update
sudo apt update
sudo apt upgrade -y

# Install essentials
echo "Installing build tools..."
sudo apt install -y build-essential cmake git

# Install GoogleTest
echo "Installing GoogleTest..."
sudo apt install -y libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib

# Install clang
echo "Installing clang..."
sudo apt install -y clang clang-format clang-tidy

# Install extras
echo "Installing extras..."
sudo apt install -y tree htop curl wget

# Verify
echo "✅ Setup complete!"
echo ""
echo "Versions:"
cmake --version | head -1
gcc --version | head -1
git --version
