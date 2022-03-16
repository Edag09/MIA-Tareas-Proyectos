#include <iostream>
#include "Analizador.h"

using namespace std;

int main(int argc, char *argv[]){
    (new Analyzer())->disk("Entrada.script");
    return 0;
}