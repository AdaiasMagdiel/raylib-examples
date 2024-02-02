@echo off

gcc -o main main.c -I ../raylib/include -L../raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
