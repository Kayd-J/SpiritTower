/**
  * @file Spectrum.h
  * @title Spectrum
  * @brief Individuo espectro, enemigo m�s complejo del juego
  * @version 1.0
  * @author JoseSol
  * @date 20/07/2020
  */

#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "../LinkedList/LinkedList.h"

using namespace std;

class Spectrum {
private:
    int srch_speed;
    int chase_speed;
    int range;
    int extra;
    string id;
    int fitness;
    string idGen;


public:

    bool catchPlayer = false;

    bool walking = false;

    /**
     * @brief Constructor del espectro
     */
    Spectrum();

    /**
     * @brief Obtiene la velocidad de b�squeda
     * @return Velocidad de b�squeda del espectro
     */
    int getSrch_speed() const;

    /**
     * @brief Asigna la velocidad de b�squeda
     * @param Velocidad de b�squeda del espectro
     */
    void setSrch_speed(int srch_speed_);

    /**
     * @brief Obtiene la velocidad de persecuci�n
     * @return Velocidad de persecuci�n del espectro
     */
    int getChase_speed() const;

    /**
     * @brief Asigna la velocidad de persecuci�n
     * @param Velocidad de persecuci�n del espectro
     */
    void setChase_speed(int chase_speed_);

    /**
     * @brief Obtiene el rango del espectro
     * @return Rango del espectro
     */
    int getRange() const;

    /**
     * @brief Asigna el rango del espectro
     * @param Rango del espectro
     */
    void setRange(int range_);

    /**
     * @brief Obtiene el valor del atributo extra del espectro
     * @return Atributo extra del espectro
     */
    int getExtra() const;

    /**
     * @brief Asigna el valor del atributo extra del espectro
     * @param Atributo extra del espectro
     */
    void setExtra(int extra_);

    /**
     * @brief Obtiene el identificador del espectro
     * @return Identificador del espectro
     */
    string getId() const;

    /**
     * @brief Asigna el identificador del espectro
     * @param Identificador del espectro
     */
    void setId(string id_);

    /**
     * @brief Obtiene el fitness del espectro
     * @return Fitness del espectro
     */
    int getFitness() const;

    /**
     * @brief Calcula el fitness del espectro
     */
    void setFitness();

    /**
     * @brief Obtiene el identificador de generaci�n del espectro
     * @retun Identificador de generaci�n del espectro
     */
    string getIdGen() const;

    /**
     * @brief Asigna el identificador de generaci�n del espectro
     * @param Identificador de generaci�n
     */
    void setIdGen(string idgen_);

    int posX;
    int posY;

    int tempX;
    int tempY;

    LinkedList backTrackPath;

    LinkedList* patrollArea;

    string dir = "N";

    int movimientos = 0;

    string color;

    bool death = false;
};