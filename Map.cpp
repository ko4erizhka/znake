#include "Map.h"
#include <iostream>
#include "cstring"

void create_map(Map *mymap, int mapsize){
	mymap->mapsize = mapsize;
	mymap->map = new char* [mapsize];
	for (int i = 0; i < mapsize; i++) {
		mymap->map[i] = new char[mapsize];
	}
}

void delete_map(Map *mymap){

	for (int i = 0; i < mymap->mapsize; i++) {
		delete[] mymap->map[i];
	}
	delete[] mymap->map;
	memset(mymap,0,sizeof(Map));

}

void reset_map(Map *mymap) {

	for (int y = 0; y < mymap->mapsize; y++) {
		for (int x = 0; x < mymap->mapsize; x++) {
			mymap->map[y][x] = '#';
		}
	}

	for (int y = 1; y < mymap->mapsize - 1; y++) {
		for (int x = 1; x < mymap->mapsize - 1; x++) {
			mymap->map[y][x] = ' ';
		}
	}
}

void draw_map(Map *mymap) {
	for (int y = 0; y < mymap->mapsize; y++) {
		for (int x = 0; x < mymap->mapsize; x++) {
			std::cout << mymap->map[y][x];
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n\n\n\n\n\n";
}