#!/bin/bash
# 1 - git branch to setup
# Sequence of these git commands is mandatory to cover various states of git repos.
# If CI/CD build is broken, check this script is not in subject of change.

if [ -z "$1" ]; then
    exit 1
fi

git fetch origin "$1" || exit $?

# Save executable permissions of scripts
echo "Saving script permissions..."
if [ -d "Scripts" ]; then
    find Scripts -name "*.sh" -exec chmod +x {} \;
    find Scripts -name "*.bat" -exec chmod +x {} \;
fi

git clean -dfx || exit $?

git reset --hard "origin/$1" || exit $?

git checkout "$1" || exit $?

git pull origin "$1" || exit $?

# RESTORE executable permissions
echo "Restoring script permissions for WSL..."
if [ -d "Scripts" ]; then
    find Scripts -name "*.sh" -exec dos2unix {} \; 2>/dev/null || true
    find Scripts -name "*.sh" -exec chmod +x {} \;
    find Scripts -name "*.bat" -exec chmod +x {} \;
fi
