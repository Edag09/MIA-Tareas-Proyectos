#include <iostream>
#include <string.h>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "mkdisk.h"

using namespace std;

struct partitions{
    int size = 0;
    char unit;
    char name[25];
};


struct mkcreation{
    int mbr_size;
    char mbr_create_date[17];
    int mbr_dsk_signature;
};


struct mkdisk{
    int mbr_size;
    char mbr_create_date[17];
    int mbr_dsk_signature;
    int size;
    string fit = "BF";
    int unit = 1024*1024;
    string path;
};

mkdisk MBR;
mkcreation MBRC;

string Creacion :: fecha_formato(int data){
    return (data < 10 ? "0" : "") + to_string(data);  
}

string Creacion :: obtener_fecha(){
    time_t tiempo_actual = time(0);
    tm *ahora = localtime(&tiempo_actual);
    string date = fecha_formato(ahora->tm_mday) + "/" + fecha_formato(ahora->tm_mon + 1) + "/" + to_string(ahora->tm_year + 1900) + " " + fecha_formato(ahora->tm_hour) + ":" + fecha_formato(ahora->tm_min);
    return date;
}

void Creacion :: analizador_mk(string data){
    int status = 0;
    stringstream MK(data);
    string lectura;
    while (getline(MK, lectura, '=')){
        if (lectura == "-Size"){
            status = 1;
        }else if(lectura == "-unit"){
            status = 2;
        }else if(lectura == "-path"){
            status = 3;
        }else if(status == 1){
            MBR.size = stoi(lectura);
            cout << MBR.size << endl;
        }else if(status == 2){
            if (lectura == "K"){
                MBR.unit = 1024;
                cout << lectura << endl;
            }else if(lectura == "M"){
                MBR.unit = 1024*1024;
                cout << lectura << endl;
            }
        }else if(status == 3){
            MBR.path = lectura;
            cout << MBR.path << endl;
        }   
    }
}

void Creacion :: writedisk(){
    int mbr_size =  MBR.size * MBR.unit;
    string mbr_fecha_creacion = obtener_fecha();
    int mbr_signature = rand()%10;

    MBRC.mbr_size = mbr_size;
    strcpy(MBRC.mbr_create_date, mbr_fecha_creacion.c_str());
    MBRC.mbr_dsk_signature = mbr_signature;

    FILE *archivo_disco = fopen(MBR.path.c_str(), "wb");

    fseek(archivo_disco, 0, SEEK_SET);

    char buffer[1024];
    for (int i = 0; i<1024; i++){
        buffer[i] = '\0';
    }

    for (int index = 0; index < mbr_size/1024; index++){
        fwrite(&buffer, 1024, 1, archivo_disco);
    }

    fseek(archivo_disco, 0, SEEK_SET);

    fwrite(&MBRC, sizeof(MBRC), 1, archivo_disco);

    fclose(archivo_disco);
}

void Creacion :: ejecutarMK(){
    Creacion().writedisk();
    cout << "Disco Creado\n";
}


void Creacion :: analizador_rm(string direccion){
    stringstream eliminar(direccion);
    string lecture;
    int position = 0;
    while (getline(eliminar, lecture, '=')){
        if (lecture == "-path"){
            position = 1;
        }else if(position == 1){
            //Creacion().borrardk(lecture);
            cout << "Aqui\n";
            cout << lecture << endl;
        }
        
    }
    
}


void Creacion :: borrardk(string direccion){
    string pregunta;
    if(direccion.length() > 0){
        //Abre el archivo 
        FILE *archivo = fopen(direccion.c_str(), "rb");

        //Pregunta si esta
        if(archivo != NULL){
            cout << "¿Estas seguro de querer eliminar el disco? (s/n):\n";
            cin >> pregunta;

            if(pregunta == "s" || pregunta == "S"){
                int removed = remove(direccion.c_str());
                if(removed != 0)
                    cout << "No es posible eliminar el disco\n";
            }
            fclose(archivo);
        }else{
            cout << "El disco se existe\n";
        }
    }else
        cout << "Tienes que ingresar una direccion\n";
}
