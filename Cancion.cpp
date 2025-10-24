#include "Cancion.h"
#include <iostream>

Cancion::Cancion() : id_cancion(0), nombre(""), artista(""), album(""), duracion(0), ubicacion("") {}

Cancion::Cancion(int id, const string &nom, const string &art, const string &alb, int dur, const string &ubicacion)
    : id_cancion(id), nombre(nom), artista(art), album(alb), duracion(dur), ubicacion(ubicacion) {}

void Cancion::reproducir()
{
    cout << "=== REPRODUCIENDO CANCION ===" << endl;
    cout << "ID: " << id_cancion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Artista: " << artista << endl;
    cout << "Album: " << album << endl;
    cout << "Duracion: " << duracion << " segundos" << endl;
    cout << "Ubicacion: " << ubicacion << endl;
    cout << "Creditos: " << creditos.obtenerTamanio() << endl;
    cout << "♪ Reproduciendo... ♪" << endl;
}