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
class Server : public ServerListener{
public:
    /**
   * @brief crea lector de mensajes entrantes.
   */
    void run();
protected:
    bool running = true;
    int  clientLength = sizeof(ClientSocket);
};

