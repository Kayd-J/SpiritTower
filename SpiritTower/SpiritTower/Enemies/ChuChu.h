/**
  * @file ChuChu.h
  * @title ChuChu
  * @brief Enemigo simple que se mueve en linea vista
  * @version 1.0
  * @author JoseSol
  * @date 20/07/2020
  */

#pragma once
#include "EnemigoSimple.h"

class ChuChu : public EnemigoSimple {
public:
	int damage;
	int health;
};

