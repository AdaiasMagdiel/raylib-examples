#include "../../raylib/include/raylib.h"
#include <stdlib.h>
#include <time.h>

void drawShapeTriangle(int posX, int posY, int size, Color color, int mode) {
  Vector2 v1;
  Vector2 v2;
  Vector2 v3;

  if (mode == 1) {
    v1 = (Vector2){posX, posY + size};
    v2 = (Vector2){posX + size, posY + size};
    v3 = (Vector2){posX + size, posY};
  } else if (mode == 2) {
    v1 = (Vector2){posX + size, posY};
    v2 = (Vector2){posX, posY};
    v3 = (Vector2){posX + size, posY + size};
  } else if (mode == 3) {
    v1 = (Vector2){posX, posY + size};
    v2 = (Vector2){posX + size, posY + size};
    v3 = (Vector2){posX, posY};
  } else if (mode == 4) {
    v1 = (Vector2){posX, posY + size};
    v2 = (Vector2){posX + size, posY};
    v3 = (Vector2){posX, posY};
  }

  DrawTriangle(v1, v2, v3, color);
}

int randint(int min, int max) { return rand() % (max - min + 1) + min; }

int main(void) {
  srand(time(NULL));

  const int screenWidth = 600;
  const int screenHeigth = 600;

  const int size = 40;
  const int cols = screenWidth / size;
  const int rows = screenHeigth / size;

  int nums[cols][rows];
  for (int col = 0; col < cols; col++) {
    for (int row = 0; row < rows; row++) {
      nums[col][row] = randint(1, 4);
    }
  }

  InitWindow(screenWidth, screenHeigth, "Truchet Tiles");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int col = 0; col < cols; col++) {
      for (int row = 0; row < rows; row++) {
        drawShapeTriangle(col * size, row * size, size, BLACK, nums[col][row]);
      }
    }

    EndDrawing();
  }

  CloseWindow();
}
