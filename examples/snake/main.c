#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../raylib/include/raylib.h"

const int screenWidth = 600;
const int screenHeigth = 600;

const int size = 10;
const int cols = screenWidth / size;
const int rows = screenHeigth / size;

void drawFruit(Vector2 fruit);
Vector2 generateRandomFruit();
void drawSnake(Vector2 snake[]);
void checkSnakeFruitCollision(Vector2 snake[], int *snake_size, Vector2 *fruit);
void updateSnake(Vector2 snake[], int snake_size);

int snake_size = 3;
Vector2 direction = (Vector2){0, size};

int main(void) {
  srand(time(NULL));

  InitWindow(screenWidth, screenHeigth, "Snake");
  SetTargetFPS(15);

  Vector2 *snake = (Vector2 *)malloc(snake_size * sizeof(Vector2));
  Vector2 fruit = generateRandomFruit();

  snake[0] = (Vector2){size, size};
  snake[1] = (Vector2){size, size * 2};
  snake[2] = (Vector2){size, size * 3};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (IsKeyPressed(KEY_UP)) {
      direction = (Vector2){0, -1 * size};
    } else if (IsKeyPressed(KEY_RIGHT)) {
      direction = (Vector2){size, 0};
    } else if (IsKeyPressed(KEY_DOWN)) {
      direction = (Vector2){0, size};
    } else if (IsKeyPressed(KEY_LEFT)) {
      direction = (Vector2){-1 * size, 0};
    }


    checkSnakeFruitCollision(snake, &snake_size, &fruit);
    drawFruit(fruit);
    drawSnake(snake);
    updateSnake(snake, snake_size);

    EndDrawing();
  }

  free(snake);
  CloseWindow();
}

Vector2 generateRandomFruit() {
  int x = (rand() % cols) * size;
  int y = (rand() % rows) * size;

  return (Vector2){x, y};
}

void drawFruit(Vector2 fruit) {
  DrawRectangle(fruit.x, fruit.y, size, size, RED);
}

void drawSnake(Vector2 snake[]) {
  for (int i = 0; i < snake_size; i++) {
    DrawRectangle(snake[i].x, snake[i].y, size, size, DARKGREEN);

    if (snake[i].x > screenWidth) snake[i].x = 0;
    if (snake[i].y > screenWidth) snake[i].y = 0;

    if (snake[i].x < 0) snake[i].x = screenWidth;
    if (snake[i].y < 0) snake[i].y = screenWidth;
  }
}

void updateSnake(Vector2 snake[], int snake_size) {
  for (int i = 0; i < snake_size - 1; ++i) {
    snake[i].x = snake[i + 1].x;
    snake[i].y = snake[i + 1].y;
  }

  snake[snake_size - 1].x = snake[snake_size - 2].x + direction.x;
  snake[snake_size - 1].y = snake[snake_size - 2].y + direction.y;
}

void checkSnakeFruitCollision(Vector2 snake[], int *snake_size, Vector2 *fruit) {
    int snakeHeadX = snake[*snake_size - 1].x;
    int snakeHeadY = snake[*snake_size - 1].y;

    Rectangle snakeRect = (Rectangle){snakeHeadX, snakeHeadY, size, size};
    Rectangle fruitRect = (Rectangle){fruit->x, fruit->y, size, size};

    if (CheckCollisionRecs(snakeRect, fruitRect)) {
        *fruit = generateRandomFruit();
        (*snake_size)++;

        Vector2 *tempSnake = (Vector2 *)realloc(snake, (*snake_size) * sizeof(Vector2));
        if (tempSnake != NULL) {
            snake = tempSnake;

            snake[*snake_size - 1] = (Vector2){snakeHeadX + direction.x, snakeHeadY + direction.y};
        } else {
            (*snake_size)--;
        }
    }
}

