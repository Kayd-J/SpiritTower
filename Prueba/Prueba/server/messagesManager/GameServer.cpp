#include "GameServer.h"


void GameServer::sendMessage(std::string message) {
    sendto(m_socket, (char*)&message, sizeof(message), 0, (struct sockaddr*)&ClientSocket, clientLength);
}

void GameServer::sendJSON(std::string message) {
    sendMessage(message);
}
    