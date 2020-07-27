#pragma once
#include "EnemigoSimple.h"

class OjoEspectral : public EnemigoSimple {
public:
	int visionRange;
	bool watched = false;
};
