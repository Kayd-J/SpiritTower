#pragma once
#include "network/ServerListener.h"
#include <string>
#include <iterator>
class Server :public ServerListener{
public:
    Server(const char* ipAddress, int port) : ServerListener(ipAddress, port) { }
    //Accepts and start to listen the client
    void run();
    std::string confirm = "Connected Successful \r\n";
protected:
    //Will handle the message
    virtual int onMessageReceived(int clientSocket, const char* msg, int length);
    //Sends the message
    virtual void sendMessage(int clientSocket, const char* msg, int length);
    //Sends a confirm message
    virtual void onClientConnected(int clientSocket);
};

