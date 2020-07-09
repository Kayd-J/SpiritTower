#pragma once
#include <vector>
#include <stdlib.h>

using namespace std;

class Spectrum {
private:

    int srch_speed;
    int chase_speed;
    int range;
    int extra;

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
};

