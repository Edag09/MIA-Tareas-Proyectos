#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Analizador.h"

using namespace std;

int main() {
    (new Analyzer())->disk("Entrada.script");
    return 0;
}
