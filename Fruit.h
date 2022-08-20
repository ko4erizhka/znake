#pragma once
#include "Coords.h"
#include "Map.h"
#include "cstdlib"

struct Fruit
{
	Coords coords;
	char symbol = '@';
};

void draw_fruit(Fruit *myfruit, Map *mymap);
void replace_fruit(Fruit* myfruit, Map* mymap);
void remove_fruit(Fruit* myfruit, Map* mymap);
