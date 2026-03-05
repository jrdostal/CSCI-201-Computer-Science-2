@echo off
REM This script compiles all C++ source files in the current directory into a single executable.

echo Compiling Final Project...

REM Compile all .cpp files. 
REM If your project uses the "include cpp" pattern (like Module 6), you might need to specify just the main file (e.g., g++ main.cpp -o FinalProject.exe).
g++ *.cpp -o FinalProject.exe

REM Check for compilation errors
if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b %errorlevel%
)

echo Compilation successful. Running FinalProject.exe...
echo.
FinalProject.exe
pause