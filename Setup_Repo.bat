@echo off
REM ====================================================
REM Git Clean Local Changes - Reset Script
REM Usage: Setup_Repo.bat [branch_name]
REM Default: main
REM ====================================================

setlocal enabledelayedexpansion

REM Set default branch
if "%1"=="" (
    set BRANCH=main
) else (
    set BRANCH=%1
)

echo ==========================================
echo Cleaning Local Changes - Reset to %BRANCH%
echo ==========================================
echo.

REM 1 - Check if git repository exists
if not exist ".git" (
    echo [ERROR] Not a git repository!
    echo Run 'git init' first to initialize repository.
    pause
    exit /b 1
)

REM 2 - Show current status before cleanup
echo [INFO] Current status before cleanup:
git status --short
echo.

REM 3 - Stash any uncommitted changes (optional)
set /p STASH_CHANGES="Do you want to stash uncommitted changes? (y/n): "
if /i "!STASH_CHANGES!"=="y" (
    echo [1/5] Stashing uncommitted changes...
    git stash push -m "Stashed by Setup_Repo.bat - %date% %time%"
    if !ERRORLEVEL! neq 0 exit /b !ERRORLEVEL!
)

REM 4 - Clean untracked files
echo [2/5] Cleaning untracked files...
git clean -fd
if !ERRORLEVEL! neq 0 exit /b !ERRORLEVEL!

REM 5 - Reset tracked files
echo [3/5] Resetting tracked files...
git reset --hard HEAD
if !ERRORLEVEL! neq 0 exit /b !ERRORLEVEL!

REM 6 - Fetch latest from origin
echo [4/5] Fetching latest from origin...
git fetch origin
if !ERRORLEVEL! neq 0 (
    echo [WARNING] Could not fetch from origin, continuing...
)

REM 7 - Reset to origin/branch
echo [5/5] Resetting to origin/%BRANCH%...
git reset --hard origin/%BRANCH% 2>nul
if !ERRORLEVEL! neq 0 (
    echo [INFO] Could not reset to origin/%BRANCH%, using local %BRANCH%...
    git checkout %BRANCH% --force 2>nul
)

echo.
echo ==========================================
echo CLEANUP COMPLETE!
echo ==========================================
echo.
echo Repository: %CD%
echo Branch:     %BRANCH%
echo Status:
git status --short --branch
echo.
echo Ready for new changes.
pause
