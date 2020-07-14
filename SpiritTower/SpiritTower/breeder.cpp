#include "pch.h"
#include "breeder.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

breeder::breeder() {

}

vector<Spectrum> breeder::newGeneration(vector<Spectrum> gen) {
    size_t const half_size = gen.size() / 2;
    vector<Spectrum> split_lo(gen.begin(), gen.begin() + half_size);
    vector<Spectrum> split_hi(gen.begin() + half_size, gen.end());

    this->genA = split_lo;
    this->genB = split_hi;
    /**
    cout << "Complete size: " <<gen.size()<<endl;
    cout << "GenA size: " << genA.size() << endl;
    cout << "GenB size: " << genB.size() << endl;
    
    cout << "||Gen A||" << endl;
    for (int i = 0; i < genA.size(); i++) {
        cout<<genA.at(i).getId()<<endl;
    }
    cout << "\n||Gen B||" << endl;
    for (int i = 0; i < genB.size(); i++) {
        cout << genB.at(i).getId() << endl;
    }
    **/
    for (int i = 0; i < half_size; i++) {
        cross(genA.at(i), genB.at(i));
    }

    return genB;
}

vector<Spectrum> breeder::firstGeneration() {

    srand(time(NULL));

    vector<Spectrum> res;

    string labels = "abcdefghij";

    int random1;

    for (int i = 0; i < 10; i++) {
        Spectrum* spectrum = new Spectrum();
        random1 = 1 + rand() % 2;
        spectrum->setChase_speed(random1);
        random1 = 1 + rand() % 2;
        spectrum->setSrch_speed(random1);
        random1 = 1 + rand() % 2;
        spectrum->setRange(random1);
        random1 = rand() % 2;
        spectrum->setExtra(random1);
        spectrum->setId(labels[i]);
        spectrum->setFitness();

        res.push_back(*spectrum);
        cout <<"Id: "<< spectrum->getId() <<"|| Chase Speed: " << spectrum->getChase_speed() << "|| Search Speed : " << spectrum->getSrch_speed() << "|| Range : "
            << spectrum->getRange() << "|| Extra : " << spectrum->getExtra() <<"||Fitness: "<<spectrum->getFitness()<< endl;
    }

    return res;
}

Spectrum breeder::cross(Spectrum parentA, Spectrum parentB) {
    Spectrum son;

    string geneticA = decToBin(parentA.getChase_speed()) + decToBin(parentA.getSrch_speed());
    string geneticB = decToBin(parentB.getRange()) + decToBin(parentB.getExtra());
    string geneticSon = geneticA + geneticB;
    /**
    if ((1 + rand() % 100) < 6) {
        geneticSon = mutation(2, geneticSon);
    }
    else if ((1 + rand() % 100) < 9) {
        geneticSon = mutation(1, geneticSon);
    }
    **/
    cout << binToDec(stoi(geneticSon.substr(0, 3))) << binToDec(stoi(geneticSon.substr(3, 3))) << binToDec(stoi(geneticSon.substr(6, 3))) << binToDec(stoi(geneticSon.substr(9, 3)))<<endl;
    son.setChase_speed(binToDec(stoi(geneticSon.substr(0, 3))));
    son.setSrch_speed(binToDec(stoi(geneticSon.substr(3, 3))));
    son.setRange(binToDec(stoi(geneticSon.substr(6, 3))));
    son.setExtra(binToDec(stoi(geneticSon.substr(9, 3))));
    
    return son;
}

string breeder::mutation(int op, string genetic)
{
    int randGen = 1 + rand() % 12;
    if (op == 1) {

        string change = genetic.substr(randGen, 1);
        if (change == "1") {
            genetic.substr(randGen, 1) = "0";
        }
        else {
            genetic.substr(randGen, 1) = "1";
        }
    }
    /**
    else{
        string change = genetic.substr(randGen, 3);
        if (change == "1") {
            genetic.substr(randGen, 1) = "0";
        }
        else {
            genetic.substr(randGen, 1) = "1";
        }
    }
    **/
    return genetic;
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

