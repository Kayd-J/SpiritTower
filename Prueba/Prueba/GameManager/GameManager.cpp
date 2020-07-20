#include "GameManager.h"

void run();

GameManager* GameManager::instance = 0;

GameManager::GameManager() {
	player = new Player();
	breed = new breeder();
	breed->newGeneration();
	matrixLevel.createMatrix(20,20);
	fillMap(matrixLevel);
	fillSpectrums();
	fillLevelList();
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
		*temp = breed->getBestOne(i);
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
			(*it)->posX = 10;
			(*it)->posY = 18;
			(*it)->tempX = 10;
			(*it)->tempY = 18;
		}
		else {
			(*it)->posX = 17;
			(*it)->posY = 5;
			(*it)->tempX = 17;
			(*it)->tempY = 5;
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
	int everybodyFindPlayer = 0;
	PathFinding pathFind;
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	for (it; it != last; ++it) {
		if ((*it)->catchPlayer != true) {
			everybodyFindPlayer = 1;
			break;
		}
	}
	if (everybodyFindPlayer == 1) {
		auto it = spectrumList.begin();
		auto last = spectrumList.end();
		for (it; it != last; ++it) {
			int x = (*it)->tempX;
			int y = (*it)->tempY;
			Square* start = matrixLevel.findSquare(x, y);
			Square* end = matrixLevel.findSquare(player->posX, player->posY);
			if (start == end) {
				(*it)->catchPlayer = true;
			}
			else if ((*it)->catchPlayer == false) {
				LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
				(*it)->tempY = tempList.getHead()->getNext()->getSquare()->getColNumb();
				(*it)->tempX = tempList.getHead()->getNext()->getSquare()->getRowNumb();
				cout << (*it)->getId() << endl;
				tempList.display();
			}
		}
	}
	else {
		this->chasingPlayer = false;
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
	int xp = player->posX;
	int yp = player->posY;
	map[xp][yp] = player->ids;
	sendMap = Serialize::SerializeMatrix(map);
	//cout << sendMap << endl;
}

void GameManager::returnBack(){
	int posibleBackTrack = 0;
	BackTracking backTrack;
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	for(it; it != last; ++it) {
		if ((*it)->walking != true) {
			posibleBackTrack = 1;
			break;
		}
	}
	if (posibleBackTrack == 1) {
		auto it = spectrumList.begin();
		auto last = spectrumList.end();
		for (it; it != last; ++it) {
			int x = (*it)->tempX;
			int y = (*it)->tempY;
			Square* start = matrixLevel.findSquare(x, y);
			Square* end = matrixLevel.findSquare((*it)->posX, (*it)->posY);
			if (start != end) {
				if ((*it)->backTrackPath.getSize() == 0) {
					(*it)->backTrackPath = backTrack.searchPath(matrixLevel, start, end);
				}
				else {
					(*it)->tempY = (*it)->backTrackPath.getHead()->getNext()->getSquare()->getColNumb();
					(*it)->tempX = (*it)->backTrackPath.getHead()->getNext()->getSquare()->getRowNumb();
					cout << (*it)->getId() << endl;
					(*it)->backTrackPath.display();
					(*it)->backTrackPath.removeNode((*it)->backTrackPath.getHead()->getSquare());
				}
			}
			else {
				(*it)->walking = true;
			}
		}
	}
	else {
		this->walking = true;
	}
}

void GameManager::patrolling(){
	PathFinding pathFind;
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	for (it; it != last; ++it) {

		int initialX = (*it)->tempX;
		int initialY = (*it)->tempY;

		int endX = (*it)->patrollArea->getTail()->getSquare()->getRowNumb();
		int endY = (*it)->patrollArea->getTail()->getSquare()->getColNumb();

		Square* start = matrixLevel.findSquare(initialX, initialY);
		Square* end = matrixLevel.findSquare(endX,endY);

		if (start != end) {
			LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
			(*it)->tempY = tempList.getHead()->getNext()->getSquare()->getColNumb();
			(*it)->tempX = tempList.getHead()->getNext()->getSquare()->getRowNumb();
			tempList.display();
		}
		else {
			int tempX = (*it)->patrollArea->getHead()->getSquare()->getRowNumb();
			int tempY = (*it)->patrollArea->getHead()->getSquare()->getColNumb();
			(*it)->patrollArea->getHead()->getSquare()->setRowNumb(endX);
			(*it)->patrollArea->getHead()->getSquare()->setColNumb(endY);
			(*it)->patrollArea->getTail()->getSquare()->setRowNumb(tempX);
			(*it)->patrollArea->getTail()->getSquare()->setColNumb(tempY);
		}
	}
}

void GameManager::fillLevelList(){
	if (this->level == 1) {
		int spec = 1;
		auto it = spectrumList.begin();
		auto last = spectrumList.end();
		for (it; it != last; ++it) {
			(*it)->patrollArea = new LinkedList();
			if (spec == 1) {
				Square* sA1 = new Square();
				sA1->setColNumb(7);
				sA1->setRowNumb(2);
				Square* sA4 = new Square();
				sA4->setColNumb(10);
				sA4->setRowNumb(2);
				(*it)->patrollArea->addNode(sA1);
				(*it)->patrollArea->addNode(sA4);
			}
			if (spec == 2) {
				Square* sB1 = new Square();
				sB1->setColNumb(18);
				sB1->setRowNumb(10);
				Square* sB4 = new Square();
				sB4->setColNumb(18);
				sB4->setRowNumb(13);
				(*it)->patrollArea->addNode(sB1);
				(*it)->patrollArea->addNode(sB4);

			}
			if (spec == 3) {
				Square* sC1 = new Square();
				sC1->setColNumb(5);
				sC1->setRowNumb(17);
				Square* sC4 = new Square();
				sC4->setColNumb(8);
				sC4->setRowNumb(17);
				(*it)->patrollArea->addNode(sC1);
				(*it)->patrollArea->addNode(sC4);
			}
			spec++;
		}
		spec = 1;
	}
}

LinkedList* GameManager::rangeAnalizer(Spectrum* spect){
	LinkedList* result = new LinkedList();
	int im = 0;
	int pa = 0;
	for (int i = 1; i <= spect->getRange(); i++) {
		if (i % 2 == 0) {
			pa += 1;
		}
		else {
			im += 1;
		}
	}
	analizeIm(result, im, spect->dir,spect);
	analizePa(result,pa,spect->dir,spect);
	return result;
}

void GameManager::analizeIm(LinkedList*& result, int impar, string dir, Spectrum* spect){
	int x1, x2, y1, y2;
	for (int i = 1; i <= impar; i++) {
		if (dir == "N") {
			x1 = spect->tempX - i;
			y1 = spect->tempY + i;
			if (x1 >0 && x1 < 20 && y1 > 0 && y1 < 19) {
				result->addNode(matrixLevel.findSquare(x1, y1));
			}
			x2 = spect->tempX - i;
			y2 = spect->tempY - i;
			if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
				result->addNode(matrixLevel.findSquare(x2, y2));
			}
		}
		else if (dir == "S") {
			x1 = spect->tempX + i;
			y1 = spect->tempY + i;
			if (x1 >0 && x1 < 20 && y1 > 0 && y1 < 19) {
				result->addNode(matrixLevel.findSquare(x1, y1));
			}
			x2 = spect->tempX + i;
			y2 = spect->tempY - i;
			if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
				result->addNode(matrixLevel.findSquare(x2, y2));
			}
		}
		else if (dir == "W") {
			x1 = spect->tempX + i;
			y1 = spect->tempY - i;
			if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
				result->addNode(matrixLevel.findSquare(x1, y1));
			}
			x2 = spect->tempX - i;
			y2 = spect->tempY - i;
			if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
				result->addNode(matrixLevel.findSquare(x2, y2));
			}
		}
		else {
			x1 = spect->tempX + i;
			y1 = spect->tempY + i;
			if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
				result->addNode(matrixLevel.findSquare(x1, y1));
			}
			x2 = spect->tempX - i;
			y2 = spect->tempY + i;
			if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
				result->addNode(matrixLevel.findSquare(x2, y2));
			}
		}
	}
}

