#pragma once


#include "Spectrum.h"
#include <iostream>
//#include <tgmath.h>

using namespace std;

class breeder
{

private:

    int generation = 1;

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

    int getGeneration();

    vector<Spectrum> newGeneration(vector<Spectrum> gen);
    vector<Spectrum> firstGeneration();
};

