#pragma once
#include "LinkedList.h"
#include <iostream>
#include <list>

using namespace std;
class PathFinding{
public:
	list<Square*> openList;
	list<Square*> closedList;

	LinkedList pathList;

	LinkedList searchPath(Square* start, Square* end);

	int heuristic(Square* start, Square* end);

	bool includes(list<Square*> list, Square* square);
};

