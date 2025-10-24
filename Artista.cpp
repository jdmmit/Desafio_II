#include "Artista.h"

Artista::Artista() : id_artista(0), nombre(""), edad(0), pais("") {}

Artista::Artista(int id, const string &nom, int edad, const string &pais)
    : id_artista(id), nombre(nom), edad(edad), pais(pais) {}

void Artista::Info()
{
    cout << "=== INFORMACION DEL ARTISTA ===" << endl;
    cout << "ID: " << id_artista << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anos" << endl;
    cout << "Pais: " << pais << endl;
    cout << "Albumes en catalogo: " << catalogo.obtenerTamanio() << endl;
    cout << "==============================" << endl;
}
