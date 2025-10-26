#include "Usuario.h"

Usuario::Usuario() : id_usuario(0), nickname(""), nombre(""), edad(0), membresia(ESTANDAR), ciudad("")
{}

Usuario::Usuario(int id, const string& nick, const string& nom, int edad, TipoMembresia mem, const string& ciudad) : id_usuario(id), nickname(nick), nombre(nom), edad(edad), membresia(mem), ciudad(ciudad){}

bool Usuario::login() {
    cout << "Login para usuario: " << nickname << endl;
    cout << "ID: " << id_usuario << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anos" << endl;
    cout << "Membresia: " << (membresia == PREMIUM ? "Premium" : "Estandar") << endl;
    cout << "Ciudad: " << ciudad << endl;
    return true;
}
