@echo off

if "%1" == "" (
	echo Please, inform the example folder.
	exit /b 1
)

set folder_name=%1

set source_file=%folder_name%\main.c
set output_file=%folder_name%\main.exe
set include_dir=raylib/include
set lib_dir=raylib/lib
set libraries=-lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

gcc -o "%output_file%" "%source_file%" -I%include_dir% -L%lib_dir% %libraries%

echo Successful compiled into %folder_name% folder.

if "%2" == "run" (
    start %output_file%
    exit /b 0
)
