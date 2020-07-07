#pragma once
#include <iostream>
#include "LinkedList.h"
#include "Matrix.h"

using namespace std;
class BackTracking{
public:
	LinkedList searchPath(Matrix mat, Square* start, Square* end);
	Square* searchPath(Square* square, LinkedList* path, LinkedList* visited);
};

