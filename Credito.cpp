#include "Credito.h"

Credito::Credito() : nombre(""), apellido(""), codigoAfiliacion("") {}

Credito::Credito(const string &nom, const string &ape, const string &codigo)
    : nombre(nom), apellido(ape), codigoAfiliacion(codigo) {}

bool Credito::operator==(const Credito &otro) const
{
    return codigoAfiliacion == otro.codigoAfiliacion;
}

void Credito::mostrarInfo() const
{
    cout << nombre << " " << apellido << " (Codigo: " << codigoAfiliacion << ")";
}