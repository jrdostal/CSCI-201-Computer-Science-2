REM This batch file compiles all C++ source files in the current directory into a single executable. It uses g++ to compile the code. After compilation, it executes the FinalProject.exe program.

REM The steps in the batch file are as follows:
REM 1. Compile all .cpp files into an executable named FinalProject.exe.
REM 2. Check for compilation errors.
REM 3. Run the FinalProject.exe program.

REM Note: Make sure to have the g++ compiler installed and properly set up in your system's PATH environment variable to run this batch file successfully.

REM Compile the project
@echo off
echo Compiling Final Project...
g++ *.cpp -o FinalProject.exe

REM Check if compilation was successful
REM If the compilation fails, the batch file will exit with an error message. If it succeeds, it will proceed to run the program.
if errorlevel 1 (
    echo Compilation failed. Please check the error messages above.
    pause
    exit /b 1
)

echo.
echo Compilation successful. Running FinalProject.exe...
echo.
FinalProject.exe
pause