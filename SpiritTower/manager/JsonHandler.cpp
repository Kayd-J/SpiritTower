    #include "JsonHandler.h"

bool JsonHandler::handlingReceivedData(Json::Value DataOne, Json::Value DataTwo) {

    std::cout << "INFO RECEIVED " << std::endl;
    int health = DataOne["Health"].asInt();
    int score = DataOne["Score"].asInt();
    bool shield = DataOne["Shield"].asBool();
    bool sword = DataOne["Sword"].asBool();
    int posX = DataOne["posX"].asInt();
    int posY = DataOne["posY"].asInt();

    std::cout << "This is the PLAYER STATUS -> " << std::endl;
    std::cout << "Can be used One by One :) " << std::endl;
    std::cout << "This is the Health-> " << health << std::endl;
    std::cout << "This is the Score-> " << score << std::endl;
    std::cout << "This is the Shield-> " << shield << std::endl;
    std::cout << "This is the Sword-> " << sword << std::endl;
    std::cout << "This his PosX-> " << posX << std::endl;
    std::cout << "This his PosY-> " << posY << std::endl;

    return true;
}
bool JsonHandler::Deserialize(std::basic_string<char> streamOfJson) {
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
            if (handlingReceivedData(DataOne, DataTwo)) {
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
