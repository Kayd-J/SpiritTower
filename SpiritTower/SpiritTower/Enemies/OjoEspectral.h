/**
  * @file OjoEspectral.h
  * @title OjoEspectral
  * @brief Enemigo simple que no se mueve y alerta espectros
  * @version 1.0
  * @author JoseSol
  * @date 20/07/2020
  */

#pragma once
#include "EnemigoSimple.h"

class OjoEspectral : public EnemigoSimple {
public:
	int visionRange;
	bool watched = false;
};
