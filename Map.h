#pragma once


struct Map {
	int mapsize;
	char **map;
};


void create_map(Map* mymap, int mapsize);
void delete_map(Map* mymap);
void reset_map(Map* mymap);
void draw_map(Map* mymap);