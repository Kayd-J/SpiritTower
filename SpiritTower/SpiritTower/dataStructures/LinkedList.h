#pragma once
#include "Node.h"
class LinkedList{
private:
    Node *head, *tail;
    int size;
public:
    LinkedList();
    int getSize();
    void display();
    void addNode(std::string node);
};

