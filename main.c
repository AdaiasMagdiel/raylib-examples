#include "raylib.h"

int main(void)
{
    const int screenWidth = 600;
    const int screenHeight = 600;

    const int size = 50;
    const int cols = screenWidth / size;
    const int rows = screenHeight / size;

    InitWindow(screenWidth, screenHeight, "Generative Art");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for (int col = 0; col < cols; col++) {
                for (int row = 0; row < rows; row++) {
                    float hue = (col * rows + row) % 360;
                    DrawRectangle(col*size, row*size, size, size, ColorFromHSV(hue, 0.5f, 1.0f));
                }
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
