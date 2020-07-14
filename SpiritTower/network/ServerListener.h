#include <iostream>
#include <WS2tcpip.h>
#include <string>
#pragma comment (lib, "ws2_32.lib")
/**
 *  @file ServerListener.h
 *  @version 1.0
 *  @date 28/06/2020
 *  @author Joseph Jimenez.
 *  @class ServerListener.
 *  @brief Capa de Red para iniciar el Server UDP.
 */
class ServerListener {
public:
    /**
     * @brief init inicia los componentes de la red.
     * @return 1 Si todo sale bien al iniciar componentes de sockets.
     */
    int init();
    /**
     * @brief cierra componentes de sockets.
     */
    void shutDownSocket();
protected:
    SOCKET                   m_socket;
    sockaddr_in              ClientSocket;
    sockaddr_in              server_addr;
};