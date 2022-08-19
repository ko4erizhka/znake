#include "Snake.h"
#include "Map.h"
#include "windows.h"

int main(){
	
	
	Map map;
	Snake snake;
	create_map(&map,22);
	create_snake(&snake,map.mapsize);
	reset_map(&map);
	for (int i = 0;i<8;i++){
		draw_snake(&snake, &map);
		draw_map(&map);
		move_snake(&snake);
		Sleep(1500);
		reset_map(&map);
		if (i == 2) snake.snake_dir = up;
		if (i == 4) snake.snake_dir = left;
		if (i == 6) snake.snake_dir = down;
	}
	
	delete_snake(&snake);
	delete_map(&map);

	return 1;
}