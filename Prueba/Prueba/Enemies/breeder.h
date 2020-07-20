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


    Spectrum cross(Spectrum parentA, Spectrum parentB);

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

    breeder();

    vector<Spectrum> getGeneration(int idx);

    void newGeneration();
    void firstGeneration();
    void displayGeneration(int idx);
    Spectrum getBestOne(int idx);
    void setInTen();
    void pullWorse(int idx);
};
