#pragma once
#include<cstdlib>
#include <iostream>
#include <string>
class Node{
private:
    std::string data;
    Node *next;
public:
    std::string getData();
    Node* getNext();
    void setData(std::string newData);
    void setNext(Node *next);
};

