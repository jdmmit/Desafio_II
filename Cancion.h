#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Credito.h"
using namespace std;

class Cancion
{
private:
    int id_cancion;
    string nombre;
    string artista;
    string album;
    int duracion;
    string ubicacion;
    Lista<string> creditos;

public:
    Cancion();
    Cancion(int id, const string &nom, const string &art, const string &alb, int dur, const string &ubicacion);

    // Funciones para obtener los datos o getters
    int getId() const { return id_cancion; }
    string getNombre() const { return nombre; }
    string getArtista() const { return artista; }
    string getAlbum() const { return album; }
    int getDuracion() const { return duracion; }
    string getUbicacion() const { return ubicacion; }
    Lista<string> &getCreditos() { return creditos; }

    // Método principal
    void reproducir();
};

#endif