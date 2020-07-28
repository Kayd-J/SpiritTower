/**
  * @file breeder.h
  * @title breeder
  * @brief Utiliza algor[itmos genéticos para mejorar enemigos
  * @version 1.0
  * @author JoseSol
  * @date 20/07/2020
  */

#pragma once
#include "Spectrum.h"
#include <iostream>
//#include <tgmath.h>

using namespace std;

class breeder
{

private:

    vector<vector<Spectrum>> generations;

    vector<Spectrum> genA;
    vector<Spectrum> genB;

    Spectrum parentA;
    Spectrum parentB;

    /**
     * @brief Realiza el cruce entre dos espectros
     * @param parentA, parentB
     * @return Espectro hijo
     */
    Spectrum cross(Spectrum parentA, Spectrum parentB);

    /**
     * @brief Realiza mutaciones a una cadena de genes
     * @param op, genetic
     * @return cadena de genes mutada
     */
    string mutation(int op, string genetic);

public:
    /**
     * Convierte un numero de decimal a binario.
     * @param n
     * @return resultado
    */
    string decToBin(int n);

    /**
     * Convierte un numero de binario a decimal.
     * @param binario
     * @return resultado
    */
    int binToDec(int binario);

    /**
     * @brief Constructor de breeder
     */
    breeder();

    /**
     * @brief Obtiene la generación de un índice dado
     * @param idx
     * @return generación
     */
    vector<Spectrum> getGeneration(int idx);

    /**
     * @brief Crea una nueva generación de espectros
     */
    void newGeneration();

    /**
     * @brief Crea la primera generación de espectros con genes aleatorios
     */
    void firstGeneration();

    /**
     * @brief Imprime en consola la generación actual de un indice definido
     * @param idx
     */
    void displayGeneration(int idx);

    /**
     * @brief Busca al mejor espectro d euna generación definida por un indice
     * @param idx
     * @return El mejor espectro
     */
    Spectrum getBestOne(int idx);

    /**
     * @brief Establece el tamaño de la población en 10 para cada generación, elimina a los peores
     */
    void setInTen();

    /**
     * @brief Saca al espectro más débil de una generación definida por un índice
     * @param idx
     */
    void pullWorse(int idx);
};
