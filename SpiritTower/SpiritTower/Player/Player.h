#pragma once
#include <iostream>
using namespace std;
class Player {
public:
    Player();
    int getPosX();
    int getPosY();
    string getIP();
    int getHealth();
    int getScore();
    bool getShield();
    bool getSword();
    int posX = 18;
    int posY = 3;
    string ids = "P";
    int health = 1;
    int score = 100;
    bool shield = false;
    bool sword = true;
};
