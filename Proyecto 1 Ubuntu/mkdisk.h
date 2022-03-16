#include <iostream>
#include <string>

//Se escriben todos los metodos a utilizar en el mkdisk

using namespace std;


class Creacion{
    public:
        void writedisk();
        string fecha_formato(int data);
        string obtener_fecha();
        void analizador_mk(string data);
        void ejecutarMK();
        void analizador_rm(string path);
        void borrardk(string path);
};