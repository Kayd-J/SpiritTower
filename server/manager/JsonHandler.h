#pragma once
#include <iostream>
#include <json/json.h>
#include <json/value.h>
class JsonHandler{
public:
    static bool handlingReceivedData(std::string DataOne, std::string DataTwo, std::string DataThree, std::string DataFour);
    static bool Deserialize(std::basic_string<char> streamOfJson);
};