void GameManager::analizePa(LinkedList*& result, int par, string dir, Spectrum* spect){
	int x1, x2, y1, y2;
	for (int i = 0; i < par; i++) {
		for (int j = i; j >= 0; j--) {
			if (dir == "N") {
				x1 = spect->tempX - 1 - i;
				y1 = spect->tempY + j;
				if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
					result->addNode(matrixLevel.findSquare(x1, y1));
				}
				x2 = spect->tempX - 1 - i;
				y2 = spect->tempY - j;
				if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
					result->addNode(matrixLevel.findSquare(x2, y2));
				}
			}
			else if (dir == "S") {
				x1 = spect->tempX + 1 + i;
				y1 = spect->tempY + j;
				if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
					result->addNode(matrixLevel.findSquare(x1, y1));
				}
				x2 = spect->tempX + 1 + i;
				y2 = spect->tempY - j;
				if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
					result->addNode(matrixLevel.findSquare(x2, y2));
				}
			}
			else if (dir == "W") {
				x1 = spect->tempX + j;
				y1 = spect->tempY - 1 - i;
				if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
					result->addNode(matrixLevel.findSquare(x1, y1));
				}
				x2 = spect->tempX - j;
				y2 = spect->tempY - 1 - i;
				if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
					result->addNode(matrixLevel.findSquare(x2, y2));
				}
				
			}
			else {
				x1 = spect->tempX + j;
				y1 = spect->tempY + 1 + i;
				if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
					result->addNode(matrixLevel.findSquare(x1, y1));
				}
				x2 = spect->tempX - j;
				y2 = spect->tempY + 1 + i;
				if (x2 > 0 && x2 < 20 && y2 > 0 && y2 < 19) {
					result->addNode(matrixLevel.findSquare(x2, y2));
				}
			}
		}
	}
}

void run() {
	GameManager* gmr = GameManager::getInstance();
	while (gmr->inGame) {
		gmr->mapUpdate();
		gmr->displayMap();
		//gmr->gameServer.sendJSON(gmr->sendMap);


		auto it = gmr->spectrumList.begin();
		auto last = gmr->spectrumList.end();
		for (it; it != last; ++it) {
			LinkedList* list = new LinkedList();
			list = gmr->rangeAnalizer(*it);
			int size1 = list->getSize();
			Node* temp = list->getHead();
			for (int i = 0; i < size1; i++) {
				gmr->map[temp->getSquare()->getRowNumb()][temp->getSquare()->getColNumb()] = (*it)->getId();
				temp = temp->getNext();
			}

		}
		cout << "--------------------------------------" << endl;
		gmr->displayMap();
		int a = 0;
		while (a < 10) {
			cout << gmr->player->posX << endl;
			this_thread::sleep_for(chrono::milliseconds(1000));
			a++;
		}
		gmr->mapUpdate();
		gmr->displayMap();
		break;
		/*
		gmr->displayMap();
		if (gmr->walking == true) {
			gmr->patrolling();
		}
		else if (gmr->chasingPlayer == true) {
			gmr->chasing();
		}
		else if (gmr->chasingPlayer == false && gmr->walking == false) {
			gmr->returnBack();
		}
		cout << "----------------------------------------------" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		*/
	}
}