#include "GameManager.h"

void run();

GameManager* GameManager::instance = 0;

GameManager::GameManager() {
	matrixLevel.createMatrix(20,20);
	fillMap(matrixLevel);
	fillSpectrums();
	cout << "-------------------------------------------" << endl;
	inGame = true;
	this->starting = thread(run);
}

GameManager* GameManager::getInstance(){
	if (instance == 0) {
		instance = new GameManager();
	}
	return instance;
}

void GameManager::fillMap(Matrix mat){
	Square* temp = matrixLevel.getHead();
	Square* temp2 = matrixLevel.getHead();
	int i = 0;
	int j = 0;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			map[i][j] = to_string(temp->getEntity());
			temp = temp->getNexCol();
			j++;
		}
		j = 0;
		temp2 = temp2->getNexRow();
		temp = temp2;
		i++;
	}
}

void GameManager::fillSpectrums(){
	string ids = "ABC";
	for (int i = 0; i < 3; i++) {
		Spectrum* temp = new Spectrum();
		temp->setId(ids.substr(i,1));
		spectrumList.push_back(temp);
	}
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	int b = 3;
	for (it; it != last; ++it) {
		if (b==3) {
			(*it)->posX = 2;
			(*it)->posY = 7;
			(*it)->tempX = 2;
			(*it)->tempY = 7;
		}
		else if (b==2) {
			(*it)->posX = 5;
			(*it)->posY = 2;
			(*it)->tempX = 5;
			(*it)->tempY = 2;
		}
		else {
			(*it)->posX = 14;
			(*it)->posY = 6;
			(*it)->tempX = 14;
			(*it)->tempY = 6;
		}
		b--;
	}
}

void GameManager::displayMap(){
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
}

void GameManager::chasing(){
	PathFinding pathFind;
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	for (it; it != last; ++it) {
		int x = (*it)->tempX;
		int y = (*it)->tempY;
		Square* start = matrixLevel.findSquare(x, y);
		Square* end = matrixLevel.findSquare(player.posX, player.posY);
		if (start == end) {
			(*it)->findPlayer = true;
		}
		else if ((*it)->findPlayer == false) {
			LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
			(*it)->tempY = tempList.getHead()->getNext()->getSquare()->getColNumb();
			(*it)->tempX = tempList.getHead()->getNext()->getSquare()->getRowNumb();
			cout << (*it)->getId() << endl;
			tempList.display();
		}
	}
}

void GameManager::mapUpdate(){
	fillMap(matrixLevel);
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	for (it; it != last; ++it) {
		int x = (*it)->tempX;
		int y = (*it)->tempY;
		map[x][y] = (*it)->getId();
	}
	int xp = player.posX;
	int yp = player.posY;
	map[xp][yp] = player.ids;
}


void run() {
	GameManager* gmr = GameManager::getInstance();
	while (gmr->inGame) {
		gmr->mapUpdate();
		gmr->displayMap();
		gmr->chasing();
		cout << "----------------------------------------------" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}