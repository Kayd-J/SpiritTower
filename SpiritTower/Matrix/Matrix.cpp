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
			temp->setEntity(0);
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
	fillMat();
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

void Matrix::resetMat(){
	Square* temp = this->head;
	Square* temp2 = this->head;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			temp->setFcost(0);
			temp->setHcost(0);
			temp->setGcost(0);
			temp->setFather(nullptr);
			temp = temp->getNexCol();
		}
		temp2 = temp2->getNexRow();
		temp = temp2;
	}
}


void Matrix::removeNeighbors(){
	Square* temp = this->head;
	Square* temp2 = this->head;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			auto it = temp->neighborsList.begin();
			auto last = temp->neighborsList.end();
			for (it; it != last; ++it) {
				if ((*it)->getEntity() == 1 || (*it)->getEntity() == 2 || (*it)->getEntity() == 4) {
					temp->neighborsList.remove(*it);
					it = temp->neighborsList.begin();
				}
			}
			temp = temp->getNexCol();
		}
		temp2 = temp2->getNexRow();
		temp = temp2;
	}
}

void Matrix::fillMat(){
	string entireString;
	int i = 0;
	string readingLine;
	ifstream readFile;
	readFile.open("Sources/matrix.txt");
	while (!readFile.eof()) {
		readFile >> readingLine;
		entireString = entireString + readingLine;
	}
	readFile.close();
	Square* temp = this->head;
	Square* temp2 = this->head;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			temp->setEntity((entireString.at(i) - '0'));
			temp = temp->getNexCol();
			i++;
		}
		temp2 = temp2->getNexRow();
		temp = temp2;
	}
}

Square* Matrix::findSquare(int row, int col){
	Square* temp = this->head;
	while (temp->getRowNumb()!=row) {
		while (temp->getColNumb() != col) {
			temp = temp->getNexCol();
		}
		temp = temp->getNexRow();
	}
	return temp;
}


void Matrix::addNeighbors() {
	Square* temp = this->head;
	Square* temp2 = this->head;
	while (temp2 != nullptr) {
		while (temp != nullptr) {
			temp->neighborsList.clear();
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