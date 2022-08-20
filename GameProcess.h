#pragma once
#include "Map.h"
#include "Snake.h"
#include "Fruit.h"

struct Game{bool gamecurrent=1;};

void InitializeZnake(Map *mymap, Snake *mysnake,Fruit *myfruit, int mapsize);
void GameOver();
void DisposeZnake(Map *mymap, Snake *mysnake);
void get_direction(Snake *snake, Game *mygame);