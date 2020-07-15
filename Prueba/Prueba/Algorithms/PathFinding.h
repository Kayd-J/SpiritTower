#pragma once
#include "../LinkedList/LinkedList.h"
#include <iostream>
#include <list>
#include"../Matrix/Matrix.h"

using namespace std;
class PathFinding{
public:
	LinkedList searchPath(Matrix mat,Square* start, Square* end);
	int heuristic(Square* start, Square* end);
	bool includes(list<Square*> list, Square* square);
};

