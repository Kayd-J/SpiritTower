#include "breeder.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

breeder::breeder() {
    firstGeneration();
}

void breeder::newGeneration() {
    for (int x = 0; x < 3; x++) {
        vector<Spectrum>* gen = &generations.at(x);
        size_t const half_size = gen->size() / 2;
        vector<Spectrum> split_lo(gen->begin(), gen->begin() + half_size);
        vector<Spectrum> split_hi(gen->begin() + half_size, gen->end());

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
            gen->push_back(cross(genA.at(i), genB.at(i)));
            gen->push_back(cross(genB.at(i), genA.at(i)));
        }
        cout << ".................................." << endl;
    }
    setInTen();
}

void breeder::firstGeneration() {

    srand(time(NULL));

    string labels1 = "ABC";
    string labels2 = "abcdefghij";

    int random1;

    for (int j = 0; j < 3; j++) {
        vector<Spectrum> res;
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
            spectrum->setIdGen(labels1.substr(j, 1) + labels2.substr(i, 1));
            spectrum->setFitness();

            res.push_back(*spectrum);
            cout << "Id: " << spectrum->getIdGen() << "|| Chase Speed: " << spectrum->getChase_speed() << "|| Search Speed : " << spectrum->getSrch_speed() << "|| Range : "
                << spectrum->getRange() << "|| Extra : " << spectrum->getExtra() << "||Fitness: " << spectrum->getFitness() << endl;
        }
        generations.push_back(res);
        cout << "---------------------------------------------------------------------------" << endl;
    }
}

void breeder::displayGeneration(int idx)
{
    vector<Spectrum> gen = generations.at(idx);
    size_t const gen_size = gen.size();
    Spectrum* spectrum;

    for (int i = 0; i < gen_size; i++) {
        spectrum = &gen.at(i);
        cout << "Id: " << spectrum->getIdGen() << "|| Chase Speed: " << spectrum->getChase_speed() << "|| Search Speed : " << spectrum->getSrch_speed() << "|| Range : "
            << spectrum->getRange() << "|| Extra : " << spectrum->getExtra() << "||Fitness: " << spectrum->getFitness() << endl;
    }
}

Spectrum breeder::getBestOne(int idx)
{
    vector<Spectrum> gen = generations.at(idx);
    size_t const gen_size = gen.size();
    Spectrum spectrum;
    int bestIdx;
    int bestFit = 0;


    for (int i = 0; i < gen_size; i++) {
        spectrum = gen.at(i);
        if (spectrum.getFitness() > bestFit) {
            bestIdx = i;
            bestFit = spectrum.getFitness();
        }
    }

    spectrum = gen.at(bestIdx);

    return spectrum;
}

void breeder::setInTen()
{
    vector<Spectrum>* gen;
    int bestIdx;
    int bestFit = 0;
    size_t gen_size;

    for (int i = 0; i < 3; i++) {

        gen = &generations.at(i);
        gen_size = gen->size();

        for (int j = 0; j < 10; j++) {
            pullWorse(i);
        }
    }
}

void breeder::pullWorse(int idx)
{
    vector<Spectrum>* gen = &generations.at(idx);
    size_t const gen_size = gen->size();
    Spectrum spectrum;
    int bestIdx;
    int bestFit = 100;


    for (int i = 0; i < gen_size; i++) {
        spectrum = gen->at(i);
        if (spectrum.getFitness() < bestFit) {
            bestIdx = i;
            bestFit = spectrum.getFitness();
        }
    }


    gen->erase(gen->begin() + bestIdx);



}

Spectrum breeder::cross(Spectrum parentA, Spectrum parentB) {
    Spectrum* son = new Spectrum();

    string geneticA = decToBin(parentA.getChase_speed()) + decToBin(parentA.getSrch_speed());
    string geneticB = decToBin(parentB.getRange()) + decToBin(parentB.getExtra());
    string geneticSon = geneticA.substr(0, 2) + geneticB.substr(0, 2) + geneticA.substr(2, 2) + geneticB.substr(2, 2)
        + geneticA.substr(4, 2) + geneticB.substr(4, 2);
    cout << "La genetica del hijo es..." << endl;
    cout << geneticSon << endl;

    if ((1 + rand() % 100) < 20) {
        geneticSon = mutation(2, geneticSon);
    }
    else if ((1 + rand() % 100) < 30) {
        geneticSon = mutation(1, geneticSon);
    }

    cout << binToDec(stoi(geneticSon.substr(0, 3))) << binToDec(stoi(geneticSon.substr(3, 3))) << binToDec(stoi(geneticSon.substr(6, 3))) << binToDec(stoi(geneticSon.substr(9, 3))) << endl;
    son->setChase_speed(binToDec(stoi(geneticSon.substr(0, 3))));
    son->setSrch_speed(binToDec(stoi(geneticSon.substr(3, 3))));
    son->setRange(binToDec(stoi(geneticSon.substr(6, 3))));
    son->setExtra(binToDec(stoi(geneticSon.substr(9, 3))));
    son->setIdGen(parentA.getIdGen() + parentB.getIdGen());
    son->setFitness();
    cout << "Id: " << son->getIdGen() << "|| Chase Speed: " << son->getChase_speed() << "|| Search Speed : " << son->getSrch_speed() << "|| Range : "
        << son->getRange() << "|| Extra : " << son->getExtra() << "||Fitness: " << son->getFitness() << endl;

    return *son;
}

string breeder::mutation(int op, string genetic)
{
    string subString1;
    string subString2;

    if (op == 1) {
        /*
        int randGen1 = 1 + rand() % 9;
        string change = genetic.substr(randGen1, 1);
        if (change == "1") {
            genetic.substr(randGen1, 1) = "0";
        }
        else {
            genetic.substr(randGen1, 1) = "1";
        }
        */
        int randGen1 = rand() % 9;

        cout << randGen1 << endl;
        string change = genetic.substr(randGen1, 1);
        cout << "Cambia " << change << endl;
        subString1 = genetic.substr(0, randGen1);
        subString2 = genetic.substr(randGen1, genetic.size());
        if (change == "1") {
            return subString1 + "0" + subString2;
        }
        else {
            return subString1 + "1" + subString2;
        }
    }

    else {
        int randGen2 = 0 + rand() % 6;
        string chain;
        string change = genetic.substr(randGen2, 4);
        subString1 = genetic.substr(0, randGen2);
        subString2 = genetic.substr(randGen2 + 4, genetic.size());
        for (int i = 0; i < change.size(); i++) {
            if (change.substr(i, 1) == "1") {
                chain += "0";
            }
            else {
                chain += "1";
            }
        }
        return subString1 + chain + subString2;
    }

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

vector<Spectrum> breeder::getGeneration(int idx) {
    return generations.at(idx);
}
