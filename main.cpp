#include "SistemaUdeATunes.h"
#include <iostream>

using namespace std;

int main(){
    cout << "=== SISTEMA UDEATUNES ===" << endl;

    SistemaUdeATunes sistema;
    sistema.cargarDatos();

    // Menu principal interactivo
    sistema.menuPrincipal();

    cout << "\n === PROGRAMA FINALIZADO ===" << endl;
    return 0;
}
