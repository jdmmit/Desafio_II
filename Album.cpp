#include "Album.h"
#include <iostream>

Album::Album() : id_album(0), nombre(""), artista(""), fecha(""), portada("") {}

Album::Album(int id, const string &nom, const string &art, const string &fecha, const string &portada)
    : id_album(id), nombre(nom), artista(art), fecha(fecha), portada(portada) {}

void Album::agregar()
{
    cout << "=== AGREGAR ALBUM ===" << endl;
    cout << "ID: " << id_album << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Artista: " << artista << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Portada: " << portada << endl;
    cout << "Canciones: " << canciones.obtenerTamanio() << endl;
    cout << "Album agregado correctamente." << endl;
}