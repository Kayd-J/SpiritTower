/**
* @file BackTracking.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title BackTracking
* @brief Algoritmo  BackTracking
*/
#pragma once
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../Matrix/Matrix.h"

using namespace std;
class BackTracking {
public:

	/**
	* @brief searchPath busca camino por medio de backtracking
	* @param mat matriz a la cual se busca camino
	* @param start square inicio
	* @param end square final
	* @return linkedlist con camino
	*/
	LinkedList searchPath(Matrix mat, Square* start, Square* end);

	/**
	* @brief searchPath busca camino
	* @param square square el cual se evalua para ver si hay camino
	* @param path lista que guarda camino
	* @param visited lista que guarda los square visitados
	* return square nuevo
	*/
	Square* searchPath(Square*& square, LinkedList*& path, LinkedList*& visited);
};
