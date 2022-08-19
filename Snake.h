#pragma once
#include "MyQueue.h"
#include "Map.h"


enum Directions
{
	up,
	down,
	left,
	right,
	stop
};
struct Snake{
	char symbol;
	int length;
	MyQueue body;
	Directions snake_dir;
};
 

void create_snake(Snake* snake, int cs_mapsize);
void delete_snake(Snake* snake);
void move_snake(Snake *snake);
void draw_snake(Snake *snake, Map *map);