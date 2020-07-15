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

	/*
	cout << "-------------------------------------------------" << endl;

	game->displayMap();

	Square* start = game->matrixLevel.findSquare(1, 3);
	Square* end = game->matrixLevel.findSquare(2, 8);


	PathFinding pathFind;
	pathFind.searchPath(game->matrixLevel, start, end).display();

	cout << "-------------------------------------------------" << endl;

	BackTracking backTrack;
	backTrack.searchPath(game->matrixLevel,end,start).display();
	
	*/
	return 0;
}
