#pragma once
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include "../Server.h"
class JsonHandler : public Server{
public:
    static bool handlingReceivedData(std::string DataOne, Json::Value DataTwo, Json::Value DataThree);
    static bool Deserialize(std::basic_string<char> streamOfJson);
};

