#pragma once
#include <string>
#include <iostream>
#include "json-c/json.h"
/**
 *  @file Serialize.h
 *  @version 1.0
 *  @date 17/07/2020
 *  @author Joseph Jimenez.
 *  @class Serialize.
 *  @brief Serializa los objetos en formato json
 */
class Serialize{
public:
	/**
	  * @brief serializa la matriz.
	*/
	static void SerializeMatrix(std::string MatrixMap[20][20]);
};

