#pragma once
#include <string>
#include <iostream>
#include "json-c/json.h"

using namespace std;
class Serialize {
public:
	static string SerializeMatrix(std::string MatrixMap[20][20]);
};

