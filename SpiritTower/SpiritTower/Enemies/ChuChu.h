#pragma once
#include "EnemigoSimple.h"

class ChuChu : public EnemigoSimple {
public:
	int damage;
	void move();
	int health;
};

