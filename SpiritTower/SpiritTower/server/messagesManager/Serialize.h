#pragma once
#include <string>
#include <iostream>
#include "json-c/json.h"
#include "../../Player/Player.h"
#include "../../Enemies/Spectrum.h"
#include "../../Enemies/RatonSimple.h"
#include "../../Enemies/ChuChu.h"
#include "../../Enemies/OjoEspectral.h"
#include "../../Objects/Objeto.h"

using namespace std;
class Serialize {
public:
	static string SerializeMatrix(std::string MatrixMap[20][20]);
	static string SerializeData(Player* player, vector<Spectrum*> ListaEspectros, vector<RatonSimple*> rats, vector<OjoEspectral*> spectEyes, vector<ChuChu*> chus, vector<Objeto*> ListaObjetos, Player* boss);
};
