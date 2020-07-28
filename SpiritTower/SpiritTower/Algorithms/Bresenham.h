#pragma once
#include <iostream>
#include "../Matrix/Square.h"


class Bresenham
{
public:
	int size = 20;
	string map[20][20];
	list<Square*> doBresenham(int x1, int y1, int x2, int y2);
	void print();
};

