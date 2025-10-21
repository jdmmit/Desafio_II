#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "Lista.h>"
#include "Enumeraciones.h"

using namespace std;

class Usuario
{
private:
    int id_usuario;
    string nickname;
    string nombre;
    int edad;
    TipoMembresia membresia;
    string ciudad;
    Lista<int> favorito; // ID de canciones favoritas.

public:
    Usuario();
    Usuario(int id, const string& nick, const string& nom, int edad, TipoMembresia mem, const string& ciudad);

    // Funciones para obtener los datos del usuario o getters
    int getID() const { return id_usuario; }
    string getNickname() const { return nickname; }
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    TipoMembresia getMembresia() const { return membresia; }
    string getCiudad() const { return ciudad; }
    Lista<int>& getFavorito() { return favorito; }

    bool login();

};

#endif
