#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "partitions.h"

using namespace std;

int size = 0;
int unit = 0;
string path, name;
int particionesLogicas = 23;
int pref = 17;

struct Partitions{
    int size = 0;
    char name[27];
};

struct PMBR{
    int mbr_size;
    char mbr_create_date[17];
    int mbr_dsk_signature;
    Partitions particiones[4];
};


void Particiones ::analizador_fd(string direccion){
    stringstream dato(direccion);
    string recorrido;
    int positions = 0;
    while (getline(dato, recorrido, '=')){
        if (recorrido == "-Size"){
            positions = 1;
        
        }else if(recorrido == "-unit"){
            positions = 2;
        
        }else if(recorrido == "-path"){
            positions = 3;

        }else if(recorrido == "-name"){
            positions = 4;
        
        }else if(positions == 1){
            size = stoi(recorrido);
            cout << size << endl;
        
        }else if(positions == 2){
            if(recorrido == "K"){
                unit = 1024;
                cout << recorrido << endl;
            
            }else if(recorrido == "M"){
                unit = 1024*1024;
                cout << recorrido << endl;
            
            }
        
        }else if(positions == 3){
            path = recorrido;
            cout << path + "\n";
        
        }else if(positions == 4){
            name = recorrido;
            cout << name + "\n";
        }
        
    }
}

void Particiones :: write_partition(){
    PMBR partitionMBR;

    FILE *archivo = fopen(path.c_str(), "r+");
    fseek(archivo, 0, SEEK_SET);
    fread(&partitionMBR, sizeof(PMBR), 1, archivo);

    //Se ve si hay una particion libre
    int indexP = 0;
    for (int i = 0; i < 4; i++){
        if(partitionMBR.particiones[i].size == 0){
            indexP = i;
            break;
        }
    }

    Partitions nueva;
    nueva.size = unit*size;
    strcpy(nueva.name, name.c_str());

    partitionMBR.particiones[indexP] = nueva;

    fseek(archivo, 0, SEEK_SET);
    fwrite(&partitionMBR, sizeof(PMBR), 1, archivo);

    fclose(archivo);
}

void Particiones :: ejecudar_particion(){
    Particiones().write_partition();
    cout << "Particion creada\n";
}

