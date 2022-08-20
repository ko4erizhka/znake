#include "GameProcess.h"
#include "Map.h"
#include "Snake.h"
#include "Fruit.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

void InitializeZnake(Map *mymap, Snake *mysnake, Fruit *myfruit, int mapsize){
	
	create_map(mymap,mapsize);
	reset_map(mymap);
	create_snake(mysnake,mapsize);
	replace_fruit(myfruit, mymap);
}

void GameOver(){
	system("CLS");
	using namespace std;
	string GameOverArr[] = {
	"  [][]      [][]   []    [] [][][][]",
	"[]    []  []    [] [][][][] []      ",
	"[]        []    [] [] [] [] []      ",
	"[]  [][]  [][][][] []    [] [][][]  ",
	"[]    []  []    [] []    [] []      ",
	"  [][]    []    [] []    [] [][][][]",
	"									 ",
	"  [][]    []    [] [][][][] [][][]  ",
	"[]    []  []    [] []       []    []",
	"[]    []  []    [] []       [][][]  ",
	"[]    []   []  []  [][][]   []    []",
	"[]    []   []  []  []       []    []",
	"  [][]       []    [][][][] []    []"
	};
	
	for(int i = 0;i<=12;i++){
		system("CLS");
		for(int j = 0; j<=i;j++){
			cout<<GameOverArr[j]<<endl;
			
		}
	Sleep(50);
	
	}
}

void DisposeZnake(Map *mymap, Snake *mysnake){
	delete_map(mymap);
	delete_snake(mysnake);
}

void get_direction(Snake *snake, Game *mygame){

	while (true) {
		if (GetKeyState(27) < 0){mygame->gamecurrent = 0; break;}
		else if (GetKeyState(13) < 0){}
		else if (GetKeyState(37) < 0 && snake->direction != right) //left
		{
			snake->direction = left;
		}
		else if (GetKeyState(38) < 0 && snake->direction != down ) {//up
			snake->direction = up;
		}
		else if (GetKeyState(39) < 0 && snake->direction != left ) {//right
			snake->direction = right;
		}
		else if (GetKeyState(40) < 0 && snake->direction != up) {//down
			snake->direction = down;
		}
	}

}