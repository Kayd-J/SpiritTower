#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "../Matrix/Square.h"

class EnemigoSimple
{
public:
	EnemigoSimple();
	int posX;
	int posY;
	bool death;
	std::string color;
	std::string dir;
	virtual std::string getId();
	virtual void randomMove(std::string map[20][20]);
	virtual void setId(std::string id);
	int tempX;
	int tempY;
	bool moving = false;
private:
	std::string id;

};
