#pragma once
#include <list>
using namespace std;
class Square{
private:
	Square *nextRow, *prevRow;
	Square *nextCol,  *prevCol;
	int entity;
	int rowNumb, colNumb;
	int gCost;
	int hCost;
	int fCost;
	Square* father;
	
public:
	Square();
	int getEntity();
	int getRowNumb();
	int getColNumb();
	int getGcost();
	int getFcost();
	int getHcost();
	Square* getNexRow();
	Square* getprevRow();
	Square* getNexCol();
	Square* getPrevCol();
	Square* getFather();

	void setEntity(int entity);
	void setRowNumb(int row);
	void setColNumb(int col);
	void setGcost(int gCost);
	void setFcost(int fCost);
	void setHcost(int hCost);
	void setNexRow(Square* square);
	void setprevRow(Square* square);
	void setNexCol(Square* square);
	void setPrevCol(Square* square);
	void setFather(Square* square);
	list<Square*> neighborsList;
};

