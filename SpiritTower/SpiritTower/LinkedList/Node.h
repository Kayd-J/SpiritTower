/**
* @file Node.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title Node
* @brief Nodos de linkedlist
*/
#pragma once
#include <iostream>
#include "../Matrix/Square.h"

using namespace std;

class Node {
private:
	Square* square;
	Node* next;
	Node* prev;
public:

	/**
	* @brief getNext obtiene referencia a siguiente nodo
	* @return nodo referencia
	*/
	Node* getNext();

	/**
	* @brief getSquare obtiene data square del nodo
	* return Square referencia
	*/
	Square* getSquare();

	/**
	* @brief setNext asigna siguiente nodo
	* @param next referencia al siguiente nodo
	*/
	void setNext(Node* next);

	/**
	* @brief setSquare asigna siguiente square
	* @param square square que se asigna
	*/
	void setSquare(Square* square);

	/**
	* @brief Node costructor
	*/
	Node();

	/**
	* @brief getPrev obtiene nodo anterior
	* @return nodo referencia
	*/
	Node* getPrev();

	/**
	* @brief setPrev asigna nodo anterior
	* @param nodo referencia
	*/
	void setPrev(Node* prev);
};

