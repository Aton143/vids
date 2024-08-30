@echo off

set GLFW_PATH="..\external\glfw"
set GLAD_PATH="..\external\glad"
set IMGUI_PATH="..\external\imgui"
set SOURCES="%IMGUI_PATH%\backends\imgui_impl_glfw.cpp" "%IMGUI_PATH%\backends\imgui_impl_opengl3.cpp" "%IMGUI_PATH%\imgui*.cpp"

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
IF NOT EXIST imgui.obj (
cl /c /EHsc- /MD /nologo /Od /Zi /I "%GLFW_PATH%\include" /I "%GLAD_PATH%\include" /I "%IMGUI_PATH%" /I "%IMGUI_PATH%\backends" %SOURCES% /link "%GLFW_PATH%\lib-vc2017\glfw3.lib" kernel32.lib user32.lib gdi32.lib shell32.lib opengl32.lib
)
cl /EHsc- /wd4042 /MD /nologo /Od /Zi /I "..\external" /I "%GLFW_PATH%\include" /I "%GLAD_PATH%\include" /I "%IMGUI_PATH%" /I "%IMGUI_PATH%\backends" ..\src\main.cpp *.obj /link "%GLFW_PATH%\lib-vc2017\glfw3.lib" kernel32.lib user32.lib gdi32.lib shell32.lib opengl32.lib

popd
