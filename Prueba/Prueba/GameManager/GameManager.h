#pragma once
#include "../Matrix/Matrix.h"
#include "../Player/Player.h"
#include "../Enemies/Spectrum.h"
#include <thread>
#include <chrono>
#include <string>
#include "../Algorithms/PathFinding.h"
#include "../Algorithms/BackTracking.h"


using namespace std;

class GameManager{
private:
	static GameManager* instance;
	GameManager();
	Player player;
	list<Spectrum*> spectrumList;
	

public:
	bool chasingPlayer = true;
	bool walking = false;
	static GameManager* getInstance();
	Matrix matrixLevel;
	string map[20][20];

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
};

