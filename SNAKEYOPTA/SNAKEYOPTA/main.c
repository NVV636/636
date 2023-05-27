#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define CANVAS_WIDTH 240
#define CANVAS_HEIGHT 120

#define CELL_WIDTH 10
#define CELL_HEIGHT 10

#define EAT_WIDTH 6
#define EAT_HEIGHT 6

#define FIELD_WIDTH 24 //CANVAS_WIDTH / CELL_WIDTH
#define FIELD_HEIGHT 12 //CANVAS_HEIGHT / CELL_HEIGHT

#define LVL_COUNT 5

typedef struct Coord_ {
	int x;
	int y;
} Coord;

const short(*LEVEL)[FIELD_WIDTH] = NULL;


const short lvl[LVL_COUNT][FIELD_HEIGHT][FIELD_WIDTH] =
{
	// LVL 0
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,


	// LVL 1
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,

	// LVL 2
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//LVL 3
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	//LVL 4
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const Coord SNAKE_SPAWNS[LVL_COUNT] = {
	{6, 6},
	{6, 6},
	{6, 6},
	{1, 1},
	{16, 4}
};

const int DIFFICULTY_COUNT = 3;
const char* const difficulty_names[] = { "SPEED: SLOWPOKE", "SPEED: NORMAL", "SPEED: HARD" };
const float difficulty_speeds[] = { 0.2, 0.1, 0.03 };
int difficulty = 0;

const Vector2 ZERO_VEC = { 0, 0 };

typedef struct SnakeNode_ {
	int32_t lifetime;
	bool food_inside;
}SnakeNode;

typedef struct Snake_ {
	int dir_x; // 1 - вправо -1 - влево 
	int dir_y; // 1 - вверх -1 - вниз
	int next_dir_x;
	int next_dir_y;
	int len;
	int pos_x;
	int pos_y;
	float speed; // в секундах для следующего обновления
	float last_step_update; // время с последнего обновления
	bool has_changed_dir;
	bool has_fooden;
}Snake;

typedef struct Food_ {
	int x;
	int y;
}Food;

void GoToGame();
void GoToSelectLevel();

int current_level = 0;

bool game_over = false;

Food food = { -1, -1 };
//Food super_food = {-1, -1};
SnakeNode snake_body[FIELD_WIDTH][FIELD_HEIGHT];
Snake snake;

void (*Draw)(void);
void (*Update)(void);

void InitSnake()
{
	for (int i = 0; i < snake.len; i++)
	{
		int x = snake.pos_x - snake.dir_x * i;
		int y = snake.pos_y - snake.dir_y * i;
		snake_body[x][y].lifetime = snake.len - i;
	}
}

void SpawnFood()
{
	int x;
	int y;
	do {
		x = GetRandomValue(0, FIELD_WIDTH - 1);
		y = GetRandomValue(0, FIELD_HEIGHT - 1);
	} while (snake_body[x][y].lifetime > 0 || LEVEL[y][x] > 0);
	food.x = x;
	food.y = y;
}

void Setup()
{
	snake.dir_x = 1;
	snake.len = 2;
	snake.dir_y = 0;
	snake.next_dir_x = 1;
	snake.next_dir_y = 0;
	snake.pos_x = SNAKE_SPAWNS[current_level].x;
	snake.pos_y = SNAKE_SPAWNS[current_level].y;
	snake.last_step_update = 0;
	snake.has_fooden = false;
	snake.speed = difficulty_speeds[difficulty];
	game_over = false;
	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			snake_body[i][j].lifetime = 0;
			snake_body[i][j].food_inside = false;
		}
	}

	LEVEL = lvl[current_level];

	InitSnake();
	SpawnFood();
}

void DrawWalls(int i, int j)
{
	if (LEVEL[j][i] == 0)
	{
		return;
	}
	DrawRectangle(i * CELL_WIDTH, j * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, WHITE);
}

void DrawSnakeBody(int i, int j)
{
	if (snake_body[i][j].lifetime < 1) {
		return;
	}
	DrawRectangle(i * CELL_WIDTH, j * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, PURPLE);
}

void DrawSnakeHead()
{
	DrawRectangle(snake.pos_x * CELL_WIDTH, snake.pos_y * CELL_HEIGHT, CELL_HEIGHT, CELL_WIDTH, VIOLET);
}

void DrawSnakeAndWalls()
{
	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			DrawSnakeBody(i, j);


			DrawWalls(i, j);

		}
	}
	DrawSnakeHead();
}


void DrawFood()
{
	int dw = (CELL_WIDTH - EAT_WIDTH) / 2;
	int dh = (CELL_HEIGHT - EAT_HEIGHT) / 2;
	DrawRectangle(food.x * CELL_WIDTH + dw, food.y * CELL_HEIGHT + dh, EAT_HEIGHT, EAT_WIDTH, RED);
}

void CheckFood()
{
	if (snake.pos_x == food.x && snake.pos_y == food.y)
	{
		snake.len++;
		snake.has_fooden = true;
		SpawnFood();
	}
}

void CheckWalls() {
	if (LEVEL[snake.pos_y][snake.pos_x] > 0) {
		game_over = true;
	}
}

void CheckCollision()
{
	if (snake_body[snake.pos_x][snake.pos_y].lifetime > 0)
	{
		game_over = true;
	}
}

