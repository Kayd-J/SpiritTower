#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "../LinkedList/LinkedList.h"

using namespace std;

class Spectrum {
private:
    int srch_speed;
    int chase_speed;
    int range;
    int extra;
    string id;
    int fitness;
    string idGen;


public:

    bool catchPlayer = false;

    bool walking = false;

    Spectrum();
    int getSrch_speed() const;

    void setSrch_speed(int srch_speed_);

    int getChase_speed() const;

    void setChase_speed(int chase_speed_);

    int getRange() const;

    void setRange(int range_);

    int getExtra() const;

    void setExtra(int extra_);

    string getId() const;

    void setId(string id_);

    int getFitness() const;

    void setFitness();

    string getIdGen() const;

    void setIdGen(string idgen_);

    int posX;
    int posY;

    int tempX;
    int tempY;

    LinkedList backTrackPath;

    LinkedList* patrollArea;

    string dir = "N";

    int movimientos = 0;

    string color;
};