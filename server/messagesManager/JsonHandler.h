#pragma once
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include "../Server.h"
class JsonHandler : public Server {
public:
    static bool handlingReceivedData(Json::Value DataOne, Json::Value DataTwo);
    static bool Deserialize(std::basic_string<char> streamOfJson);
};