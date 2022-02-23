#include <iostream>
#include "Analizador.h"

using namespace std;

int main(){
    (new Analyzer())->disk("Entrada.script");
    return 0;
}