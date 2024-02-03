#include "../../raylib/include/raylib.h"


int main(void)
{
	const int screenWidth = 600;
	const int screenHeigth = 600;

	const int size = 80;
	const int cols = screenWidth / size;
	const int rows = screenHeigth / size;

	InitWindow(screenWidth, screenHeigth, "PacPac");
 
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// V1
		Vector2 v1 = {0, 80};
		Vector2 v2 = {80, 80};
		Vector2 v3 = {80, 0};
		Color color1 = DARKGREEN;

		DrawTriangle(v1, v2, v3, color1);

		// v2
		Vector2 v4 = {160, 80};
		Vector2 v5 = {80, 0};
		Vector2 v6 = {80, 80};
		Color color2 = DARKBLUE;

		DrawTriangle(v4, v5, v6, color2);

		// v3
		Vector2 v7 = {80, 80};
		Vector2 v8 = {0, 80};
		Vector2 v9 = {80, 160};
		Color color3 = DARKPURPLE;

		DrawTriangle(v7, v8, v9, color3);

		// v4
		Vector2 v10 = {80, 160};
		Vector2 v11 = {160, 80};
		Vector2 v12 = {80, 80};
		Color color4 = YELLOW;

		DrawTriangle(v10, v11, v12, color4);

		EndDrawing();
	}

	CloseWindow();
}
