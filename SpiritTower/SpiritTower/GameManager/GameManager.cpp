#include "GameManager.h"

void run();

GameManager* GameManager::instance = 0;

GameManager::GameManager() {
	player = new Player();
	breed = new breeder();
	//breed->newGeneration();
	matrixLevel.createMatrix(20, 20);
	nextLevel();
	//cout << Serialize::SerializeData(player,spectrumList,rats,specEye,chu,objectList,player);
	cout << "-------------------------------------------" << endl;
	inGame = true;
	this->starting = thread(run);
}

GameManager* GameManager::getInstance() {
	if (instance == 0) {
		instance = new GameManager();
	}
	return instance;
}

void GameManager::fillMap(Matrix mat) {
	Square* temp = matrixLevel.getHead();
	Square* temp2 = matrixLevel.getHead();
	int i = 0;
	int j = 0;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			map[i][j] = to_string(temp->getEntity());
			if (objectsFilled == false) {
				if (temp->getEntity() == 3) {
					Cofre* cofre = new Cofre();
					cofre->id = "K";
					cofre->posX = temp->getRowNumb();
					cofre->posY = temp->getColNumb();
					cofre->death = false;
					cofre->color = "g";
					objectList.push_back(cofre);
				}
				else if (temp->getEntity() == 4) {
					Jarron* jar = new Jarron();
					jar->id = "J";
					jar->posX = temp->getRowNumb();
					jar->posY = temp->getColNumb();
					jar->death = false;
					jar->color = "g";
					objectList.push_back(jar);
				}
			}
			temp = temp->getNexCol();
			j++;
		}
		j = 0;
		temp2 = temp2->getNexRow();
		temp = temp2;
		i++;
	}
	objectsFilled = true;
}

void GameManager::fillSpectrums() {
	string ids = "ABC";
	for (int i = 0; i < 3; i++) {
		Spectrum* temp = new Spectrum();
		//temp->patrollArea = new LinkedList();
		*temp = breed->getBestOne(i);
		temp->posX = spectrumPositions.at(level - 1).at(i)->getRowNumb();
		temp->posY = spectrumPositions.at(level - 1).at(i)->getColNumb();
		temp->tempX = spectrumPositions.at(level - 1).at(i)->getRowNumb();
		temp->tempY = spectrumPositions.at(level - 1).at(i)->getColNumb();
		temp->color = spectrumColors.at(level - 1).substr(i, 1);

		Square* sA1 = new Square();
		sA1->setRowNumb(spectrumPositions.at(level - 1).at(i)->getRowNumb());
		sA1->setColNumb(spectrumPositions.at(level - 1).at(i)->getColNumb());
		Square* sA4 = new Square();
		sA4->setRowNumb(spectrumFinalPosition.at(level - 1).at(i)->getRowNumb());
		sA4->setColNumb(spectrumFinalPosition.at(level - 1).at(i)->getColNumb());

		temp->patrollArea->addNode(sA1);
		temp->patrollArea->addNode(sA4);

		spectrumList.push_back(temp);
	}
}

void GameManager::displayMap() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void GameManager::chasing() {
	int everybodyFindPlayer = 0;
	PathFinding pathFind;
	int size = spectrumList.size();
	for (int i = 0; i < size; i++) {
		if (spectrumList.at(i)->catchPlayer != true) {
			everybodyFindPlayer = 1;
			break;
		}
	}
	if (everybodyFindPlayer == 1) {
		for (int i = 0; i < size; i++) {
			if (cycles % ((8 - (spectrumList.at(i))->getChase_speed()) * 2) == 0) {
				int x = (spectrumList.at(i))->tempX;
				int y = (spectrumList.at(i))->tempY;
				Square* start = matrixLevel.findSquare(x, y);
				Square* end = matrixLevel.findSquare(player->getPosX(), player->getPosY());
				if (start == end) {
					(spectrumList.at(i))->catchPlayer = true;
				}
				else if (spectrumList.at(i)->catchPlayer == false) {
					if (i!=spectIndex) {
						LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
						(spectrumList.at(i))->tempY = tempList.getHead()->getSquare()->getColNumb();
						(spectrumList.at(i))->tempX = tempList.getHead()->getSquare()->getRowNumb();
						cout << (spectrumList.at(i))->getId() << endl;
						cout << "JUEPUTAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
						tempList.display();
					}
					else {
						cout << "JOSE NECIOOOOOOOOO" << endl;
						breadCrumbing(spectrumList.at(i));
						cout << "MIERDAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
					}
					spectrumList.at(i)->movimientos++;
				}
			}
		}
		
	}
	else {
		this->chasingPlayer = false;
	}
}

