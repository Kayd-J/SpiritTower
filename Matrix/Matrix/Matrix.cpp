#include "Matrix.h"

Matrix::Matrix() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}


void Matrix::createMatrix(int rows, int cols) {
	srand(time(NULL));
	this->cols = cols;
	this->rows = rows;
	Square* temp2 = new Square();
	int i = 0;
	int j = 0;
	while(i < rows){
		if (j < cols) {
			Square* temp = new Square;
			temp->setColNumb(j);
			temp->setRowNumb(i);
			temp->setEntity(getRandomValue());
			if (this->head == nullptr) {
				this->head = temp;
				temp2 = this->head;
			}
			else {
				if (i == 0) {
					temp2->setNexCol(temp);
					temp->setPrevCol(temp2);
					temp2 = temp;
				}
				else {
					Square* temp3 = this->head;
					if (j == 0) {
						while (temp2->getNexRow() != nullptr) {
							temp2 = temp2->getNexRow();
						}
						temp2->setNexRow(temp);
						temp->setprevRow(temp2);
						temp2 = temp;
					}
					else {
						while (temp3->getColNumb() != temp->getColNumb()) {
							while (temp3->getRowNumb() != (temp->getRowNumb() - 1)) {
								temp3 = temp3->getNexRow();
							}
							temp3 = temp3->getNexCol();
						}
						temp2->setNexCol(temp);
						temp->setPrevCol(temp2);
						temp->setprevRow(temp3);
						temp3->setNexRow(temp);
						temp2 = temp;
					}
				}
			}
			j++;
		}
		else {
			j = 0;
			i++;
			temp2 = this->head;
		}
	}
	while (temp2->getNexRow() != nullptr) {
		while (temp2->getNexCol() != nullptr) {
			temp2 = temp2->getNexCol();
		}
		temp2 = temp2->getNexRow();
	}
	this->tail = temp2;
	addNeighbors();
}


void Matrix::display() {
	Square* temp = this->head;
	Square* temp2 = this->head;
	while (temp2 != nullptr) {
		while (temp!= nullptr) {
			cout << temp->getEntity()<<" ";
			temp = temp->getNexCol();
		}
		temp2 = temp2->getNexRow();
		temp = temp2;
		cout << endl;
	}
}

int Matrix::getSize() {
	return this->size;
}

Square* Matrix::getHead() {
	return this->head;
}

Square* Matrix::getTail(){
	return this->tail;
}

int Matrix::getRandomValue(){
	int value;
	value = rand() % 4;
	if (value != 1) {
		value = 0;
	}
	return value;
}


void Matrix::addNeighbors() {
	Square* temp = this->head;
	Square* temp2 = this->head;
	int cont = 0;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			if (temp->getColNumb() > 0) {
				temp->neighborsList.push_back(temp->getPrevCol());
			}
			if (temp->getColNumb() < (this->cols-1)) {
				temp->neighborsList.push_back(temp->getNexCol());
			}
			if (temp->getRowNumb() > 0) {
				temp->neighborsList.push_back(temp->getprevRow());
			}
			if (temp->getRowNumb() < (this->rows-1)) {
				temp->neighborsList.push_back(temp->getNexRow());
			}
			temp = temp->getNexCol();
		}
		temp2 = temp2->getNexRow();
		temp = temp2;
	}
}

