#include "../../raylib/include/raylib.h"

void updateSnake(int snake[][2], int snake_size, int direction[]);

int main(void) {
  const int screenWidth = 600;
  const int screenHeigth = 600;

  const int size = 10;
  const int cols = screenWidth / size;
  const int rows = screenHeigth / size;

  InitWindow(screenWidth, screenHeigth, "Truchet Tiles");
  SetTargetFPS(15);

  int snake[][2] = {{size, size}, {size, size * 2}, {size, size * 3}};
  int snake_size = 3;
  int direction[2] = {0, size};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int i = 0; i < snake_size; i++) {
      DrawRectangle(snake[i][0], snake[i][1], size, size, DARKGREEN);
    }
    updateSnake(snake, snake_size, direction);

    EndDrawing();
  }

  CloseWindow();
}

void updateSnake(int snake[][2], int snake_size, int direction[]) {
  int tail[2];
  int head[2];

  tail[0] = snake[0][0];
  tail[1] = snake[0][1];
  head[0] = snake[snake_size - 1][0];
  head[1] = snake[snake_size - 1][1];

  for (int i = 0; i < snake_size - 1; ++i) {
    snake[i][0] = snake[i + 1][0];
    snake[i][1] = snake[i + 1][1];
  }

  snake[snake_size - 1][0] = head[0] + direction[0];
  snake[snake_size - 1][1] = head[1] + direction[1];
}
