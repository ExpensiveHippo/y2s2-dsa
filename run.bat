REM COMPILES ALL .CPP FILE IN A FOLDER
@echo off
setlocal


REM Check if folder arguement was provided
if "%~1"=="" (
    echo No folder specified. Using current directory.
    set "FOLDER=."
) else (
    set "FOLDER=%~1"
)

REM Check if folder is valid 
pushD "%FOLDER%" || (
    echo Invalid folder: "%FOLDER%"
    pause
    exit /b 1
)

REM Compile .cpp files and run .exe
echo Compiling .cpp files in folder: "%FOLDER%"
g++ *.cpp -o test.exe
if %errorLevel% == 0 (
    echo Compilation successful.
    echo Running test.exe...
    test.exe
) else (
    echo Compilation failed.
)

REM Return to original folder
popd
pause
