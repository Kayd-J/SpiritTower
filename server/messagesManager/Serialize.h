#pragma once
#include <string>
#include <iostream>
#include <json/json.h>
#include <json/value.h>
class Serialize {
public:
	static std::basic_string<char, std::char_traits<char>, std::allocator<char>> SerializeMap(std::string MatrixMap);
};

