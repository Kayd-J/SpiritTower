#pragma once
//#include "network/ServerListener.h"
#include <string>
#include <iterator>
#include "messagesManager/JsonHandler.h"
#include "../GameManager/GameManager.h"

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

    /**
    * @param  message recibe el mensaje de los sockets
    * @brief el mensaje lo dirige al deserializador
    */
    void onMessageReceived(std::string message);

    /**
    * @param  message, el mensaje para enviar
    * @brief envia el mensaje al socket conectado
    */
    void sendMessage(std::string message);


    void sendDisconnectMessage();
    std::string CLOSING_CLIENT = "SERVERisCLOSING";
    std::string SENDING_DATA = "DATADEFAULT";
    int  clientLength = sizeof(ClientSocket);
protected:
    bool running = true;


};
