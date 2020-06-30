#pragma once
#include <iostream>
#include "Square.h"

using namespace std;

class Node{
private:
	Square* square;
	Node* next;
public:
	Node* getNext();
	Square* getSquare();
	void setNext(Node* next);
	void setSquare(Square* square);
	Node();
};

