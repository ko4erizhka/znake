#include "coords.h"
#include "Snake.h"
#include <cstring>
#include "Map.h"


void create_snake(Snake *snake, int cs_mapsize) {
	int map_center = cs_mapsize/2; //получаем центр карты

	snake->symbol = 'o';
	snake->length = 2;
	snake->snake_dir = right;
	snake->body = {};
	Push(&snake->body,{map_center,map_center});			//вставляем первые два элемента змеи
	Push(&snake->body,{map_center+1,map_center});
	Push(&snake->body,{map_center+2,map_center});
}

void delete_snake(Snake *snake) {

	while (snake->length>0) {
		Pop(&snake->body);
	}

}

void move_snake(Snake *snake){
	
	MyQueue *snake_body = &snake->body;//указатель на тело змеи чтобы проще было
	Coords moving_segment = Back(snake_body);//получение координат головы во внешнюю переменную
	Pop(snake_body);//удаление хвоста

	switch(snake->snake_dir)
	{	
		case stop:
			break;
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
	Push(snake_body,moving_segment);//вставка новой головы змеи
}

void draw_snake(Snake *snake, Map *map){
	Node *tempbodypart = snake->body.head;
	while (tempbodypart->next_coords) {
		map->map[tempbodypart->coords_data.y][tempbodypart->coords_data.x] = snake->symbol;
		tempbodypart = tempbodypart->next_coords;
	}
	map->map[tempbodypart->coords_data.y][tempbodypart->coords_data.x] = snake->symbol;
		
}