/**
* @file Bresenham.h
* @class Bresenham.
* @brief permite dibujar lineas mediante el rastreo
*/

#pragma once
#include <iostream>
#include "../Matrix/Square.h"


class Bresenham
{
public:
	int size = 20;
	string map[20][20];

	/**
	* @param  x1, y1, x2, y2
	* @brief se le indica en los primeros parametros su inicio y en los segundos parametros, donde debe terminar
	* @return list<Square*>
	*/
	list<Square*> doBresenham(int x1, int y1, int x2, int y2);

	/**
	* @brief imprime todo el camino a seguir con el algoritmo
	*/
	void print();
};

