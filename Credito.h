#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>
#include <string>
using namespace std;

class Credito
{
private:
    string nombre;
    string apellido;
    string codigoAfiliacion;

public:
    Credito();
    Credito(const string &nom, const string &ape, const string &codigo);

    // Funciones para obtener los datos o getters
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getCodigoAfiliacion() const { return codigoAfiliacion; }

    // Setters (métodos para asignar valores)
    void setNombre(const string &nom) { nombre = nom; }
    void setApellido(const string &ape) { apellido = ape; }
    void setCodigoAfiliacion(const string &codigo) { codigoAfiliacion = codigo; }

    // Sobrecarga de operador ==
    bool operator==(const Credito &otro) const;

    void mostrarInfo() const;
};

#endif