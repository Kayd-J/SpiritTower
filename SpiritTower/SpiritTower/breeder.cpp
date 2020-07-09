#include "pch.h"
#include "breeder.h"


breeder::breeder() {

}

vector<Spectrum> breeder::newGeneration(vector<Spectrum> gen) {
    this->gen1 = gen;



    return gen2;
}

vector<Spectrum> breeder::newGeneration() {

    vector<Spectrum> res;

    int random1;

    for (int i = 0; i < 3; i++) {
        Spectrum* spectrum = new Spectrum();
        random1 = 1 + rand() % 2;
        spectrum->setChase_speed(random1);
        random1 = 1 + rand() % 2;
        spectrum->setSrch_speed(random1);
        random1 = 1 + rand() % 2;
        spectrum->setRange(random1);
        random1 = rand() % 2;
        spectrum->setExtra(random1);

        res.push_back(*spectrum);
        cout << spectrum->getChase_speed() << "  " << spectrum->getSrch_speed() << "  "
            << spectrum->getRange() << "  " << spectrum->getExtra() << endl;
    }

    return res;
}

Spectrum breeder::cross(Spectrum) {
    Spectrum result;
    return result;
}


string breeder::decToBin(int n)
{
    // Size of an integer is assumed to be 32 bits
    string res;
    for (int i = 2; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            res += "1";
        else
            res += "0";
    }
    return res;
}


int breeder::binToDec(int binario)
{
    int exp, digito;
    int decimal;

    exp = 0;
    decimal = 0;
    while (((int)(binario / 10)) != 0)
    {

        digito = (int)binario % 10;
        decimal = decimal + digito * pow(2, exp);
        exp++;
        binario = (int)(binario / 10);
    }
    decimal = decimal + binario * pow(2, exp);
    //cout << endl << "Decimal: " << decimal << endl;
    return decimal;
}

int breeder::getGeneration() {
    return generation;
}