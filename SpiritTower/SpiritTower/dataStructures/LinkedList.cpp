#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
int LinkedList::getSize() {
    return this->size;
}
void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}
void LinkedList::addNode(std::string n) {
    auto *temp = new Node;
    temp->setData(n);
    temp->setNext(nullptr);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->setNext(temp);
        tail = tail->getNext();
    }
    size++;
}
