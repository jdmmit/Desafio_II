#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Cancion.h"
#include "Enumeraciones.h"
using namespace std;

class Album
{
private:
    int id_album;
    string nombre;
    string artista;
    string fecha;
    string portada;
    Lista<Cancion> canciones;

public:
    Album();
    Album(int id, const string &nom, const string &art, const string &fecha, const string &portada);

    // Funciones para obtener los datos o getters
    int getId() const { return id_album; }
    string getNombre() const { return nombre; }
    string getArtista() const { return artista; }
    string getFecha() const { return fecha; }
    string getPortada() const { return portada; }
    Lista<Cancion> &getCanciones() { return canciones; }

    // Método principal
    void agregar();
};

#endif
