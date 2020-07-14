#include "Server.h"
#include "manager/JsonHandler.h"
void Server::run() {
    ZeroMemory(&ClientSocket, clientLength);
    char buf[1024];
    while (running) {
        ZeroMemory(buf, 1024);

        int bytesIn = recvfrom(m_socket, buf, 1024, 0, (sockaddr*)&ClientSocket, &clientLength);
        if (bytesIn == SOCKET_ERROR){
            continue;
        } 
        onMessageReceived(buf);
    }
    sendDisconnectMessage();
    closesocket(m_socket);
    shutDownSocket();
}
void Server::sendDisconnectMessage() {
    sendto(m_socket, (char*)&CLOSING_CLIENT, sizeof(CLOSING_CLIENT), 0, (struct sockaddr*)&ClientSocket, clientLength);
}
void Server::sendMessage(std::string message) {
    sendto(m_socket, (char*)&message, sizeof(message), 0, (struct sockaddr*)&ClientSocket, clientLength);
}
void Server::onMessageReceived(std::string message) {
    if (JsonHandler::Deserialize(message)) {
    }else {
        sendMessage(message);
    }
}

