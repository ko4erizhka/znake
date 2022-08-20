#include "Snake.h"
#include "Map.h"
#include "Fruit.h"
#include "GameProcess.h"
#include "windows.h"
#include <thread>


int main() {

	Game mygame;
	Map map;
	Snake snake;
	Fruit fruit;

	InitializeZnake(&map, &snake, &fruit, 22);
	std::thread first (get_direction,&snake,&mygame);
	
	while (mygame.gamecurrent) {

		int speed = 100;
		int i = 0;

		draw_snake(&snake, &map);
		draw_fruit(&fruit, &map);
		draw_map(&map);
		Sleep(speed);
		
		


		if (get_symbol(&map, check_next_move(&snake, &map)) == map.border || get_symbol(&map, check_next_move(&snake, &map)) == snake.symbol)
		{

			break;
		}
		else if (get_symbol(&map, check_next_move(&snake, &map)) == fruit.symbol) {
			remove_fruit(&fruit, &map);
			replace_fruit(&fruit, &map);
			grow_snake(&snake);
			i+=1;
			if (i%5 == 0) speed -=1;

		}

		move_snake(&snake, &map);
		reset_map(&map);
		
		
	}
	
	DisposeZnake(&map, &snake);
	GameOver();
	first.join();
	return 0;
}