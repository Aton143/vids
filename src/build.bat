@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
REM https://github.com/raysan5/raylib/issues/2417
cl /nologo /Od /Zi ..\src\main.cpp /I ..\raylib\include\ /MD /link /MACHINE:X64 /OUT:"main.exe" ..\raylib\lib\raylib.lib opengl32.lib kernel32.lib user32.lib shell32.lib gdi32.lib winmm.lib msvcrt.lib
popd