void MoveSnake()
{
	snake.last_step_update += GetFrameTime();
	if (snake.last_step_update >= snake.speed)
	{
		snake.last_step_update = 0;
	}
	else
	{
		return;
	}

	if (snake.has_fooden)
	{
		snake.has_fooden = false;
	}
	else
	{
		for (int i = 0; i < FIELD_WIDTH; i++)
		{
			for (int j = 0; j < FIELD_HEIGHT; j++)
			{
				if (snake_body[i][j].lifetime > 0)
				{
					snake_body[i][j].lifetime--;

				}
			}
		}
	}

	snake.dir_x = snake.next_dir_x;
	snake.dir_y = snake.next_dir_y;
	snake.pos_x += snake.dir_x;
	snake.pos_y += snake.dir_y;

	if (snake.pos_x >= FIELD_WIDTH)
	{
		snake.pos_x = 0;
	}
	if (snake.pos_x < 0)
	{
		snake.pos_x = FIELD_WIDTH - 1;
	}
	if (snake.pos_y >= FIELD_HEIGHT)
	{
		snake.pos_y = 0;
	}
	if (snake.pos_y < 0)
	{
		snake.pos_y = FIELD_HEIGHT - 1;
	}
	CheckCollision();
	CheckWalls();
	snake_body[snake.pos_x][snake.pos_y].lifetime = snake.len;
}



void DrawGame()
{
	DrawFood();
	DrawSnakeAndWalls();

	if (game_over)
	{
		DrawText("GAME OVER", 20, 20, 33, DARKBLUE);
		DrawText("PRESS SPACE TO RESTART", 5, 80, 17, DARKBLUE);
	}
}

void ControlSnake()
{
	if ((snake.dir_y == 0) && (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)))
	{
		snake.next_dir_x = 0;
		snake.next_dir_y = -1;
		return;
	}
	if ((snake.dir_y == 0) && (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)))
	{
		snake.next_dir_x = 0;
		snake.next_dir_y = 1;
		return;
	}
	if ((snake.dir_x == 0) && (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)))
	{
		snake.next_dir_x = -1;
		snake.next_dir_y = 0;
		return;
	}
	if ((snake.dir_x == 0) && (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)))
	{
		snake.next_dir_x = 1;
		snake.next_dir_y = 0;
		return;
	}
}



void UpdateGame()
{
	if (game_over)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			GoToSelectLevel();
		}
		return;
	}

	if (IsKeyPressed(KEY_R))
	{
		GoToSelectLevel();
		return;
	}

	MoveSnake();
	CheckFood();
	ControlSnake();
}

Rectangle GetCanvasTarget() { // находим центр экрана
	float sh = (float)GetScreenHeight();
	float sw = (float)GetScreenWidth();
	float scale = fminf(sh / CANVAS_HEIGHT, sw / CANVAS_WIDTH);
	Rectangle  rec = { 0, 0, CANVAS_WIDTH * scale, CANVAS_HEIGHT * scale };
	return rec;
}


void GoToGame()
{
	Draw = DrawGame;
	Update = UpdateGame;
	Setup();
}

void DrawSelectLevel() {
	DrawText("SNAKE", 50, 4, 40, DARKBLUE);
	DrawText("LEVEL: ", 4, 60, 20, DARKBLUE);
	DrawText("PRESS ENTER TO START", 4, 100, 8, DARKBLUE);

	char buffer[3]; //макс. число 99
	sprintf(buffer, "%d", current_level);
	DrawText(buffer, 84, 60, 20, DARKBLUE);

	DrawText(difficulty_names[difficulty], 4, 80, 20, DARKBLUE);
}

void UpdateSelectLevel() {
	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
		current_level++;
	}
	else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
		current_level--;
	}
	if (current_level < 0) {
		current_level = LVL_COUNT - 1;
	}
	if (current_level >= LVL_COUNT) {
		current_level = 0;
	}

	if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
		difficulty--;
	}
	else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
		difficulty++;
	}
	if (difficulty < 0) {
		difficulty = DIFFICULTY_COUNT - 1;
	}
	if (difficulty >= DIFFICULTY_COUNT) {
		difficulty = 0;
	}

	if (IsKeyPressed(KEY_ENTER)) {
		GoToGame();
	}
}

void GoToSelectLevel() {
	Draw = DrawSelectLevel;
	Update = UpdateSelectLevel;
}
int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(CANVAS_WIDTH * 4, CANVAS_HEIGHT * 4, "Snake");
	SetTargetFPS(60);
	SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_POINT);
	RenderTexture2D canvas = LoadRenderTexture(CANVAS_WIDTH, CANVAS_HEIGHT);
	Rectangle canvas_field = { 0, 0, (float)canvas.texture.width, -(float)canvas.texture.height };
	SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT); //интерполяция (убрать мыло при растяжении окна)
	Setup();
	GoToSelectLevel();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(PINK);
		BeginTextureMode(canvas);
		ClearBackground(PINK);
		Draw();
		EndTextureMode();
		DrawTexturePro(canvas.texture, canvas_field, GetCanvasTarget(), ZERO_VEC, 0.0f, WHITE);
		EndDrawing();
		Update();

	}
	CloseWindow();
	return 0;
}