#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList{
private: 
	Node* head;
	Node* tail;
	int size;
public:
	void addNode(Square* addNode);
	LinkedList();
	int getSize();
	Node* getHead();
	void display();
	void addTop(Square* square);
	void removeNode(Square* square);
	Node* getTail();
	bool isInList(Square* square);
	Square* getRandomNode();
};

