//
// Created by renea on 21/02/2022.
//

#ifndef PROYECTO_1_ANALIZADOR_H
#define PROYECTO_1_ANALIZADOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Analyzer{
public:
    void disk(string cad);
};

void Analyzer::disk(string path) {
    cout << path << endl;
    ifstream docs(path);
    string lector;

    while (getline(docs, lector)){
        cout << lector << endl;
    }
}

#endif //PROYECTO_1_ANALIZADOR_H
