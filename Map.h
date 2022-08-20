#pragma once
#include "Coords.h"

struct Map {
	int mapsize;
	char border = '#';
	char **map;
};


void create_map(Map* mymap, int mapsize);
void delete_map(Map* mymap);
void reset_map(Map* mymap);
void draw_map(Map* mymap);
char get_symbol(Map *mymap, Coords check_coords);