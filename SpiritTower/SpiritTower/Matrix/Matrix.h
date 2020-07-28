/**
* @file Matrix.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title Matriz
* @brief Matriz Del Juego
*/
#pragma once
#include <iostream>
#include "Square.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include<string>

using namespace std;
class Matrix {
private:
	Square* head;
	Square* tail;
	int size;
	int rows;
	int cols;
public:

	/**
	* @brief createMatrix Crea matriz logica
	* @param rows cantidad de filas
	* @param cols cantidad de columnas
	*/
	void createMatrix(int rows, int cols);

	/**
	* @brief Matrix constructor de la clase Matrix
	*/
	Matrix();

	/**
	* @brief display Print que muestra la matriz completa
	*/
	void display();

	/**
	* @brief getSize Muestra tamano de la matriz
	* @return int Tamano de matriz
	*/
	int getSize();

	/**
	* @brief addNeighbors agrega nodos vecinos
	*/
	void addNeighbors();

	/**
	* @brief getHead Obtiene principio de la matriz
	* @return nodo head de la matriz
	*/
	Square* getHead();

	/**
	* @brief getTail Obtiene principio de la matriz
	* @return nodo tail de la matriz
	*/
	Square* getTail();

	/**
	* @brief getRandomValue obtiene genera un int random
	* @return int con valor random
	*/
	int getRandomValue();

	/**
	* @brief resetMat resetea valores iniciales de la matriz
	*/
	void resetMat();

	/**
	* @brief removeNeighbors elimina vecinos nodos de la matriz
	*/
	void removeNeighbors();

	/**
	* @brief fillMat Llena matriz con datos especificos mediante un archivo
	* @param file id int del archivo que se lee
	*/
	void fillMat(int file);

	/**
	* @brief findSquare encuenta un nodo en la matriz
	* @param row int filas
	* @param col int columnas
	* @return nodo de la matriz en fila y colunma especifica
	*/
	Square* findSquare(int row, int col);
};
