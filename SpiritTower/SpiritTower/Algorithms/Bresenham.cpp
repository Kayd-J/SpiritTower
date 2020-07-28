#include "Bresenham.h"


list<Square*> Bresenham::doBresenham(int x1, int y1, int x2, int y2) {
	list<Square*> temp;
	//Distancias que se desplazan en cada eje
	int movY = 0;
	int movX = 0;
	int deltaX = (x2 - x1);
	int deltaY = (y2 - y1);
	//Incrementos para las secciones con avance inclinado
	if (deltaY < 0) {
		deltaY = -deltaY;
		movY = -1;
	}
	else {
		movY = 1;
	}
	if (deltaX < 0) {
		deltaX = -deltaX;
		movX = -1;
	}
	else {
		movX = 1;
	}

	int x = x1;
	int y = y1;
	map[x][y] = 'I';

	if (deltaX > deltaY) {
		int p = 2 * deltaY - deltaX;
		int incE = 2 * deltaY;
		int incNE = 2 * (deltaY - deltaX);

		// Bucle para el trazado de las línea.
		while (x != x2) {
			std::cout << "first bucle x" << std::endl;
			x = x + movX;
			std::cout << x << std::endl;
			if (p < 0) {
				p = p + incE;
			}
			else {
				y = y + movY;
				p = p + incNE;
				std::cout << "first bucle y y p" << std::endl;
				std::cout << y << std::endl;
			}

			Square* bresen = new Square();
			bresen->setRowNumb(x);
			bresen->setColNumb(y);
			temp.push_back(bresen);
			//map[x][y] = '*';

		}
	}
	else {
		int p = 2 * deltaX - deltaY;
		int incE = 2 * deltaX;
		int incNE = 2 * (deltaX - deltaY);

		while (y != y2) {
			y = y + movY;
			std::cout << "second bucle y" << std::endl;
			std::cout << y << std::endl;
			if (p < 0) {
				p = p + incE;

			}
			else {

				x = x + movX;
				p = p + incNE;
				std::cout << "second bucle x y p" << std::endl;
				std::cout << x << std::endl;
			}
			Square* bresen = new Square();
			bresen->setRowNumb(x);
			bresen->setColNumb(y);
			temp.push_back(bresen);
			//map[x][y] = '*';
		}
	}
	return temp;
}
void Bresenham::print() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}
