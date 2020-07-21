#include "EnemigoSimple.h"
#include <iostream>

EnemigoSimple::EnemigoSimple()
{
	//srand(time(NULL));
}

std::string EnemigoSimple::getId() {
	return id;
}
void EnemigoSimple::randomMove(std::string map[20][20]) {
	int randomX;
	int randomY;
	int orientation[2] = { -1,1 };
	int randomBi;
	int randomC;
	bool cantMove = 0;

	while (!cantMove) {
		randomX = 1 + rand() % 4;
		randomY = 1 + rand() % 4;
		randomBi = rand() % 2;
		randomC = rand() % 2;
		if (map[(randomX * orientation[randomBi]) + posX][(randomY * orientation[randomC]) + posY] != "0") {
			std::cout << "Can't Move" << std::endl;
		}
		else {
			cantMove = 1;
			std::cout << randomX << std::endl;
			std::cout << "Moving" << std::endl;
		}
	}

	posX = randomX * orientation[randomBi];
	std::cout << posX << std::endl;
	posY = randomY * orientation[randomC];
	std::cout << posY << std::endl;

}

void EnemigoSimple::setId(std::string id) {
	this->id = id;
}
