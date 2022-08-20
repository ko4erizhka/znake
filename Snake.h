#pragma once
#include "MyQueue.h"
#include "Map.h"


enum Directions
{
	up,
	down,
	left,
	right
};
struct Snake{
	char symbol;
	MyQueue body;
	Directions direction;
};
 

void create_snake(Snake* snake, int cs_mapsize);
void delete_snake(Snake* snake);
Coords check_next_move(Snake *snake, Map *map);
void move_snake(Snake *snake,Map *map);
void draw_snake(Snake *snake, Map *map);
void grow_snake(Snake *snake);