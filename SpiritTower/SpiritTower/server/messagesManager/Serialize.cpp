#include "Serialize.h"



string Serialize::SerializeMatrix(std::string MatrixMap[20][20]) {
	json_object* jobj = json_object_new_object();
	json_object* jarray1 = json_object_new_array();

	for (int x = 0; x < 20; x++) {
		json_object* jarray2 = json_object_new_array();
		for (int y = 0; y < 20; y++) {
			const char* str1 = MatrixMap[x][y].c_str();
			json_object* jsonString = json_object_new_string(str1);
			json_object_array_add(jarray2, jsonString);
		}
		json_object_array_add(jarray1, jarray2);
	}
	//printf("The json object created: %s", json_object_to_json_string(jarray1));
	json_object_object_add(jobj, "Matrix", jarray1);
	string serialized = json_object_to_json_string(jobj);
	return serialized;
}

string Serialize::SerializeData(Player* player, vector<Spectrum*> ListaEspectros, vector<RatonSimple*> rats, vector<OjoEspectral*> spectEyes, vector<ChuChu*> chus, vector<Objeto*> ListaObjetos, Player* boss)
{
	json_object* jobj = json_object_new_object();
	//-------------------------------------Player------------------------------------------------
	json_object* playerStats = json_object_new_object();

	json_object* health = json_object_new_int(player->getHealth());
	json_object* score = json_object_new_int(player->getScore());
	json_object* shield = json_object_new_boolean(player->getShield());
	json_object* sword = json_object_new_boolean(player->getScore());
	json_object* posX = json_object_new_boolean(player->getPosX());
	json_object* posY = json_object_new_boolean(player->getPosY());

	json_object_object_add(playerStats, "Health", health);
	json_object_object_add(playerStats, "Score", score);
	json_object_object_add(playerStats, "Shield", shield);
	json_object_object_add(playerStats, "Sword", sword);
	json_object_object_add(playerStats, "posX", shield);
	json_object_object_add(playerStats, "posY", sword);

	//-------------------------------------Enemie------------------------------------------------------

	json_object* enemieStats = json_object_new_array();

	for (int i = 0; i < ListaEspectros.size(); i++) {
		json_object* spectros = json_object_new_object();

		json_object* IDspectros = json_object_new_string(ListaEspectros.at(i)->getId().c_str());
		json_object* COLORspectros = json_object_new_string(ListaEspectros.at(i)->color.c_str());
		json_object* DEATHspectros = json_object_new_boolean(ListaEspectros.at(i)->death);
		json_object* POSXspectros = json_object_new_int(ListaEspectros.at(i)->tempY);
		json_object* POSYspectros = json_object_new_int(ListaEspectros.at(i)->tempX);

		json_object_object_add(spectros, "ID", IDspectros);
		json_object_object_add(spectros, "COLOR", COLORspectros);
		json_object_object_add(spectros, "DEATH ", DEATHspectros);
		json_object_object_add(spectros, "posX", POSXspectros);
		json_object_object_add(spectros, "posY", POSYspectros);

		json_object_array_add(enemieStats, spectros);
	}
	for (int i = 0; i < rats.size(); i++) {
		json_object* enemie = json_object_new_object();
		json_object* IDEnemigo = json_object_new_string(rats.at(i)->getId().c_str());
		json_object* COLOREnemigo = json_object_new_string(rats.at(i)->color.c_str());
		json_object* DEATHEnemigo = json_object_new_boolean(rats.at(i)->death);
		json_object* POSXEnemigo = json_object_new_int(rats.at(i)->posY);
		json_object* POSYEnemigo = json_object_new_int(rats.at(i)->posX);

		json_object_object_add(enemie, "ID", IDEnemigo);
		json_object_object_add(enemie, "COLOR", COLOREnemigo);
		json_object_object_add(enemie, "DEATH ", DEATHEnemigo);
		json_object_object_add(enemie, "posX", POSXEnemigo);
		json_object_object_add(enemie, "posY", POSYEnemigo);

		json_object_array_add(enemieStats, enemie);
	}
	for (int i = 0; i < chus.size(); i++) {
		json_object* enemie = json_object_new_object();

		json_object* IDEnemigo = json_object_new_string(chus.at(i)->getId().c_str());
		json_object* COLOREnemigo = json_object_new_string(chus.at(i)->color.c_str());
		json_object* DEATHEnemigo = json_object_new_boolean(chus.at(i)->death);
		json_object* POSXEnemigo = json_object_new_int(chus.at(i)->posY);
		json_object* POSYEnemigo = json_object_new_int(chus.at(i)->posX);

		json_object_object_add(enemie, "ID", IDEnemigo);
		json_object_object_add(enemie, "COLOR", COLOREnemigo);
		json_object_object_add(enemie, "DEATH ", DEATHEnemigo);
		json_object_object_add(enemie, "posX", POSXEnemigo);
		json_object_object_add(enemie, "posY", POSYEnemigo);

		json_object_array_add(enemieStats, enemie);
	}
	for (int i = 0; i < spectEyes.size(); i++) {
		json_object* enemie = json_object_new_object();

		json_object* IDEnemigo = json_object_new_string(spectEyes.at(i)->getId().c_str());
		json_object* COLOREnemigo = json_object_new_string(spectEyes.at(i)->color.c_str());
		json_object* DEATHEnemigo = json_object_new_boolean(spectEyes.at(i)->death);
		json_object* POSXEnemigo = json_object_new_int(spectEyes.at(i)->posY);
		json_object* POSYEnemigo = json_object_new_int(spectEyes.at(i)->posX);

		json_object_object_add(enemie, "ID", IDEnemigo);
		json_object_object_add(enemie, "COLOR", COLOREnemigo);
		json_object_object_add(enemie, "DEATH ", DEATHEnemigo);
		json_object_object_add(enemie, "posX", POSXEnemigo);
		json_object_object_add(enemie, "posY", POSYEnemigo);

		json_object_array_add(enemieStats, enemie);
	}
	//-------------------------------------Objects------------------------------------------------------
	json_object* objectStats = json_object_new_array();

	for (int i = 0; i < ListaObjetos.size(); i++) {

		json_object* object = json_object_new_object();

		json_object* IDObject = json_object_new_string(ListaObjetos.at(i)->id.c_str());
		json_object* DEATHObject = json_object_new_boolean(ListaObjetos.at(i)->death);
		json_object* POSXObject = json_object_new_int(ListaObjetos.at(i)->posY);
		json_object* POSYObject = json_object_new_int(ListaObjetos.at(i)->posX);


		json_object_object_add(object, "ID", IDObject);
		json_object_object_add(object, "DEATH ", DEATHObject);
		json_object_object_add(object, "posX", POSXObject);
		json_object_object_add(object, "posY", POSYObject);


		json_object_array_add(objectStats, object);
	}
	//-------------------------------------Boss------------------------------------------------
	json_object* bossStats = json_object_new_object();

	json_object* healthboss = json_object_new_int(boss->getHealth());
	json_object* scoreboss = json_object_new_int(boss->getScore());
	json_object* shieldboss = json_object_new_boolean(boss->getShield());
	json_object* swordboss = json_object_new_boolean(boss->getScore());
	json_object* posXboss = json_object_new_boolean(boss->getPosX());
	json_object* posYboss = json_object_new_boolean(boss->getPosY());

	json_object_object_add(bossStats, "Health", healthboss);
	json_object_object_add(bossStats, "Score", scoreboss);
	json_object_object_add(bossStats, "Shield", shieldboss);
	json_object_object_add(bossStats, "Sword", swordboss);
	json_object_object_add(bossStats, "posX", shieldboss);
	json_object_object_add(bossStats, "posY", swordboss);

	//-------------------------------------LastUnified------------------------------------------------
	json_object_object_add(jobj, "Player", playerStats);
	json_object_object_add(jobj, "Enemies", enemieStats);
	json_object_object_add(jobj, "Objects", objectStats);
	json_object_object_add(jobj, "Boss", bossStats);

	string serialized = json_object_to_json_string(jobj);
	//std::cout << serialized << std::endl;
	return serialized;
}