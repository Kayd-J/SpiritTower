// SpiritTower.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Spectrum.h"
#include "breeder.h"
#include <string>

using namespace std;

int main()
{
    /*
    string u = "110011010110";

    int randGen2 = 1 + rand() % 6;
    cout << randGen2 << endl;
    string chain;
    string change = u.substr(randGen2, 3);
    string subString1 = u.substr(0, randGen2);
    string subString2 = u.substr(randGen2 + 3, u.size());
    for (int i = 0; i < change.size(); i++) {
        if (change.substr(i, 1) == "1") {
            chain += "0";
        }
        else {
            chain += "1";
        }
    }
    cout << change << endl;
    cout << subString1 << endl;
    cout << chain << endl;
    cout << subString2 << endl;
    cout << subString1 + chain + subString2 << endl;;
    */
    
    vector<Spectrum> especs;
    breeder* breeder1 = new breeder();

    breeder1->displayGeneration(0);

    breeder1->newGeneration();
    breeder1->newGeneration();
    breeder1->newGeneration();
    //breeder1->newGeneration();

    breeder1->displayGeneration(0);

    cout<<"El mejor de la gen A es: " <<breeder1->getBestOne(0).getId()<<endl;

    

    //string u = "1111100000";
    /**
    for (int i = 0; i < 4; ++i) {
        int ran = rand() % 2;
        cout << ran << endl;
    }
    **/
    
    //especs = breeder1->firstGeneration();
   // especs = breeder1->newGeneration(especs);
    //cout << especs.at(2).getExtra() << endl;



    /*
    int randGen1 = 1 + rand() % 9;
    string subString1;
    string subString2;
    cout << randGen1 << endl;
    string change = u.substr(randGen1, 1);
    cout << change << endl;
    subString1 = u.substr(0, randGen1-1);
    subString2 = u.substr(randGen1, u.size());
    if (change == "1") {
        cout << subString1 + "0" + subString2 << endl;
    }
    else {
        cout << subString1 + "1" + subString2 << endl;
    }
    */
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
