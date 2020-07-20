#pragma once
#include "network/ServerListener.h"
#include "manager/Serialize.h"
//#include "GameManager/GameManager.h"
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
class Server : public ServerListener{
public:
    /**
      * @brief crea lector de mensajes entrantes.
      */
    void run();
    /**
      * @brief lleva el mensaje a manejar.
      */
    void onMessageReceived(std::string message);
    /**
      * @brief envia mensajes a socket especifico
      */
    void sendMessage(std::string message);
    int  clientLength = sizeof(ClientSocket);
    std::string mensaje = "itsworking";
protected:
    bool running = true;
};

