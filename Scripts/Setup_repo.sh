#!/bin/bash
# 1 - git branch to setup
# Sequence of these git commands is mandatory to cover various states of git repos.
# If CI/CD build is broken, check this script is not in subject of change.

if [ -z "$1" ]; then
    exit 1
fi

git fetch origin "$1" || exit $?

git clean -dfx || exit $?

git reset --hard "origin/$1" || exit $?

git checkout "$1" || exit $?

git pull origin "$1" || exit $?
