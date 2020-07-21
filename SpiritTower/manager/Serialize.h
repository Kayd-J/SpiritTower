#pragma once
#include <string>
#include <iostream>
#include "json-c/json.h"
#include "../../Player/Player.h"
#include "../../Enemies/Spectrum.h"
#include "../../Enemies/EnemigoSimple.h"
#include "../../Objeto.h"

using namespace std;
class Serialize {
public:
	static string SerializeMatrix(std::string MatrixMap[20][20]);
	static string SerializeData(Player player, vector<Spectrum> ListaEspectros, vector<EnemigoSimple> ListaEnemigos, vector<Objeto> ListaObjetos, Player boss);
};

