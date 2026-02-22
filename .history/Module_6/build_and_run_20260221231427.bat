REM This batch file compiles the main.cpp file and runs the resulting executable. It uses g++ to compile the code and links against the ws2_32 library, which is necessary for Windows socket programming. After compilation, it executes the Module6.exe program and then exits.

REM The batch file is designed to be run in a Windows environment where g++ is available (such as through MinGW or Cygwin) and where the necessary libraries for socket programming are present.

REM The steps in the batch file are as follows:
REM 1. Compile the main.cpp file into an executable named Module6.exe, linking against the ws2_32 library.
REM 2. Print a message indicating that compilation is finished and that the program will now run.
REM 3. Run the Module6.exe program.

REM Note: Make sure to have the g++ compiler installed and properly set up in your system's PATH environment variable to run this batch file successfully.

REM Compile the project
@echo off
echo Compiling project...
g++ main.cpp -o Module6.exe -lws2_32

REM Check if compilation was successful
REM If the compilation fails, the batch file will exit with an error message. If it succeeds, it will proceed to run the program.
if errorlevel 1 (
    echo Compilation failed. Please check the error messages above.
    exit /b 1
)
echo.
echo Compilation finished. Running program...
echo.
Module6.exe

REM Exit the batch file
exit