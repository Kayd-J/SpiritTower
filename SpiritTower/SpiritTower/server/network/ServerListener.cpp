#include "ServerListener.h"

int ServerListener::init() {
    WSADATA WSAData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk = WSAStartup(ver, &WSAData);
    if (wsOk != 0)::std::cerr << " ERROR. Iniciando WinSock " << std::endl;

    m_socket = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_addr.S_un.S_addr = ADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(54000);

    if (m_socket == INVALID_SOCKET) {
        std::cerr << " ERROR. Creando socket " << std::endl;
        shutDownSocket();
        return 0;
    }

    DWORD nonBlocking = 1;
    if (ioctlsocket(m_socket, FIONBIO, &nonBlocking) != 0) {
        std::cerr << " ERROR. On non-blocking " << std::endl;
        return 0;
    }

    if (bind(m_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << " ERROR. En enlace de socket " << std::endl;
        closesocket(m_socket);
        shutDownSocket();
        return 0;
    }
    return 1;
}
void ServerListener::shutDownSocket() {
    WSACleanup();
}
