#include "PathFinding.h"

LinkedList PathFinding::searchPath(Square* start, Square* end){
	openList.push_back(start);
	Square* winner = new Square;
	bool finished = false;
	//mientras no hayamos encontrado el camino
	while (finished != true) {
		if (openList.size() > 0) {
			winner = openList.front();
			auto iter = openList.begin();
			auto lastn = openList.end();
			//analizamos que elementos de openlist tiene menor coste
			for (iter;iter!=lastn;++iter) {
				if ((*iter)->getGcost() < winner->getFcost()) {
					winner = *iter;
				}
			}
			//Si hemos llegado al ifnal buscamos el camino de vuelta
			if (winner == end) {
				//metemos el final encontrado en la lista del camino
				Square* tempFather = winner;
				pathList.addTop(tempFather);
				//vamos buscando los padres para obtener el camino desde el inicio
				while (tempFather->getFather() != nullptr){
					tempFather = tempFather->getFather();
					pathList.addTop(tempFather);
				}
				cout << "Camino Encontrado" << endl;
				finished = true;
			}

			//Si no hemos llegado al final, seguimos buscando
			else {
				openList.remove(winner);
				closedList.push_back(winner);
				auto it = winner->neighborsList.begin();
				auto last = winner->neighborsList.end();
				for (it; it != last;++it) {
					Square* neighbor = *it;
					//Si el vecino no esta en closedList y no es una pared
					if (includes(closedList,neighbor)==false && (neighbor->getEntity() != 1)) {
						int tempG = (winner->getGcost() + 1);
						//Si vecino esta en openList y su peso es mayor
						if (includes(openList,neighbor)==true) {
							if (tempG < (neighbor->getGcost())) {
								//encontre camino mas corto
								neighbor->setGcost(tempG);
							}
						}
						else {
							neighbor->setGcost(tempG);
							openList.push_back(neighbor);
						}
						//Actualizamos valores
						neighbor->setHcost(heuristic(neighbor, end));
						neighbor->setFcost(neighbor->getGcost() + neighbor->getHcost());

						//guardamos el padre de donde vinimos
						neighbor->setFather(winner);
					}
					
				}
			}
		}
		else {
			cout << "No hay camino posible" << endl;
			finished = true;
		}
	}
	return pathList;
}

int PathFinding::heuristic(Square* start, Square* end){
	int x = abs(start->getColNumb() - end->getColNumb());
	int y = abs(start->getRowNumb() - end->getRowNumb());
	int heuristic = x + y;
	return heuristic;
}

bool PathFinding::includes(list<Square*> list, Square* square){
	auto it = list.begin();
	auto last = list.end();
	for (it; it != last; ++it) {
		if (*it == square) {
			return true;
		}
	}
	return false;
}



