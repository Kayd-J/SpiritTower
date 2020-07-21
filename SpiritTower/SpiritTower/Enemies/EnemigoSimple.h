#pragma once
#include <string>
#include <ctime>

class EnemigoSimple
{
public:
	EnemigoSimple();
	int posX = 4;
	int posY = 4;
	bool DEATH;
	std::string dir;
	virtual std::string getId();
	virtual void randomMove(std::string map[20][20]);
	virtual void setId(std::string id);
private:
	std::string id;
};

