#pragma once
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../Matrix/Matrix.h"

using namespace std;
class BackTracking {
public:
	LinkedList searchPath(Matrix mat, Square* start, Square* end);
	Square* searchPath(Square*& square, LinkedList*& path, LinkedList*& visited);
};

