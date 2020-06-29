#include "Server.h"
void Server::run() {
    ZeroMemory(&ClientSocket, clientLength);
    char buf[1024];
    while (running) {
        ZeroMemory(buf, 1024);

        int bytesIn = recvfrom(m_socket, buf, 1024, 0, (sockaddr*)&ClientSocket, &clientLength);
        if (bytesIn == SOCKET_ERROR){
            continue;
        } 
        std::cout << "Message recv from " << buf << std::endl;
    }
    closesocket(m_socket);
    shutDownSocket();
}
