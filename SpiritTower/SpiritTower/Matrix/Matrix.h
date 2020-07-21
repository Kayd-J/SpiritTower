#pragma once
#include <iostream>
#include "Square.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include<string>

using namespace std;
class Matrix : public exception {
private:
	Square* head;
	Square* tail;
	int size;
	int rows;
	int cols;
public:
	void createMatrix(int rows, int cols, int file);
	Matrix();
	void display();
	int getSize();
	void addNeighbors();
	Square* getHead();
	Square* getTail();
	int getRandomValue();
	void resetMat();
	void removeNeighbors();
	void fillMat(int file);
	Square* findSquare(int row, int col);
};
