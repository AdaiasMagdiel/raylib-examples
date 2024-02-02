#include "../../raylib/include/raylib.h"

float angle = 0.0f;
float velocity = 0.5f;

void drawPacman(float posX, float posY, float radius, Color color, int mode)
{
	Vector2 pos = {posX+radius/2, posY+radius/2};
	float startAngle = 0.0f;
	float endAngle = 270.0f;

	if (mode == 1){
		startAngle = 0.0f;
		endAngle = 270.0f;
	} else if (mode == 2) {
		startAngle += 90;
		endAngle += 90;
	} else if (mode == 3) {
		startAngle += 90 * 2;
		endAngle += 90 * 2;
	} else if (mode == 4) {
		startAngle += 90 * 3;
		endAngle += 90 * 3;
	}

	DrawCircleSector(pos, radius/2, startAngle + angle, endAngle + angle, 0, color);
}

int main(void)
{
	const int screenWidth = 600;
	const int screenHeigth = 600;

	const int size = 40;
	const int cols = screenWidth / size;
	const int rows = screenHeigth / size;

	InitWindow(screenWidth, screenHeigth, "PacPac");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLUE);

		int mode = 1;
		for (int col = 0; col < cols; col++)
		{
			for (int row = 0; row < rows; row++) {
				drawPacman(col*size, row*size, size, WHITE, mode % 4);
				mode++;
			}
		}

		EndDrawing();
		angle += velocity;
	}

	CloseWindow();
}
