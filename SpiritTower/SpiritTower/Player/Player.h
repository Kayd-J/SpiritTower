#pragma once
#include <iostream>
using namespace std;
class Player {
public:
    Player();
    int getPosX();
    int getPosY();
    string getID();
    int getHealth();
    int getScore();
    bool getShield();
    bool getSword();

    void setPosX(int _posx);
    void setPosY(int _posy);
    void setID(string _id);
    void setHealth(int _health);
    void setScore(int _score);
    void setShield(bool _shield);
    void setSword(bool _sword);

private:
    int posX = 10;
    int posY = 1;
    string ids = "P";
    int health = 5;
    int score = 0;
    bool shield = true;
    bool sword = false;
};
