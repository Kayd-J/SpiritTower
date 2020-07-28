/**
* @file PathFinding.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title PathFinding
* @brief Algoritmo A* Pathfinding
*/
#pragma once
#include "../LinkedList/LinkedList.h"
#include <iostream>
#include <list>
#include"../Matrix/Matrix.h"

using namespace std;
class PathFinding {
public:
	/**
	* @brief searchPath busca camino mediante pathfindin y guarda ese camino en una lista
	* @param mat matriz a la cual se busca camino
	* @param start square de inicio
	* @param end square final
	* @return lista enlazada con camino
	*/
	LinkedList searchPath(Matrix mat, Square* start, Square* end);

	/**
	* @brief heuristic obtiene valor heuristico entre dos square
	* @param start square inicio
	* @param end square final
	* @return int con valor del heuristico
	*/
	int heuristic(Square* start, Square* end);

	/**
	* @brief includes indica si existe un square dentro de una lista de square
	* @param list lista de square
	* @param square square que se desea buscar
	* @return booleano que indica si se encontro o no el square en la lista
	*/
	bool includes(list<Square*> list, Square* square);
};