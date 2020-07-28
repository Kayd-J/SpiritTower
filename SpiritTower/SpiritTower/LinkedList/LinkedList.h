/**
* @file LinkedList.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title LinkedList
* @brief Lista doblemente Enlazada de Nodos
*/
#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
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
	void setHead(Node* head);
};

