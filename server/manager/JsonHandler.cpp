#include "JsonHandler.h"
bool JsonHandler::handlingReceivedData(std::string DataOne, std::string DataTwo, std::string DataThree, std::string DataFour) {
    std::cout << "Making Something with PosX from client" << std::endl;
    std::cout << "Making Something with PosY from client" << std::endl;
    std::cout << "Making Something with Life from client" << std::endl;
    std::cout << "Making Something with Score from client" << std::endl;
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
            std::string DataOne = root["PosX"].asString();
            std::string DataTwo = root["PosY"].asString();
            std::string DataThree = root["Life"].asString();
            std::string DataFour = root["Score"].asString();
            if (JsonHandler::handlingReceivedData(DataOne, DataTwo, DataThree, DataFour)) {
                std::cout << "I did something with the Data" << std::endl;
                return true;
            }else{
                std::cout << "Something were wrong while handling the Data from Client" << std::endl;
                return false;
            }
        }
    }
    return false;
}