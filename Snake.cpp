#include "coords.h"
#include "Snake.h"
#include <cstring>
#include "Map.h"


void create_snake(Snake *snake, int cs_mapsize) {
	int map_center = cs_mapsize/2; //получаем центр карты
	snake->symbol = 'o';
	snake->direction = right;
	snake->body = {};
	Push(&snake->body,{map_center,map_center});			//вставляем первые два элемента змеи
	grow_snake(snake);
	grow_snake(snake);
}

void delete_snake(Snake *snake) {
	while (snake->body.head) {
		Pop(&snake->body);
	}
}

Coords check_next_move(Snake* snake,Map *map)
{
	MyQueue *snake_body = &snake->body;//указатель на тело змеи чтобы проще было
	Coords moving_segment = Back(snake_body);//получение координат головы во внешнюю переменную

	switch(snake->direction)
	{	
		
		case right:
			moving_segment.x = moving_segment.x+1;
			break;
		case up:
			moving_segment.y = moving_segment.y+1;
			break;
		case left:
			moving_segment.x = moving_segment.x-1;
			break;
		case down:
			moving_segment.y = moving_segment.y-1;
			break;
	}
	
	return moving_segment;
	
	
}

void move_snake(Snake *snake,Map *map){
	
	Pop(&snake->body);//удаление хвоста
	Push(&snake->body,check_next_move(snake,map));
}

void draw_snake(Snake *snake, Map *map){
	Node *tempbodypart = snake->body.head;
	while (tempbodypart->next_coords) {
		map->map[tempbodypart->coords_data.y][tempbodypart->coords_data.x] = snake->symbol;
		tempbodypart = tempbodypart->next_coords;
	}
	map->map[tempbodypart->coords_data.y][tempbodypart->coords_data.x] = snake->symbol;
		
}

void grow_snake(Snake *snake){
	
	Coords growing_segment = Back(&snake->body);
	switch(snake->direction)
	{	
		case right:
			growing_segment.x++;
			break;
		case up:
			growing_segment.y++;
			break;
		case left:
			growing_segment.x--;
			break;
		case down:
			growing_segment.y--;
			break;
	}
	
	Push(&snake->body,growing_segment);
}