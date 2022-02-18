#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

string path = "./disk.dk";

struct MBR{
    int size;
    char create_date[17];
    int disk_signature;
};

string Fecha (int arch){
    return (arch < 10 ? "0" : "")+ to_string(arch);
}

string obtener(){
    time_t time_actual = time(0);
    tm *ahora = localtime(&time_actual);
    string data = Fecha(ahora->tm_mday) + "/" + Fecha(ahora->tm_mon+1) + "/" + to_string(ahora->tm_year+1900) + " " + Fecha(ahora->tm_hour) + ":" + Fecha(ahora->tm_min);
    return data;
}

void escritura(){
    MBR disco;

    int size = 1024 * 1024 * 5;
    string create_date = obtener();
    int disk_signature = rand() % 10;

    disco.size = size;
    strcpy(disco.create_date, create_date.c_str());
    disco.disk_signature = disk_signature;

    FILE *disk = fopen(path.c_str(), "rb+");
    fseek(disk, 0, SEEK_SET);
    char characters[1024];

    for (int i = 0; i < 1024; ++i)
        characters[i] = '\0';

    for (int index = 0; index < size/1024; ++index)
        fwrite(&characters, 1024, 1, disk);

    fseek(disk, 0, SEEK_SET);
    fwrite(&disco, sizeof(MBR), 1, disk);
    fclose(disk);

}

void mostrar_Disco(){

    MBR disco;

    FILE *disk = fopen(path.c_str(), "r+");
    fseek(disk, 0, SEEK_SET);
    fread(&disco, sizeof(MBR), 1, disk);
    fclose(disk);
    
    cout << disco.size << endl;
    cout << disco.create_date << endl;
    cout << disco.disk_signature << endl;
}

void openFile(string dirrecion){
    ifstream archivo(dirrecion);
    string linea;
    while(getline(archivo, linea)){
        if (linea == "mkdisk"){
            escritura();
        }else{
            mostrar_Disco();
        }
        
    }

}

int main(int argc, char *argv[]) {
    cout << "Eduardo Rene Agustin Mendoza \n 201801627" << endl;
    openFile(argv[3]);
}