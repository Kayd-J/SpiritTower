/**
* @file Serialize.h
* @class Serialize.
* @brief Da formato json a la informacion que se va enviar al cliente
*/

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

    /**
    *@param  MatrixMap[20][20]
    * @brief lleva la matriz a un formato json
    * @return un string con formato json para enviar
    */
	static string SerializeMatrix(std::string MatrixMap[20][20]);

    /**
    * @param  player, ListaEspectros, rats, spectEyes, chus, ListaObjectos, boss
    * @brief al pasarle los objetos que se van a enviar se mensaje al cliente, se les da formato json
    * @return un string con formato json para enviar
    */
	static string SerializeData(Player* player, vector<Spectrum*> ListaEspectros, vector<RatonSimple*> rats, vector<OjoEspectral*> spectEyes, vector<ChuChu*> chus, vector<Objeto*> ListaObjetos, Player* boss);
};