void GameManager::mapUpdate() {
	fillMap(matrixLevel);
	auto its = spectrumList.begin();
	auto lasts = spectrumList.end();
	for (its; its != lasts; ++its) {
		int x = (*its)->tempX;
		int y = (*its)->tempY;
		map[x][y] = (*its)->getId();
	}
	for (int i = 0; i < rats.size(); i++) {
		int x = rats.at(i)->posX;
		int y = rats.at(i)->posY;
		map[x][y] = rats.at(i)->getId();
	}
	for (int i = 0; i < specEye.size(); i++) {
		int x = specEye.at(i)->posX;
		int y = specEye.at(i)->posY;
		map[x][y] = specEye.at(i)->getId();
	}
	for (int i = 0; i < chu.size(); i++) {
		int x = chu.at(i)->posX;
		int y = chu.at(i)->posY;
		map[x][y] = chu.at(i)->getId();
	}
	int xp = player->getPosX();
	int yp = player->getPosY();
	map[xp][yp] = player->getID();
	sendMap = Serialize::SerializeMatrix(map);
	//cout << sendMap << endl;
}

void GameManager::returnBack() {
	int posibleBackTrack = 0;
	BackTracking backTrack;
	auto it = spectrumList.begin();
	auto last = spectrumList.end();
	crumbs.clear();
	for (it; it != last; ++it) {
		if ((*it)->walking != true) {
			posibleBackTrack = 1;
			break;
		}
	}
	if (posibleBackTrack == 1) {
		auto it = spectrumList.begin();
		auto last = spectrumList.end();
		for (it; it != last; ++it) {
			if (cycles % 7 == 0) {
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
	}
	else {
		this->walking = true;
	}
}

void GameManager::patrolling() {
	PathFinding pathFind;
	int size = spectrumList.size();
	for (int i=0; i < size; i++) {
		if (searchingPlayer(rangeAnalizer(spectrumList.at(i)))) {
			teleportSpect((spectrumList.at(i))->posX, (spectrumList.at(i))->posY);
			walking = false;
			chasingPlayer = true;
			playerTempX = player->getPosX();
			playerTempY = player->getPosY();
			spectIndex = i;
			break;
		}
		if (cycles % ((8 - (spectrumList.at(i))->getSrch_speed()) * 2) == 0) {
			(spectrumList.at(i))->movimientos++;
			int initialX = (spectrumList.at(i))->tempX;
			int initialY = (spectrumList.at(i))->tempY;

			int endX = (spectrumList.at(i))->patrollArea->getTail()->getSquare()->getRowNumb();
			int endY = (spectrumList.at(i))->patrollArea->getTail()->getSquare()->getColNumb();

			Square* start = matrixLevel.findSquare(initialX, initialY);
			Square* end = matrixLevel.findSquare(endX, endY);

			if (start != end) {
				LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
				(spectrumList.at(i))->tempY = tempList.getHead()->getSquare()->getColNumb();
				(spectrumList.at(i))->tempX = tempList.getHead()->getSquare()->getRowNumb();
			}
			else {
				int tempX = (spectrumList.at(i))->patrollArea->getHead()->getSquare()->getRowNumb();
				int tempY = (spectrumList.at(i))->patrollArea->getHead()->getSquare()->getColNumb();
				(spectrumList.at(i))->patrollArea->getHead()->getSquare()->setRowNumb(endX);
				(spectrumList.at(i))->patrollArea->getHead()->getSquare()->setColNumb(endY);
				(spectrumList.at(i))->patrollArea->getTail()->getSquare()->setRowNumb(tempX);
				(spectrumList.at(i))->patrollArea->getTail()->getSquare()->setColNumb(tempY);
			}
		}
	}
}

LinkedList* GameManager::rangeAnalizer(Spectrum* spect) {
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
	analizeIm(result, im, spect->dir, spect);
	analizePa(result, pa, spect->dir, spect);
	return result;
}

void GameManager::analizeIm(LinkedList*& result, int impar, string dir, Spectrum* spect) {
	int x1, x2, y1, y2;
	for (int i = 1; i <= impar; i++) {
		if (dir == "N") {
			x1 = spect->tempX - i;
			y1 = spect->tempY + i;
			if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
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
			if (x1 > 0 && x1 < 20 && y1 > 0 && y1 < 19) {
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

void GameManager::analizePa(LinkedList*& result, int par, string dir, Spectrum* spect) {
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

void GameManager::fillEnemies() {
	string rids = "RTXN";
	string sids = "SE";
	string chuc = "H";
	//rat for
	for (int i = 0; i < ratCuantity.at(level - 1); i++) {
		RatonSimple* temp = new RatonSimple();
		temp->setId(rids.substr(i, 1));
		temp->posX = ratPositions.at(level - 1).at(i)->getRowNumb();
		temp->posY = ratPositions.at(level - 1).at(i)->getColNumb();
		rats.push_back(temp);

	}
	for (int i = 0; i < eyeCuantity.at(level - 1); i++) {
		OjoEspectral* temp = new OjoEspectral();
		temp->setId(sids.substr(i, 1));
		temp->posX = eyePositions.at(level - 1).at(i)->getRowNumb();
		temp->posY = eyePositions.at(level - 1).at(i)->getColNumb();
		specEye.push_back(temp);
	}
	for (int i = 0; i < chuCuantity.at(level - 1); i++) {
		ChuChu* temp = new ChuChu();
		temp->setId(chuc);
		temp->posX = chuPositions.at(level - 1).at(i)->getRowNumb();
		temp->posY = chuPositions.at(level - 1).at(i)->getColNumb();
		chu.push_back(temp);
	}
}

void run() {
	GameManager* gmr = GameManager::getInstance();
	while (gmr->inGame) {
		gmr->mapUpdate();
		gmr->displayMap();
		gmr->dataToSend = Serialize::SerializeData(gmr->player, gmr->spectrumList, gmr->rats, gmr->specEye, gmr->chu, gmr->objectList, gmr->player);
		gmr->moveRat();
		gmr->spectrumAttack();

		cout << gmr->player->getHealth() << endl;


		if (gmr->player->getHealth() <= 0) {
			cout << "JUGADOR HA MUERTO" << endl;
			gmr->level--;
			gmr->player->setHealth(5);
			gmr->player->setScore(gmr->player->getScore() - 300);
			cout << gmr->player->getHealth();
			cout << gmr->player->getScore();
			gmr->restartLvl = true;
			gmr->nextLevel();
			gmr->chasingPlayer = false;
			gmr->walking = true;
			gmr->restartLvl = false;
		}
		cout << gmr->player->getPosX() << "--" << gmr->player->getPosY() << endl;
		
		if (gmr->level == 3 || gmr->level == 4) {
			gmr->eyesVision();
			gmr->mapUpdate();
			gmr->displayMap();
			
		}
		if (gmr->matrixLevel.findSquare(gmr->player->getPosX(), gmr->player->getPosY())->getEntity() == 2) {
			gmr->chasingPlayer = false;
			cout << "ZONA SEGURA" << endl;
		}
		else if (gmr->matrixLevel.findSquare(gmr->player->getPosX(), gmr->player->getPosY())->getEntity() == 6) {
			gmr->objectsFilled = false;
			gmr->nextLevel();
			cout << "CAMBIE DE NIVEL" << endl;
			gmr->mapUpdate();
			gmr->displayMap();
			break;
		}
		if (gmr->walking == true) {
			gmr->patrolling();
			cout << "PATRULLANDO" << endl;
		}
		else if (gmr->chasingPlayer == true) {
			gmr->fillCrumbs();
			gmr->chasing();
			cout << "PERSIGUIENDO" << endl;
		}
		else if (gmr->chasingPlayer == false && gmr->walking == false) {
			gmr->returnBack();
			cout << "REGRESANDO" << endl;
		}
		cout << "----------------------------------------------" << endl;

		gmr->cycles++;
		
		cout << gmr->cycles << endl;
		this_thread::sleep_for(chrono::milliseconds(10));
		int size = gmr->spectrumList.size();
		for (int i = 0; i < size; i++) {
			cout << gmr->spectrumList.at(i)->getId() << "-----------" << gmr->spectrumList.at(i)->movimientos << "----"<<gmr->spectrumList.at(i)->getChase_speed()<<endl;
		}
	}
}

void GameManager::nextLevel() {
	level++;
	rats.clear();
	chu.clear();
	specEye.clear();
	objectList.clear();
	spectrumList.clear();
	crumbs.clear();
	if (level != 1 && restartLvl == false) {
		breed->newGeneration();
	}
	matrixLevel.fillMat(level);
	fillMap(matrixLevel);
	if (level == 1) {
		levelsFiller();
	}
	player->setPosX(playerPositions.at(level - 1).at(0)->getRowNumb());
	player->setPosY(playerPositions.at(level - 1).at(0)->getColNumb());
	fillSpectrums();
	fillEnemies();
}

void GameManager::levelsFiller() {
	//cantidad de ratones por nivel
	ratCuantity.push_back(4);
	ratCuantity.push_back(3);
	ratCuantity.push_back(2);
	ratCuantity.push_back(3);

	//cantidad de ojos espectrales por nivel
	eyeCuantity.push_back(0);
	eyeCuantity.push_back(0);
	eyeCuantity.push_back(2);
	eyeCuantity.push_back(2);

	//cantidad de chuchus por nivel
	chuCuantity.push_back(0);
	chuCuantity.push_back(1);
	chuCuantity.push_back(1);
	chuCuantity.push_back(1);


	//RATS
	vector<Square*> ratVect1;
	Square* rat1 = new Square();
	rat1->setRowNumb(4);
	rat1->setColNumb(3);
	Square* rat2 = new Square();
	rat2->setRowNumb(2);
	rat2->setColNumb(15);
	Square* rat3 = new Square();
	rat3->setRowNumb(10);
	rat3->setColNumb(12);
	Square* rat4 = new Square();
	rat4->setRowNumb(15);
	rat4->setColNumb(13);
	ratVect1.push_back(rat1);
	ratVect1.push_back(rat2);
	ratVect1.push_back(rat3);
	ratVect1.push_back(rat4);
	ratPositions.push_back(ratVect1);


	vector<Square*> ratVect2;
	Square* rat5 = new Square();
	rat5->setRowNumb(4);
	rat5->setColNumb(10);
	Square* rat6 = new Square();
	rat6->setRowNumb(18);
	rat6->setColNumb(2);
	Square* rat7 = new Square();
	rat7->setRowNumb(17);
	rat7->setColNumb(14);
	ratVect2.push_back(rat5);
	ratVect2.push_back(rat6);
	ratVect2.push_back(rat7);
	ratPositions.push_back(ratVect2);


	vector<Square*> ratVect3;
	Square* rat8 = new Square();
	rat8->setRowNumb(17);
	rat8->setColNumb(3);
	Square* rat9 = new Square();
	rat9->setRowNumb(10);
	rat9->setColNumb(11);
	ratVect3.push_back(rat8);
	ratVect3.push_back(rat9);
	ratPositions.push_back(ratVect3);


	vector<Square*> ratVect4;
	Square* rat10 = new Square();
	rat10->setRowNumb(11);
	rat10->setColNumb(1);
	Square* rat11 = new Square();
	rat11->setRowNumb(19);
	rat11->setColNumb(9);
	Square* rat12 = new Square();
	rat12->setRowNumb(14);
	rat12->setColNumb(14);
	ratVect4.push_back(rat10);
	ratVect4.push_back(rat11);
	ratVect4.push_back(rat12);
	ratPositions.push_back(ratVect4);


	//SPECTRALEYE
	vector<Square*> spectVect1;
	Square* spectEye = new Square();
	spectVect1.push_back(spectEye);
	eyePositions.push_back(spectVect1);


	vector<Square*> spectVect2;
	Square* spectEye0 = new Square();
	spectVect2.push_back(spectEye0);
	eyePositions.push_back(spectVect2);


	vector<Square*> spectVect3;
	Square* spectEye1 = new Square();
	spectEye1->setRowNumb(10);
	spectEye1->setColNumb(8);
	Square* spectEye2 = new Square();
	spectEye2->setRowNumb(3);
	spectEye2->setColNumb(14);
	spectVect3.push_back(spectEye1);
	spectVect3.push_back(spectEye2);
	eyePositions.push_back(spectVect3);

	vector<Square*> spectVect4;
	Square* spectEye3 = new Square();
	spectEye3->setRowNumb(15);
	spectEye3->setColNumb(5);
	Square* spectEye4 = new Square();
	spectEye4->setRowNumb(14);
	spectEye4->setColNumb(12);
	spectVect4.push_back(spectEye3);
	spectVect4.push_back(spectEye4);
	eyePositions.push_back(spectVect4);


	//CHUCHUS
	vector<Square*> chuVect0;
	Square* chu0 = new Square();
	chu0->setRowNumb(13);
	chu0->setColNumb(1);
	chuVect0.push_back(chu0);
	chuPositions.push_back(chuVect0);

	vector<Square*> chuVect1;
	Square* chu1 = new Square();
	chu1->setRowNumb(13);
	chu1->setColNumb(1);
	chuVect1.push_back(chu1);
	chuPositions.push_back(chuVect1);


	vector<Square*> chuVect2;
	Square* chu2 = new Square();
	chu2->setRowNumb(15);
	chu2->setColNumb(10);
	chuVect2.push_back(chu2);
	chuPositions.push_back(chuVect2);


	vector<Square*> chuVect3;
	Square* chu3 = new Square();
	chu3->setRowNumb(2);
	chu3->setColNumb(4);
	chuVect3.push_back(chu3);
	chuPositions.push_back(chuVect3);


	//ESPECTROS
	vector<Square*> spectrumVect1;
	Square* spectrum1 = new Square();
	spectrum1->setRowNumb(2);
	spectrum1->setColNumb(7);
	Square* spectrum2 = new Square();
	spectrum2->setRowNumb(10);
	spectrum2->setColNumb(18);
	Square* spectrum3 = new Square();
	spectrum3->setRowNumb(17);
	spectrum3->setColNumb(5);
	spectrumVect1.push_back(spectrum1);
	spectrumVect1.push_back(spectrum2);
	spectrumVect1.push_back(spectrum3);
	spectrumPositions.push_back(spectrumVect1);


	vector<Square*> spectrumVect2;
	Square* spectrum4 = new Square();
	spectrum4->setRowNumb(3);
	spectrum4->setColNumb(5);
	Square* spectrum5 = new Square();
	spectrum5->setRowNumb(18);
	spectrum5->setColNumb(5);
	Square* spectrum6 = new Square();
	spectrum6->setRowNumb(13);
	spectrum6->setColNumb(13);
	spectrumVect2.push_back(spectrum4);
	spectrumVect2.push_back(spectrum5);
	spectrumVect2.push_back(spectrum6);
	spectrumPositions.push_back(spectrumVect2);


	vector<Square*> spectrumVect3;
	Square* spectrum7 = new Square();
	spectrum7->setRowNumb(2);
	spectrum7->setColNumb(4);
	Square* spectrum8 = new Square();
	spectrum8->setRowNumb(11);
	spectrum8->setColNumb(1);
	Square* spectrum9 = new Square();
	spectrum9->setRowNumb(12);
	spectrum9->setColNumb(15);
	spectrumVect3.push_back(spectrum7);
	spectrumVect3.push_back(spectrum8);
	spectrumVect3.push_back(spectrum9);
	spectrumPositions.push_back(spectrumVect3);


	vector<Square*> spectrumVect4;
	Square* spectrum10 = new Square();
	spectrum10->setRowNumb(10);
	spectrum10->setColNumb(7);
	Square* spectrum11 = new Square();
	spectrum11->setRowNumb(5);
	spectrum11->setColNumb(10);
	Square* spectrum12 = new Square();
	spectrum12->setRowNumb(5);
	spectrum12->setColNumb(13);
	spectrumVect4.push_back(spectrum10);
	spectrumVect4.push_back(spectrum11);
	spectrumVect4.push_back(spectrum12);
	spectrumPositions.push_back(spectrumVect4);

	//////////////////////
	//posicones finales area de patrullaje

	vector<Square*> spectrumVect5;
	Square* spectrum13 = new Square();
	spectrum13->setRowNumb(2);
	spectrum13->setColNumb(10);
	Square* spectrum14 = new Square();
	spectrum14->setRowNumb(13);
	spectrum14->setColNumb(18);
	Square* spectrum15 = new Square();
	spectrum15->setRowNumb(17);
	spectrum15->setColNumb(8);
	spectrumVect5.push_back(spectrum13);
	spectrumVect5.push_back(spectrum14);
	spectrumVect5.push_back(spectrum15);
	spectrumFinalPosition.push_back(spectrumVect5);


	vector<Square*> spectrumVect6;
	Square* spectrum16 = new Square();
	spectrum16->setRowNumb(6);
	spectrum16->setColNumb(5);
	Square* spectrum17 = new Square();
	spectrum17->setRowNumb(18);
	spectrum17->setColNumb(8);
	Square* spectrum18 = new Square();
	spectrum18->setRowNumb(13);
	spectrum18->setColNumb(16);
	spectrumVect6.push_back(spectrum16);
	spectrumVect6.push_back(spectrum17);
	spectrumVect6.push_back(spectrum18);
	spectrumFinalPosition.push_back(spectrumVect6);


	vector<Square*> spectrumVect7;
	Square* spectrum19 = new Square();
	spectrum19->setRowNumb(2);
	spectrum19->setColNumb(7);
	Square* spectrum20 = new Square();
	spectrum20->setRowNumb(14);
	spectrum20->setColNumb(1);
	Square* spectrum21 = new Square();
	spectrum21->setRowNumb(12);
	spectrum21->setColNumb(18);
	spectrumVect7.push_back(spectrum19);
	spectrumVect7.push_back(spectrum20);
	spectrumVect7.push_back(spectrum21);
	spectrumFinalPosition.push_back(spectrumVect7);


	vector<Square*> spectrumVect8;
	Square* spectrum22 = new Square();
	spectrum22->setRowNumb(10);
	spectrum22->setColNumb(10);
	Square* spectrum23 = new Square();
	spectrum23->setRowNumb(8);
	spectrum23->setColNumb(10);
	Square* spectrum24 = new Square();
	spectrum24->setRowNumb(8);
	spectrum24->setColNumb(13);
	spectrumVect8.push_back(spectrum22);
	spectrumVect8.push_back(spectrum23);
	spectrumVect8.push_back(spectrum24);
	spectrumFinalPosition.push_back(spectrumVect8);

	//Spectrum colors list

	spectrumColors.push_back("ggg");
	spectrumColors.push_back("rrr");
	spectrumColors.push_back("bbb");
	spectrumColors.push_back("grb");


	///////player positions//////////

	vector<Square*> playerVect1;
	Square* player1 = new Square();
	player1->setRowNumb(18);
	player1->setColNumb(1);
	playerVect1.push_back(player1);
	playerPositions.push_back(playerVect1);


	vector<Square*> playerVect2;
	Square* player2 = new Square();
	player2->setRowNumb(1);
	player2->setColNumb(1);
	playerVect2.push_back(player2);
	playerPositions.push_back(playerVect2);


	vector<Square*> playerVect3;
	Square* player3 = new Square();
	player3->setRowNumb(1);
	player3->setColNumb(18);
	playerVect3.push_back(player3);
	playerPositions.push_back(playerVect3);


	vector<Square*> playerVect4;
	Square* player4 = new Square();
	player4->setRowNumb(18);
	player4->setColNumb(1);
	playerVect4.push_back(player4);
	playerPositions.push_back(playerVect4);


}

bool GameManager::searchingPlayer(LinkedList* rangeArea) {
	//cout << "BUSCANDO JUGADOR" << endl;
	int size = rangeArea->getSize();
	Node* temp = rangeArea->getHead();
	for (int i = 0; i < size; i++) {
		if (temp->getSquare()->getRowNumb() == player->getPosX() && temp->getSquare()->getColNumb() == player->getPosY()) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void GameManager::moveRat() {
	PathFinding pathFind;
	int size = rats.size();
	for (int i = 0; i < size; i++) {
		if (rats.at(i)->moving == false) {
			int random = 1 + rand() % 10;
			if (random < 3) {
				rats.at(i)->moving = true;
				rats.at(i)->randomMove(map);
			}
		}
		else {
			if (cycles % (14) == 0) {
				int ix = rats.at(i)->posX;
				int iy = rats.at(i)->posY;
				int fx = rats.at(i)->tempX;
				int fy = rats.at(i)->tempY;
				Square* start = matrixLevel.findSquare(ix, iy);
				Square* end = matrixLevel.findSquare(fx, fy);
				if (start == end) {
					rats.at(i)->moving = false;
				}
				else {
					LinkedList tempList = pathFind.searchPath(matrixLevel, start, end);
					rats.at(i)->posY = tempList.getHead()->getSquare()->getColNumb();
					rats.at(i)->posX = tempList.getHead()->getSquare()->getRowNumb();
				}
			}
		}
	}
}

void GameManager::objectsUpdate()
{
	for (int i = 0; i < objectList.size(); i++) {
		Objeto* temp = objectList.at(i);
		if (!(temp->given)) {
			if (temp->death) {
				if (temp->id == "J") {
					player->setHealth(player->getHealth() + 1);
					temp->given = 1;
				}
				else {
					player->setScore(player->getScore() + 100);
					temp->given = 1;
				}
			}
		}
	}
}

void GameManager::eyesVision()
{
	int size = specEye.size();
	for (int i = 0; i < size; i++) {
		if (specEye.at(i)->watched == false) {
			for (int j = -2; j <= 2; j++) {
				for (int k = -2; k <= 2; k++) {
					if (specEye.at(i)->posX + j == player->getPosX() && specEye.at(i)->posY + k == player->getPosY()) {
						teleportSpect(specEye.at(i)->posX, specEye.at(i)->posY);
						specEye.at(i)->watched = true;
					}
				}
			}
		}
		else{
			specEye.at(i)->watched = false;
			for (int j = -2; j <= 2; j++) {
				for (int k = -2; k <= 2; k++) {
					if (specEye.at(i)->posX + j == player->getPosX() && specEye.at(i)->posY + k == player->getPosY()) {
						specEye.at(i)->watched = true;
					}
				}
			}
		}
	}
}

void GameManager::teleportSpect(int x, int y){
	int size = spectrumList.size();
	for (int i = 0; i < size;i++) {
		if (spectrumList.at(i)->color == "b" && !spectrumList.at(i)->death) {
			spectrumList.at(i)->tempX = x;
			spectrumList.at(i)->tempY = y;
			chasingPlayer = true;
			walking = false;
			cout << "TELEPORT" << "---" << spectrumList.at(i)->getId() << endl;
		}
	}
}

void GameManager::spectrumAttack(){
	int size = spectrumList.size();
	if (cycles%7==0) {
		for (int i = 0; i < size; i++) {
			if (spectrumList.at(i)->tempX == player->getPosX() && spectrumList.at(i)->tempY == player->getPosY()) {
				if (player->getShield() == false) {
					player->setHealth(player->getHealth() - 1);
				}
			}
		}
	}
}

void GameManager::breadCrumbing(Spectrum* firsSpect){
	firsSpect->tempX = crumbs.front()->getRowNumb();
	firsSpect->tempY = crumbs.front()->getColNumb();
	crumbs.pop_front();
}

void GameManager::fillCrumbs(){
	if (playerTempX != player->getPosX() || playerTempY != player->getPosY()) {
		Square* playerPos = new Square;
		playerPos->setRowNumb(player->getPosX());
		playerPos->setColNumb(player->getPosY());
		crumbs.push_back(playerPos);
		playerTempX = player->getPosX();
		playerTempY = player->getPosY();
	}
}



