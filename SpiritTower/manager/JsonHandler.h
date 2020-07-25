#pragma once
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include "../../Player/Player.h"

/**
 *  @file JsonHandler.h
 *  @version 2.0
 *  @date 17/07/2020
 *  @class JsonHandler.
 *  @brief Controla los mensajes Json que ingresan al servidor.
 */
class JsonHandler {
public:
    /**
      * @brief usa los json obtenidos del mensaje.
    */
    static bool handlingReceivedData(Json::Value DataOne, Json::Value DataTwo, Json::Value DataThree, Json::Value DataFour, Player*& player);
    /**
      * @brief obtiene json de cada mensaje entrante.
    */
    static bool Deserialize(std::basic_string<char> streamOfJson, Player*& player);
};
