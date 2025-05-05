@echo off
setlocal enabledelayedexpansion

:: Fixed paths
set "defaultDir=D:\CP\1AAPLANTILLA"
set "baseDir=D:\CP\TESTING"

:: Prompt user for mode
echo Select mode:
echo [1] Copy and rename default directory
echo [2] Create directory and copy default directory multiple times
set /p "mode=Enter your choice (1 or 2): "

if "%mode%"=="1" (
    :: Mode 1: Copy and rename
    set /p "newName=Enter the new name for the copied directory: "
    set "destDir=%baseDir%\%newName%"
    if exist "%defaultDir%" (
        xcopy "%defaultDir%" "%destDir%" /E /I /Q
        if exist "%destDir%" (
            echo Default directory successfully copied to "%destDir%".
        ) else (
            echo Error: Failed to copy to "%destDir%".
        )
    ) else (
        echo Error: Default directory "%defaultDir%" does not exist.
    )
    goto :EOF
)

if "%mode%"=="2" (
    :: Mode 2: Create directory and copy multiple times
    set /p "parentDir=Enter the name of the new parent directory: "
    set /p "count=Enter the number of copies to create (X): "

    set "parentPath=%baseDir%\%parentDir%"
    if exist "%defaultDir%" (
        mkdir "%parentPath%"
        set "alphabet=ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        for /L %%i in (0,1,%count%-1) do (
            set "suffix=!alphabet:~%%i,1!"
            if defined suffix (
                xcopy "%defaultDir%" "%parentPath%\!suffix!" /E /I /Q
                echo Copied to "%parentPath%\!suffix!".
            )
        )
        echo Created %count% directories in "%parentPath%".
    ) else (
        echo Error: Default directory "%defaultDir%" does not exist.
    )
    goto :EOF
)

:: Invalid choice
echo Invalid mode selected. Exiting.
pause
exit /b
