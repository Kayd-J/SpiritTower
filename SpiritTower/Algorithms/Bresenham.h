#pragma once
class Bresenham
{
public:
	int size = 20;
	char map[20][20];
	void doBresenham(int x1, int y1, int x2, int y2);
	void print();
};

