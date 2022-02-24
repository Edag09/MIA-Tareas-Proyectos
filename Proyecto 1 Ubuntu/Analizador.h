#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct mkdisk{
    int size;
    string fit = "BF";
    int unit = 1024*1024;
    string path;
};

class Analyzer{
public:
    mkdisk MBR;
public:
    void disk(string cad);
    void create_disk(string cadena);
    void find_disk(string cadena);
    void Ejecucion();
};

void Analyzer::disk(string path) {
    int status = 0;
    ifstream docs(path);
    string lector;
    //Se abre el archivo para poder leerlo
    while (getline(docs, lector)){
        stringstream entrada(lector);
        string cadena;
        //Se lee cada una de las lineas que trae el archivo
        while (getline(entrada, cadena, ' ')){
            //Se crea el disco
            if (cadena == "mkdisk"){
                cout << "Disco Creado\n";
                //create_disk(cadena);
                status = 1;
            }else
            // Se remueve el disco
            if(cadena == "rmdisk"){
                cout << "Disco Removido\n";
            }else
            //Se monta el disco
            if(cadena == "mount"){
                cout << "Disco Montado\n";
            }else
            //Se desmonta el disco
            if(cadena == "unmount"){
                cout << "Disco Desmontado\n";
            }else
            //Se busca en el disco
            if(cadena == "fdisk"){
                cout << "Busqueda de Disco\n";
            }else
            //Se formatea el disco
            if (cadena == "mkfs"){
                cout << "Disco Formateado\n";
            }else
            //Se crea los reportes
            if(cadena == "rep"){
                cout << "Reporte General\n";
            }else if(status == 1){
                create_disk(cadena);
            }
            
        }

        stringstream pas2(path);
        string recorrido;
        while (getline(pas2, recorrido, ' ')){
            if (recorrido == "mkdisk"){
                    Ejecucion();
                    break;
                }else
                // Se remueve el disco
                if(recorrido == "rmdisk"){
                    cout << "Disco Removido\n";
                }else
                //Se monta el disco
                if(recorrido == "mount"){
                    cout << "Disco Montado\n";
                }else
                //Se desmonta el disco
                if(recorrido == "unmount"){
                    cout << "Disco Desmontado\n";
                }else
                //Se busca en el disco
                if(recorrido == "fdisk"){
                    cout << "Busqueda de Disco\n";
                }else
                //Se formatea el disco
                if (recorrido == "mkfs"){
                    cout << "Disco Formateado\n";
                }else
                //Se crea los reportes
                if(recorrido == "rep"){
                    cout << "Reporte General\n";
                }
            
        }   
    }
}

void Analyzer::create_disk(string creacion){
    stringstream crea(creacion);
    string body;
    int status = 0;
    while (getline(crea, body, '=')){
        if (body == "-Size"){
            status = 1;
        }else if(body == "-unit"){
            status = 2;
        }else if(body == "-path"){
            status = 3;
        }else if(status == 1){
            MBR.size = stoi(body);
            cout << MBR.size << endl;
        }else if(status == 2){
            if (body == "K")
            {
                MBR.unit = 1024;
                cout << body << endl;
            }else if(body == "M"){
                MBR.unit = 1024*1024;
                cout << body << endl;
            }
        }else if(status == 3){
            MBR.path = body;
            cout << MBR.path << endl;
        }
        
    }
    
}

void Analyzer::find_disk(string find){
    cout << find << endl;
}

void Analyzer::Ejecucion(){
    cout<<"Archivo binario creado\n";
}