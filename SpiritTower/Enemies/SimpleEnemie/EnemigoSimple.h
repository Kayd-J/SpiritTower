#pragma once
#include <string>
#include <ctime>
class EnemigoSimple
{
public:
	EnemigoSimple();
	int posX=4;
	int posY=4;
	bool DEATH;
	std::string dir;
	std::string getId();
	void randomMove(std::string map[20][20]);
private:
	std::string id;
};

