#pragma once
#include <iostream>
#include "Square.h"
#include <time.h>
#include <stdlib.h>

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
	Square* getTail();
	int getRandomValue();
	void resetMat();
	void removeNeighbors();
};


