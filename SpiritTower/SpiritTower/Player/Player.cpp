#include "Player.h"

Player::Player()
{
}

int Player::getPosX()
{
    return posX;
}

int Player::getPosY()
{
    return posY;
}

string Player::getID()
{
    return ids;
}

int Player::getHealth()
{
    return health;
}

int Player::getScore()
{
    return score;
}

bool Player::getShield()
{
    return shield;
}

bool Player::getSword()
{
    return sword;
}

void Player::setPosX(int _posx)
{
    posX = _posx;
}

void Player::setPosY(int _posy)
{
    posY = _posy;
}

void Player::setID(string _id)
{
    ids = _id;
}

void Player::setHealth(int _health)
{
    health = _health;
}

void Player::setScore(int _score)
{
    score = _score;
}

void Player::setShield(bool _shield)
{
    shield = _shield;
}

void Player::setSword(bool _sword)
{
    sword = _sword;
}

