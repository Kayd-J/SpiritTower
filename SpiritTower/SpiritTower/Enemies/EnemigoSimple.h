/**
  * @file EnemigoSimple.h
  * @title EnemigoSimple
  * @brief Enemigo base para el resto
  * @version 1.0
  * @author JoseSol
  * @date 20/07/2020
  */

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

	/**
	 * @brief Obtiene el identificador del enemigo
	 * @return Identificador del enemigo
	 */
	virtual std::string getId();

	/**
	 * @brief Busca una posición aleatoria a la cuál moverse en un rango de 3 casillas
	 * @param mapa en forma de array de arrays de strings
	 */
	virtual void randomMove(std::string map[20][20]);

	/**
	 * @brief Asigna el iedentificador del enemigo
	 * @param Identificador del enemigo
	 */
	virtual void setId(std::string id);
	int tempX;
	int tempY;
	bool moving = false;
private:
	std::string id;

};
