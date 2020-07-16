#include "Serialize.h"

std::string Serialize::SerializeMap(std::string MatrixMap) {
    //std::basic_string<char,std::char_traits<char>,std::allocator<char>>
    Json::Value dataToSend;
    dataToSend["Matrix"] = MatrixMap;
    static Json::StreamWriterBuilder builder;
    std::string json_file = Json::writeString(builder, dataToSend);
    return json_file;
}
