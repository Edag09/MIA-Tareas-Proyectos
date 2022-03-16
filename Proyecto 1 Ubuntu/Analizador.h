#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "mkdisk.h"
#include "partitions.h"

using namespace std;

class Analyzer{
    public:
        void disk(string cad);
};

void Analyzer :: disk(string path){
    ifstream docs(path);
    string lector;

    //Inicia el analizador

    while (getline(docs, lector)){
        int position = 0;
        stringstream entrada(lector);
        string recorrido;

        // Reconoce los comandos

        while (getline(entrada, recorrido, ' ')){
            if(recorrido == "mkdisk"){
                position = 1;
                cout << "Creando Disco...\n";

            }else if(recorrido == "rmdisk"){
                position == 2;
                //cout << "Removiendo disco\n";

            }else if(recorrido == "fdisk"){
                position = 3;
                cout << "Buscando disco...\n";

            }else if(recorrido == "mount"){
                cout << "Montando disco\n";

            }else if(recorrido == "unmount"){
                cout << "Desmontando disco\n";

            }else if(recorrido == "mkfs"){
                cout << "Formateando disco\n";

            }else if(recorrido == "rep"){
                position = 7;
                cout<<"Generando Reporte\n";

            }else if(position == 1){
                //Analizador MK
                Creacion().analizador_mk(recorrido);
                //cout << "Analiza el MK\n";
            
            }else if(position == 2){
                //Eliminacion del disco
                
                cout << "Removiendo\n";
            
            }else if(position == 3){
                //Analizador FD
                Particiones().analizador_fd(recorrido);
                //cout << "Analizar el FD\n";
            }
        }

        stringstream entrada2(lector);
        string recorrido2;

        //Ejecuta los comandos

        while (getline(entrada2, recorrido2, ' ')){
            if( recorrido2 == "mkdisk"){
                //Ejecuta MK
                Creacion().ejecutarMK();
                break;
                //cout<<"Ejecutando Disco\n";

            }else if( recorrido2 == "rmdisk"){
                //Remover dsico
                //Creacion().analizador_rm(recorrido2);
                cout << "Disco Removido\n";

            }else if( recorrido2 == "fdisk"){
                Particiones().ejecudar_particion();
                break;
                //cout << "Disco encontrado\n";

            }else if( recorrido2 == "mount"){
                cout << "Disco montado\n";

            }else if( recorrido2 == "unmount"){
                cout << "Disco desmontado\n";

            }else if( recorrido2 == "mkfs"){
                cout << "Disco Formateado\n";

            }else if( recorrido2 == "rep"){
                cout << "Reportes generados\n";

            }
        }
          
    }
    
}