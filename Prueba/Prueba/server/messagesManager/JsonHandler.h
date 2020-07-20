#pragma once
#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include "../Server.h"
/**
 *  @file JsonHandler.h
 *  @version 1.0
 *  @date 17/07/2020
 *  @author Joseph Jimenez.
 *  @class JsonHandler.
 *  @brief Controla los mensajes Json que ingresan al servidor.
 */
class JsonHandler : public Server {
public:
    /**
      * @brief usa los json obtenidos del mensaje.
    */
    static bool handlingReceivedData(Json::Value DataOne, Json::Value DataTwo);
    /**
      * @brief obtiene json de cada mensaje entrante.
    */
    static bool Deserialize(std::basic_string<char> streamOfJson);
};
