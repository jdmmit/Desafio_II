#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Album.h"
using namespace std;

class Artista
{
private:
    int id_artista;
    string nombre;
    int edad;
    string pais;
    Lista<Album> catalogo;

public:
    Artista();
    Artista(int id, const string &nom, int edad, const string &pais);

    // Funciones para obtener los datos o getters
    int getId() const { return id_artista; }
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getPais() const { return pais; }
    Lista<Album> &getCatalogo() { return catalogo; }

    // Método principal
    void Info();
};

#endif
