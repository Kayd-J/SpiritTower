#include "JsonHandler.h"

bool JsonHandler::handlingReceivedData(Json::Value DataOne, Json::Value DataTwo, Json::Value DataThree, Json::Value DataFour, Player*& player, vector<Objeto*> &objetos) {

    //std::cout << "INFO RECEIVED " << std::endl;
    int health = DataOne["Health"].asInt();
    int score = DataOne["Score"].asInt();
    bool shield = DataOne["Shield"].asBool();
    bool sword = DataOne["Sword"].asBool();
    int posX = DataOne["posX"].asInt();
    int posY = DataOne["posY"].asInt();
    string dir = DataOne["Direction"].asCString();

    //------------------------------Enemies-------------------------------------------------------------
    /*
    for (int i = 0; i < DataTwo.size(); ++i) {
        std::cout << DataTwo[i]["COLOR"] << std::endl;
        std::string colorEnemie = DataTwo[i]["COLOR"].asString();
        bool deathEnemie = DataTwo[i]["DEATH"].asBool();
        std::string idEnemie = DataTwo[i]["ID"].asString();
        int posXEnemie = DataTwo[i]["posX"].asInt();
        int posYEnemie = DataTwo[i]["posY"].asInt();
        
        
        std::cout << "This is the Enemie Color-> " << colorEnemie << std::endl;
        std::cout << "This is the Enemie Score Death-> " << deathEnemie << std::endl;
        std::cout << "This is the Enemie ID-> " << idEnemie << std::endl;
        std::cout << "This his Enemie PosX-> " << posXEnemie << std::endl;
        std::cout << "This his Enemie PosY-> " << posYEnemie << std::endl;
        
    }
    */
    
    //------------------------------Objects-------------------------------------------------------------
    for (int i = 0; i < DataThree.size(); ++i) {
        //std::cout << DataThree[i]["COLOR"] << std::endl;
        bool deathObject = DataThree[i]["DEATH"].asBool();
        std::string idObject = DataThree[i]["ID"].asString();
        int posYObject = DataThree[i]["posX"].asInt();
        int posXObject = DataThree[i]["posY"].asInt();

        /*
        std::cout << "This is the Object Score Death-> " << deathObject << std::endl;
        std::cout << "This is the Object ID-> " << idObject << std::endl;
        std::cout << "This his Object PosX-> " << posXObject << std::endl;
        std::cout << "This his Object PosY-> " << posYObject << std::endl;
        */

        for (int j = 0; j < objetos.size(); j++) {
            if ((objetos.at(j)->posX == posXObject) && (objetos.at(j)->posY == posYObject)) {
                if (deathObject && !objetos.at(i)->given) {
                    objetos.at(i)->death = 1;
                    cout << "\n\nSE ASIGNAN PUNTOS\n\n" << endl;
                }
            }
        }
        
    }
    /*
    //------------------------------Boss-------------------------------------------------------------
    int healthBoss = DataFour["Health"].asInt();
    int scoreBoss = DataFour["Score"].asInt();
    bool shieldBoss = DataFour["Shield"].asBool();
    bool swordBoss = DataFour["Sword"].asBool();
    int posXBoss = DataFour["posX"].asInt();
    int posYBoss = DataFour["posY"].asInt();

    std::cout << "This is the BOSS STATUS -> " << std::endl;

    
    std::cout << "This is the Boss Health-> " << healthBoss << std::endl;
    std::cout << "This is the Boss Score-> " << scoreBoss << std::endl;
    std::cout << "This is the Boss Shield-> " << shieldBoss << std::endl;
    std::cout << "This is the Boss Sword-> " << swordBoss << std::endl;
    std::cout << "This his Boss PosX-> " << posXBoss << std::endl;
    std::cout << "This his Boss PosY-> " << posYBoss << std::endl;
    
    */
    //system("pause");
    
    
    player->setPosX(posY);
    player->setPosY(posX);
    //player->setHealth(health);
    //player->setScore(score);
    player->setShield(shield);
    player->setSword(sword);
    player->dir = dir;

    return true;
}
bool JsonHandler::Deserialize(std::basic_string<char> streamOfJson, Player*& player, vector<Objeto*> &objetos) {
    Json::Value root;
    std::string errors;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();

    bool parsingSuccessful = reader->parse(streamOfJson.c_str(), streamOfJson.c_str() + streamOfJson.size(), &root, &errors);
    delete reader;
    if (!parsingSuccessful) {
        std::cout << "DataNoParceable" << std::endl;
        return false;
    }
    else {
        for (Json::Value::const_iterator i = root.begin(); i != root.end(); i++) {
            auto DataOne = root["Player"];
            auto DataTwo = root["Enemies"];
            auto DataThree = root["Objects"];
            auto DataFour = root["Boss"];
            if (handlingReceivedData(DataOne, DataTwo, DataThree, DataFour, player, objetos)) {
                return true;
            }
            else {
                std::cout << "Something were wrong while handling the Data from Client" << std::endl;
                return false;
            }
        }
    }
    return false;
}