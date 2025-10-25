#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <string>
#include <fstream>
#include "Lista.h"
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
    string archivoRuta;
    Lista<string> creditos;

public:
    Cancion();
    Cancion(int id, const string &nom, const string &art, const string &alb, int dur, const string &ubicacion);

    // Getters
    int getId() const { return id_cancion; }
    string getNombre() const { return nombre; }
    string getArtista() const { return artista; }
    string getAlbum() const { return album; }
    int getDuracion() const { return duracion; }
    string getUbicacion() const { return ubicacion; }
    string getArchivoRuta() const { return archivoRuta; }
    Lista<string> &getCreditos() { return creditos; }

    // Metodo para cargar desde archivo
    bool cargarDesdeArchivo(string rutaArchivo);

    // Metodo de reproduccion
    void reproducir();
};

#endif