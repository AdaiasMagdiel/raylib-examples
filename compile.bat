@echo off

gcc -o main main.c -I include -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
