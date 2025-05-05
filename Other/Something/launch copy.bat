cls
@echo off
g++ "%cd%\%1.cpp" -o "%cd%\%1.exe"
"%cd%\%1.exe" < "%cd%\%1.txt"