#include "EnemigoSimple.h"


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
		if (map[(randomX * orientation[randomBi]) + posX][(randomY * orientation[randomC]) + posY] != "0" || randomX * orientation[randomBi] == 0 || randomY * orientation[randomC] == 0 || (randomX * orientation[randomBi]) + posX >= 20 || (randomY * orientation[randomC]) + posY >= 20 || (randomX * orientation[randomBi]) + posX < 0 || (randomY * orientation[randomC]) + posY < 0) {
			//std::cout << "Can't Move" << std::endl;

		}
		else {
			cantMove = 1;
			//std::cout << randomX << std::endl;
			//std::cout << "Moving" << std::endl;
		}
	}
	tempY = randomY * orientation[randomC] + posY;
	//std::cout << posX << std::endl;
	tempX = randomX * orientation[randomBi] + posX;
	//std::cout << posY << std::endl;


}

void EnemigoSimple::setId(std::string id) {
	this->id = id;
}