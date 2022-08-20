#include "Map.h"
#include "Coords.h"
#include <iostream>
#include "cstring"
#include "stdlib.h"

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
			mymap->map[y][x] = mymap->border;
		}
	}

	for (int y = 1; y < mymap->mapsize - 1; y++) {
		for (int x = 1; x < mymap->mapsize - 1; x++) {
			mymap->map[y][x] = ' ';
		}
	}
}

void draw_map(Map *mymap) {
	using namespace std;

	string screen;
	 
	for (int y = mymap->mapsize-1; y >= 0 ; y--) {
		for (int x = 0; x < mymap->mapsize; x++) {
			screen += mymap->map[y][x];
		}
		screen += "\n";
	}
	std::system("CLS");
	cout<<screen;
}

char get_symbol(Map *mymap, Coords check_coords){
	return mymap->map[check_coords.y][check_coords.x];
}