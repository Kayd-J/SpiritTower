#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Spectrum {
private:

    int srch_speed;
    int chase_speed;
    int range;
    int extra;
    string id;
    string idGen;
    int fitness;

public:

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

    string getIdGen() const;

    void setIdGen(string idgen_);

    int getFitness() const;

    void setFitness();
};

