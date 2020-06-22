#include "Server.h"
void Server::run() {
    bool running = true;
    while (running) {
        client = accept(m_socket, (struct sockaddr*)&client_addr, &clientSize);
        onClientConnected(client);
        int bytesReceived;
        do {
            char buffer[4096];
            ZeroMemory(buffer, 0, 4096);
            bytesReceived = recv(client, buffer, 4096, 0);
            if (bytesReceived > 0) {
                onMessageReceived(client, buffer, bytesReceived);
            }
        } while (bytesReceived >= 0);
        closesocket(client);
        WSACleanup();
        running = false;
        system("pause");
    }
}
int Server::onMessageReceived(int clientSocket, const char* msg, int length) {
    printf("-->%s\n", msg);
    if (msg == "/."){
        closesocket(m_socket);
    }
    else {
        sendMessage(clientSocket, msg, length);
    }
    return 0;
}
void Server::sendMessage(int clientSocket, const char* msg, int length) {
    sendToClient(clientSocket, msg, length + 1);
}
void Server::onClientConnected(int clientSocket) {
    sendToClient(clientSocket, confirm.c_str(), confirm.size() + 1);
}