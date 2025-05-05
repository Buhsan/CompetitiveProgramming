cls
@echo off
@REM echo %cd%\%1.cpp
g++ "%cd%\%1.cpp" -o "%cd%\%1.exe"
"%cd%\%1.exe" < "%cd%\%1.txt"