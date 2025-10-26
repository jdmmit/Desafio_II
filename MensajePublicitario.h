#ifndef MENSAJEPUBLICITARIO_H
#define MENSAJEPUBLICITARIO_H

#include <iostream>
#include <string>
#include "Enumeraciones.h"
using namespace std;

class MensajePublicitario
{
private:
    string contenido;
    CategoriaPublicidad categoria;

public:
    MensajePublicitario();
    MensajePublicitario(const string &mensaje, CategoriaPublicidad cat);

    // Getters
    string getContenido() const { return contenido; }
    CategoriaPublicidad getCategoria() const { return categoria; }

    // Setters
    void setContenido(const string &mensaje) { contenido = mensaje; }
    void setCategoria(CategoriaPublicidad cat) { categoria = cat; }

    // Métodos según UML
    void mostrar() const;
    int prioridad() const;
};

#endif