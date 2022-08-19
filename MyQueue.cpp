#include "MyQueue.h"

bool IsEmpty(MyQueue *myqueue){
	return !myqueue->head;
}


void Push(MyQueue *myqueue, Coords new_coords){
	
	Node *new_node = new Node;				//создание нового узла для присвоения после
	new_node->coords_data = new_coords;		//присваивание ему новых координат
	new_node->next_coords = nullptr;		//зануление указателя на следующий элемент тк добавляется в конец

	
	if (IsEmpty(myqueue)) {
		myqueue->head = new_node;			//тк очередь пуста то голова и хвост это одно и то же
		myqueue->tail = new_node;
	} else {
		myqueue->tail->next_coords = new_node; //если очередь не пуста в следующее звено после хвоста добавляется узел 
		myqueue->tail=myqueue->tail->next_coords;//он назначается последнимм
	}
	
}

void Pop(MyQueue *myqueue){
	Node *oldhead = myqueue->head;			//создается указатель на старую голову чтобы не потерять ее в памяти
	myqueue->head = myqueue->head->next_coords;//присваивается новая голова
	delete oldhead;//память старой головы возвращается
}

Coords Front(MyQueue *myqueue){
	return myqueue->head->coords_data;
}

Coords Back(MyQueue *myqueue){
	return myqueue->tail->coords_data;
}