#include "Node.h"
std::string Node::getData() {
	return this->data;
}
Node* Node::getNext() {
	return this->next;
}
void Node::setData(std::string newData) {
	this->data = newData;
}
void Node::setNext(Node *next) {
	this->next = next;
}