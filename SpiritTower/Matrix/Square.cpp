#include "Square.h"


Square::Square() {
	this->nextCol = nullptr;
	this->nextRow = nullptr;
	this->prevCol = nullptr;
	this->prevRow = nullptr;
	this->father = nullptr;
	this->entity = 0;
	this->fCost = 0;
	this->gCost = 0;
	this->hCost = 0;
}

int Square::getEntity(){
	return this->entity;
}

int Square::getRowNumb(){
	return this->rowNumb;
}

int Square::getColNumb(){
	return this->colNumb;
}

int Square::getGcost(){
	return this->gCost;
}

int Square::getFcost(){
	return this->fCost;
}

int Square::getHcost(){
	return this->hCost;
}

Square* Square::getNexRow(){
	return this->nextRow;
}

Square* Square::getprevRow(){
	return this->prevRow;
}

Square* Square::getNexCol(){
	return this->nextCol;
}

Square* Square::getPrevCol(){
	return this->prevCol;
}

Square* Square::getFather(){
	return this->father;
}

void Square::setEntity(int entity){
	this->entity = entity;
}

void Square::setRowNumb(int row){
	this->rowNumb = row;
}

void Square::setColNumb(int col){
	this->colNumb = col;
}

void Square::setGcost(int gCost){
	this->gCost = gCost;
}

void Square::setFcost(int fCost)
{
	this->fCost = fCost;
}

void Square::setHcost(int hCost){
	this->hCost = hCost;
}

void Square::setNexRow(Square* square)
{
	this->nextRow = square;
}

void Square::setprevRow(Square* Square){
	this->prevRow = Square;
}

void Square::setNexCol(Square* square){
	this->nextCol = square;
}

void Square::setPrevCol(Square* square){
	this->prevCol = square;
}

void Square::setFather(Square* square){
	this->father = square;
}
