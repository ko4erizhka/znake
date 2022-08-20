#include "Coords.h"
#include "Map.h"
#include "Fruit.h"
#include <ctime>
#include <cstdlib>	




void define_coords(Fruit* myfruit, int mapsize)
{
	using namespace std;
	srand(unsigned(time(0)));
	myfruit->coords.x = (rand() % mapsize);
	myfruit->coords.y = (rand() % mapsize);
}


void replace_fruit(Fruit* myfruit, Map* mymap)
{
	
	define_coords(myfruit, mymap->mapsize);
	while (get_symbol(mymap, myfruit->coords) != ' ') {
		define_coords(myfruit, mymap->mapsize);
	}

}

void remove_fruit(Fruit* myfruit, Map* mymap)
{
	mymap->map[myfruit->coords.y][myfruit->coords.x] = ' ';
}

void draw_fruit(Fruit* myfruit, Map* mymap)
{
	mymap->map[myfruit->coords.y][myfruit->coords.x] = myfruit->symbol;
}




