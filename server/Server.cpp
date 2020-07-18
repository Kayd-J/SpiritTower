#include "Server.h"
#include "manager/JsonHandler.h"
#include "manager/Serialize.h"
void Server::run() {
    std::string map[20][20];
    ZeroMemory(&ClientSocket, clientLength);
    char buf[1024];
    std::string matrix[20][20];
    Serialize::SerializeMatrix(matrix);
    while (running) {
        ZeroMemory(buf, 1024);
        int bytesIn = recvfrom(m_socket, buf, 1024, 0, (sockaddr*)&ClientSocket, &clientLength);
        if (bytesIn == SOCKET_ERROR){
            continue;
        }
        onMessageReceived(buf);
    }
    closesocket(m_socket);
    shutDownSocket();
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

