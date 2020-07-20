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


using namespace std;

class GameManager{
private:
	static GameManager* instance;
	GameManager();
	
	
public:
	Player* player;
	list<Spectrum*> spectrumList;
	GameServer gameServer;
	bool chasingPlayer = true;
	bool walking = false;
	static GameManager* getInstance();
	Matrix matrixLevel;
	string map[20][20];
	string sendMap;
	void fillMap(Matrix mat);
	//Entidad enemigos
	//Entidad Jugador(singleton)
	void fillSpectrums();
	void displayMap();
	void chasing();
	thread starting;
	bool inGame = false;
	void mapUpdate();
	void returnBack();
	void patrolling();
	int level = 1;
	void fillLevelList();
	LinkedList* rangeAnalizer(Spectrum* spect);
	void analizeIm(LinkedList* &result, int impar, string dir,Spectrum* spect);
	void analizePa(LinkedList* &result, int pa, string dir, Spectrum* spect);
	breeder* breed;
};

