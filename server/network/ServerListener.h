#include <iostream>
#include <WS2tcpip.h>
#include <string>
#pragma comment (lib, "ws2_32.lib")
class ServerListener {
public:
    ServerListener(const char* ipAddress, int port) : m_ipAddress(ipAddress), m_port(port) { }
    //Inits the structure of the server
    int init();
protected:
    //Sends message
    void sendToClient(int clientSocket, const char* msg, int length);
    void onMessageReceived(int clientSocket, const char* msg, int length);
    virtual void onClientConnected(int clientSocket);
    SOCKET                   m_socket;          
    SOCKET                   client;
    sockaddr_in              client_addr{};      // Clients socket structure
    socklen_t                clientSize;         // Clients Size
private:
    sockaddr_in              server_addr{};      // Server socket structure
    std::string              m_ipAddress;        // IPAddress 
    int                      m_port;             // Port
};