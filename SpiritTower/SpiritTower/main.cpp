#include <iostream>
#include"Algorithms/PathFinding.h"
#include "Algorithms/BackTracking.h"
#include <fstream>
#include <sstream>
#include "GameManager/GameManager.h"
#include "server/Server.h"

using namespace std;

int main() {

	Server server;
	if (server.init() != 0) {
		server.run();
	}

	return 0;
}