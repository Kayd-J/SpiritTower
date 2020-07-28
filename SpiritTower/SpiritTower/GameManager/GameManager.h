#pragma once
#include "../Matrix/Matrix.h"
#include "../Player/Player.h"
#include "../Enemies/Spectrum.h"
#include <thread>
#include <chrono>
#include <string>
#include "../Algorithms/PathFinding.h"
#include "../Algorithms/BackTracking.h"
#include "../server/messagesManager/Serialize.h"
#include "../server/messagesManager/GameServer.h"
#include "../Enemies/breeder.h"
#include "../Enemies/ChuChu.h"
#include "../Enemies/OjoEspectral.h"
#include "../Enemies/RatonSimple.h"
#include "../Objects/Cofre.h"
#include "../Objects/Jarron.h"
#include "../Objects/Objeto.h"
#include "../Algorithms/Bresenham.h"


using namespace std;

class GameManager {
private:
	static GameManager* instance;
	GameManager();


public:
	Player* player;
	GameServer gameServer;
	bool chasingPlayer = false;
	bool walking = true;
	static GameManager* getInstance();
	Matrix matrixLevel;
	string map[20][20];
	string sendMap;
	void fillMap(Matrix mat);
	void fillSpectrums();
	void displayMap();
	void chasing();
	thread starting;
	bool inGame = false;
	void mapUpdate();
	void returnBack();
	void patrolling();
	int level = 0;
	LinkedList* rangeAnalizer(Spectrum* spect);
	void analizeIm(LinkedList*& result, int impar, string dir, Spectrum* spect);
	void analizePa(LinkedList*& result, int pa, string dir, Spectrum* spect);
	breeder* breed;
	vector<RatonSimple*> rats;
	vector<OjoEspectral*> specEye;
	vector<ChuChu*> chu;
	vector<Spectrum*> spectrumList;
	void fillEnemies();
	vector<int> ratCuantity;
	vector<int> eyeCuantity;
	vector<int> chuCuantity;
	vector<vector<Square*>> ratPositions;
	vector<vector<Square*>> eyePositions;
	vector<vector<Square*>> chuPositions;
	vector<vector<Square*>> spectrumPositions;
	vector<vector<Square*>> spectrumFinalPosition;
	vector<vector<Square*>> playerPositions;
	void nextLevel();
	void levelsFiller();
	bool searchingPlayer(LinkedList* rangeArea);
	int cycles = 0;
	void moveRat();
	void objectsUpdate();
	vector<string> spectrumColors;
	vector<Objeto*> objectList;
	bool objectsFilled = false;
	string dataToSend;
	void eyesVision();
	void teleportSpect(int x, int y);
	void spectrumAttack();
	bool restartLvl = false;
	list<Square*> crumbs;
	void breadCrumbing(Spectrum* firsSpect);
	void fillCrumbs();
	int playerTempX;
	int playerTempY;
	int spectIndex;
	list<Square*> chuchuPath;
	void moveChuchu();
	void playerAttackSpect();
	void playerAttackChu();

	bool searchingRats(LinkedList* rangeArea);
};



