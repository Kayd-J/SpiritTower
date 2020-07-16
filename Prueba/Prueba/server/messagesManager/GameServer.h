#pragma once
#include "../network/ServerListener.h"

class GameServer : public ServerListener {
public:
	void sendMessage(std::string message);
	void sendJSON(std::string message);
	int  clientLength = sizeof(ClientSocket);
};

