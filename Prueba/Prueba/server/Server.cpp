#include "Server.h"

void Server::run() {
    GameManager* game = GameManager::getInstance();
    ZeroMemory(&ClientSocket, clientLength);
    char buf[1024];
    while (running) {
        ZeroMemory(buf, 1024);
        int bytesIn = recvfrom(m_socket, buf, 1024, 0, (sockaddr*)&ClientSocket, &clientLength);
        if (bytesIn == SOCKET_ERROR) {
            continue;
        }
        sendDisconnectMessage();
        onMessageReceived(buf);
    }
    sendDisconnectMessage();
    closesocket(m_socket);
    shutDownSocket();
    game->starting.join();
}
void Server::sendDisconnectMessage() {
    sendto(m_socket, (char*)&CLOSING_CLIENT, sizeof(CLOSING_CLIENT), 0, (struct sockaddr*)&ClientSocket, clientLength);
}
void Server::sendMessage(std::string message) {
    sendto(m_socket, (char*)&message, message.length(), 0, (struct sockaddr*)&ClientSocket, clientLength);
}

void Server::onMessageReceived(std::string message) {
    GameManager* game = GameManager::getInstance();
    if (JsonHandler::Deserialize(message,game->player)) {
        sendMessage(message);
    }
    else {
        sendMessage(message);
    }
}
