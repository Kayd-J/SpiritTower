#include "BackTracking.h"

LinkedList BackTracking::searchPath(Matrix mat, Square* start, Square* end) {
    LinkedList* path = new LinkedList;
    LinkedList* visited = new LinkedList;
    mat.removeNeighbors();
    path->addNode(start);
    while (path->getSize() != 0) {
        if (start == end) {
            break;
        }
        if (start==nullptr) {
            break;
        }
        start = searchPath(start, path, visited);
    }
    if (start == end) {
        cout << "Camino Encontrado" << endl;
    }
    else {
        cout << "No Hay Posible Camino" << endl;
    }
    mat.addNeighbors();
    return *path;
}

 
Square* BackTracking::searchPath(Square* square,LinkedList* path, LinkedList* visited){
    if ((square->neighborsList.size() == 0)) {
        path->removeNode(square);
        square = nullptr;
    }
     else if (square->neighborsList.size() == 1) {
         if (path->isInList(square->neighborsList.front())==true || visited->isInList(square->neighborsList.front()) == true) {
             visited->addNode(square);
            path->removeNode(square);
            square = path->getTail()->getSquare();
        }
        else {
            Square* temp = square->neighborsList.front();
            square->neighborsList.clear();
            square = temp;
            path->addNode(square);
        }
     }
     else {
        auto it = square->neighborsList.begin();
        auto last = square->neighborsList.end();
        bool neighborFree = true;
        LinkedList vecinos;
        for (it; it != last;++it) {
            vecinos.addNode(*it);
        }
        /*
        for (it; it != last; ++it) {
            if (path->isInList((*it))==true || visited->isInList(*it)==true) {
                neighborFree = false;
            }
            else if(path->isInList((*it)) == false) {
                neighborFree = true;
                Square* temp = (*it);
                square->neighborsList.remove((*it));
                square = temp;
                path->addNode(square);
                break;
            }
        }
        */
        while(vecinos.getSize()>0) {
            Square* tempNeighbor = vecinos.getRandomNode();
            if (path->isInList(tempNeighbor) == true || visited->isInList(tempNeighbor) == true) {
                neighborFree = false;
            }
            else if (path->isInList(tempNeighbor) == false) {
                neighborFree = true;
                Square* temp = (tempNeighbor);
                square->neighborsList.remove(tempNeighbor);
                square = temp;
                path->addNode(square);
                break;
            }
            vecinos.removeNode(tempNeighbor);
        }
        if (neighborFree == false) {
            if (path->getSize() == 1) {
                path->removeNode(square);
                square = nullptr;
            }
            else {
                path->removeNode(square);
                visited->addNode(square);
                square = path->getTail()->getSquare();
            }
        }
       
    }
    return square;
}
