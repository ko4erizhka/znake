#pragma once
#include "Coords.h"

struct Node {
	Coords coords_data;
	Node *next_coords; 
};

struct MyQueue {
	Node *head;
	Node *tail;	
};


void Push(MyQueue *myqueue, Coords newsegment);
void Pop(MyQueue *myqueue);
Coords Front(MyQueue *myqueue);
Coords Back(MyQueue *myqueue);