@echo off
echo Compiling project...
g++ main.cpp -o Module6.exe -lws2_32

echo.
echo Compilation finished. Running program...
echo.
Module6.exe
exit
