/**
* @file Square.h
* @version 1.0
* @date 28/06/2020
* @author MarioGR
* @title Square
* @brief Nodos de la matriz del Juego
*/
#pragma once
#include <list>
using namespace std;
class Square {
private:
	Square* nextRow, * prevRow;
	Square* nextCol, * prevCol;
	int entity;
	int rowNumb, colNumb;
	int gCost;
	int hCost;
	int fCost;
	Square* father;

public:
	/**
	* @brief Constructor de la clase Square
	*/
	Square();

	/**
	* @brief getEntity Obtiene valor entidad
	* @return int que indica entidad
	*/
	int getEntity();

	/**
	* @brief getRowNumb Obtiene int de fila
	* @return int que indica fila
	*/
	int getRowNumb();

	/**
	* @brief getColNumb Obtiene int de columna
	* @return int que indica columna
	*/
	int getColNumb();

	/**
	* @brief getGcost Obtiene valor G de un square
	* @return int que indica valor G
	*/
	int getGcost();

	/**
	* @brief getFcost Obtiene valor F de un square
	* @return int que indica valor F
	*/
	int getFcost();

	/**
	* @brief getHcost Obtiene valor H de un square
	* @return int que indica valor H
	*/
	int getHcost();

	/**
	* @brief getNexRow obtiene siguiente fila
	* @return Square con referencia a siguiente fila
	*/
	Square* getNexRow();

	/**
	* @brief getpreRow obtiene anterior fila
	* @return Square con referencia a siguiente fila
	*/
	Square* getprevRow();

	/**
	* @brief getNexCol obtiene siguiente columna
	* @return Square con referencia a anterior columna
	*/
	Square* getNexCol();

	/**
	* @brief getPrevCol obtiene anterior columna
	* @return Square con referencia a siguiente columna
	*/
	Square* getPrevCol();

	/**
	* @brief getFather obtiene square padre
	* @return square con ferencia al padre
	*/
	Square* getFather();


	/**
	* @brief setEntity asigna valor entidad
	* @param entity int entidad
	*/
	void setEntity(int entity);

	/**
	* @brief setRowNumb asigna valor fila
	* @param row int fila
	*/
	void setRowNumb(int row);

	/**
	* @brief setColNumb asigna valor columna
	* @param col int columna
	*/
	void setColNumb(int col);

	/**
	* @brief setGcost asigna valor G
	* @param gCost int valor g
	*/
	void setGcost(int gCost);

	/**
	* @brief setFcost asigna valor F
	* @param fCost int valor F
	*/
	void setFcost(int fCost);

	/**
	* @brief seHGcost asigna valor H
	* @param hCost int valor H
	*/
	void setHcost(int hCost);

	/**
	* @brief setNexRow asigna referencia a fila siguiente
	* @param square Square referencia
	*/
	void setNexRow(Square* square);

	/**
	* @brief setprevRow asigna referencia a fila anterior
	* @param square Square referencia
	*/
	void setprevRow(Square* square);

	/**
	* @brief setNexCol asigna referencia a columna siguiente
	* @param square Square referencia
	*/
	void setNexCol(Square* square);

	/**
	* @brief setPrevCol asigna referencia a fila anterior
	* @param square Square referencia
	*/
	void setPrevCol(Square* square);

	/**
	* @brief setFather asigna referencia a square padre
	* @param square Square referencia
	*/
	void setFather(Square* square);

	list<Square*> neighborsList;
};

