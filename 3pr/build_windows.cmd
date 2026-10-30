@echo off
setlocal
cd /d "%~dp0"

gcc -std=c11 -Wall -Wextra -g -O0 -c array.c -o array.o
if errorlevel 1 exit /b 1
gcc -shared array.o -o array.dll
if errorlevel 1 exit /b 1

gcc -std=c11 -Wall -Wextra -g -O0 -c matrix.c -o matrix.o
if errorlevel 1 exit /b 1
gcc -shared matrix.o -o matrix.dll
if errorlevel 1 exit /b 1

gcc -std=c11 -Wall -Wextra -g -O0 main.c load.c -o app.exe
if errorlevel 1 exit /b 1

echo Built: app.exe, array.dll, matrix.dll
