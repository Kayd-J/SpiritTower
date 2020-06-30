#pragma once
#include <iostream>
#include "Square.h"
#include <time.h>
#include <stdlib.h>
#include "PathFinding.h"

using namespace std;
class Matrix{
private:
	Square* head;
	Square* tail;
	int size;
	int rows;
	int cols;
public:
	void createMatrix(int rows, int cols);
	Matrix();
	void display();
	int getSize();
	void addNeighbors();
	Square* getHead();
	PathFinding pathFind;
	Square* getTail();
	int getRandomValue();
};


