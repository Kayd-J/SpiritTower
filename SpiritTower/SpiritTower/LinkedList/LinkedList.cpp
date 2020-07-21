#include "LinkedList.h"

void LinkedList::addNode(Square* square) {
	Node* temp = new Node;
	temp->setSquare(square);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->setNext(temp);
		temp->setPrev(tail);
		tail = tail->getNext();
	}
	size++;
}

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

int LinkedList::getSize() {
	return this->size;
}


Node* LinkedList::getHead() {
	return this->head;
}


void LinkedList::display() {
	Node* temp = this->head;
	while (temp != nullptr) {
		cout << temp->getSquare()->getRowNumb() << "--" << temp->getSquare()->getColNumb() << endl;
		temp = temp->getNext();
	}
}

void LinkedList::addTop(Square* square) {
	Node* temp = new Node;
	temp->setSquare(square);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		temp->setNext(this->head);
		this->head = temp;
	}
	size++;
}

void LinkedList::removeNode(Square* square) {
	Node* temp = new Node();
	temp = this->head;
	if (temp->getSquare() == square) {
		temp = temp->getNext();
		this->head = temp;
	}
	else {
		while (temp->getNext() != nullptr) {
			if (temp->getNext()->getSquare() == square) {
				if (temp->getNext() == this->tail) {
					temp->setNext(temp->getNext()->getNext());
					this->tail = temp;
					tail->setNext(temp->getNext());
					tail->setPrev(temp->getPrev());
					break;
				}
				else {
					temp->setNext(temp->getNext()->getNext());
					temp->getNext()->setPrev(temp);
					break;
				}
			}
			temp = temp->getNext();
		}
	}
	size--;
}

Node* LinkedList::getTail() {
	return this->tail;
}

bool LinkedList::isInList(Square* square) {
	Node* temp = this->head;
	while (temp != nullptr) {
		if (temp->getSquare() == square) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

Square* LinkedList::getRandomNode() {
	Node* temp = this->head;
	int i = 0;
	int index = rand() % size;
	if (size == 1) {
		return this->head->getSquare();
	}
	else {
		while (i != index) {
			temp = temp->getNext();
			i++;
		}
	}
	return temp->getSquare();

}