@echo off
setlocal enabledelayedexpansion

:: Fixed paths
set "defaultDir=D:\CP\1AAPLANTILLA"
set "baseDir=D:\CP\TESTING"

:: Check if the default directory exists
if not exist "%defaultDir%" (
    echo Error: Default directory "%defaultDir%" does not exist. Exiting.
    pause
    exit /b
)

:: Prompt user for mode
echo Select mode:
echo [1] Copy and rename default directory
echo [2] Create directory and copy default directory multiple times
set /p "mode=Enter your choice (1 or 2): "

if "%mode%"=="1" (
    :: Mode 1: Copy and rename
    set /p "newName=Enter the new name for the copied directory: "
    if not defined newName (
        echo Error: No name provided for the new directory. Exiting.
        pause
        exit /b
    )
    
    set destDir="%baseDir%\%newName%"
    
    xcopy "%defaultDir%" "%destDir%\" /E /I /Q
    if exist "%destDir%" (
        echo Default directory successfully copied to "%destDir%".
    ) else (
        echo Error: Failed to copy to "%destDir%".
    )
    goto :EOF
)

if "%mode%"=="2" (
    :: Mode 2: Create directory and copy multiple times
    set /p "parentDir=Enter the name of the new parent directory: "
    set /p "count=Enter the number of copies to create (X): "

    if not defined parentDir (
        echo Error: No name provided for the parent directory. Exiting.
        pause
        exit /b
    )
    if not defined count (
        echo Error: No count provided. Exiting.
        pause
        exit /b
    )
    if "%count%" LSS 1 (
        echo Error: Count must be greater than 0. Exiting.
        pause
        exit /b
    )

    set "parentPath=%baseDir%\%parentDir%"
    mkdir "%parentPath%"
    if not exist "%parentPath%" (
        echo Error: Failed to create parent directory "%parentPath%".
        pause
        exit /b
    )

    set "alphabet=ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for /L %%i in (0,1,%count%-1) do (
        set "suffix=!alphabet:~%%i,1!"
        if defined suffix (
            set "targetDir=%parentPath%\!suffix!"
            xcopy "%defaultDir%" "%targetDir%\" /E /I /Q
            if exist "%targetDir%" (
                echo Copied to "%targetDir%".
            ) else (
                echo Error: Failed to copy to "%targetDir%".
            )
        )
    )
    echo Created %count% directories in "%parentPath%".
    goto :EOF
)

:: Invalid choice
echo Invalid mode selected. Exiting.
pause
exit /b
