#pragma once
#include "network/ServerListener.h"
#include <string>
#include <iterator>
/**
 *  @file Server.h
 *  @version 1.0
 *  @date 28/06/2020
 *  @author Joseph Jimenez.
 *  @class Server.
 *  @brief Controla ingreso de mensajes al servidor.
 */
class Server : public ServerListener {
public:
    /**
      * @brief crea lector de mensajes entrantes.
      */
    void run();
    void onMessageReceived(std::string message);
    void sendMessage(std::string message);
    void sendDisconnectMessage();
    std::string CLOSING_CLIENT = "SERVERisCLOSING";
    std::string SENDING_DATA = "DATADEFAULT";
    int  clientLength = sizeof(ClientSocket);
protected:
    bool running = true;
};

