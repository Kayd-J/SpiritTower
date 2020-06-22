#include "ServerListener.h"
int ServerListener::init() {

    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0)::std::cerr << "Can't Initialize winsock! Quitting" << std::endl; 

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket <= 0) std::cerr << "ERROR. Can't create socket";

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(m_port);
    inet_pton(AF_INET, m_ipAddress.c_str(), &server_addr.sin_addr);

    if (bind(m_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)std::cerr << "ERROR. Can't bind to IP/PORT";
    if (listen(m_socket, SOMAXCONN) == -1) std::cerr << "Can't Listen!";

    return m_socket;
}

void ServerListener::sendToClient(int clientSocket, const char* msg, int length) {
    send(clientSocket, msg, length, 0);
}
void ServerListener::onClientConnected(int clientSocket) {
}
void ServerListener::onMessageReceived(int clientSocket, const char* msg, int length) {
}