#include "LinkedList.h"

void LinkedList::addNode(Square* square){
	Node* temp = new Node;
	temp->setSquare(square);
	if (head== nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->setNext(temp);
		tail = tail->getNext();
	}
	size++;
}

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

int LinkedList::getSize(){
	return this->size;
}


Node* LinkedList::getHead(){
	return this->head;
}


void LinkedList::display(){
	Node* temp = this->head;
	while (temp != nullptr) {
		cout << temp->getSquare()->getRowNumb() << "--"<< temp->getSquare()->getColNumb()<<endl;
		temp = temp->getNext();
	}
}

void LinkedList::addTop(Square* square){
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








