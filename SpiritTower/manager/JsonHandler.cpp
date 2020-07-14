#include "JsonHandler.h"

bool JsonHandler::handlingReceivedData(std::string DataOne, Json::Value DataTwo, Json::Value DataThree) {

    std::cout << "INFO RECEIVED " << std::endl;

    std::cout << "This is the MAP-> " << DataOne << std::endl;

    int health = DataTwo["Health"].asInt();
    int score = DataTwo["Score"].asInt();
    bool shield = DataTwo["Shield"].asBool();
    bool sword = DataTwo["Sword"].asBool();

    std::cout << "This is the PLAYER STATUS -> " << DataTwo << std::endl;

    std::cout << "Can be used One by One :) "<< std::endl;
    std::cout << "This is the Health-> " << health << std::endl;
    std::cout << "This is the Score-> " << score << std::endl;
    std::cout << "This is the Shield-> " << shield << std::endl;
    std::cout << "This is the Sword-> " << sword << std::endl;

    std::cout << "These are the ENEMIES " << std::endl;
    std::cout << DataThree << std::endl;
    auto enemyA = DataThree["A"];
    auto enemyB = DataThree["B"];

    std::cout << "For Enemie A, his data " << std::endl;
    bool alert = enemyA["Alert"].asBool();
    int range = enemyA["Range"].asInt();
    std::cout << "Already saw the player?-> " << alert << std::endl;
    std::cout << "This is the Range-> " << range << std::endl;

    std::cout << "For Enemie B, his data " << std::endl;
    std::cout << enemyB << std::endl;
    return true;
}
bool JsonHandler::Deserialize(std::basic_string<char> streamOfJson) {
    Json::Value root;
    std::string errors;

    Json::CharReaderBuilder builder;    
    Json::CharReader* reader = builder.newCharReader();

    std::cout << streamOfJson << std::endl;

    bool parsingSuccessful = reader->parse(streamOfJson.c_str(), streamOfJson.c_str() + streamOfJson.size(), &root, &errors);
    delete reader;

    if (!parsingSuccessful) {
        std::cout << "DataNoParceable" << std::endl;
        return false;
    }else{
        for (Json::Value::const_iterator i = root.begin(); i != root.end(); i++) {
            std::string DataOne = root["Matrix"].asString();
            auto DataTwo = root["Player"];
            auto DataThree = root["Enemies"];
            if (handlingReceivedData(DataOne,DataTwo,DataThree)) {
                return true;
            }else{
                std::cout << "Something were wrong while handling the Data from Client" << std::endl;
                return false;
            }
        }
    }
    return false;
}

void JsonHandler::Serialize() {
}
