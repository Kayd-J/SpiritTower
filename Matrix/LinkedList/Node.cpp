#include "Node.h"



Node::Node() {
    this->next = nullptr;
    this->square = nullptr;
}
Node* Node::getNext(){
    return this->next;
}

Square* Node::getSquare(){
    return this->square;
}

void Node::setNext(Node* next){
    this->next = next;
}

void Node::setSquare(Square* square){
    this->square = square;
}
