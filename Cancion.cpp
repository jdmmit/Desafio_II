#include "Cancion.h"
#include <iostream>
#include <fstream>

Cancion::Cancion() : id_cancion(0), nombre(""), artista(""), album(""), duracion(0), ubicacion(""), archivoRuta("") {}

Cancion::Cancion(int id, const string &nom, const string &art, const string &alb, int dur, const string &ubicacion)
    : id_cancion(id), nombre(nom), artista(art), album(alb), duracion(dur), ubicacion(ubicacion), archivoRuta("") {}

// cargar la info de la cancion desde el txt
bool Cancion::cargarDesdeArchivo(string rutaArchivo)
{
    ifstream archivo(rutaArchivo);

    if (!archivo.is_open())
    {
        return false;
    }

    archivoRuta = rutaArchivo;
    string linea;

    // leer todo el archivo
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(':');
        if (pos != string::npos)
        {
            string campo = linea.substr(0, pos);
            string valor = linea.substr(pos + 2);

            // ver que campo es y guardarlo
            if (campo == "ID")
            {
                id_cancion = stoi(valor);
            }
            else if (campo == "Nombre")
            {
                nombre = valor;
            }
            else if (campo == "Artista")
            {
                artista = valor;
            }
            else if (campo == "Album")
            {
                album = valor;
            }
            else if (campo == "Duracion")
            {
                duracion = stoi(valor);
            }
            else if (campo == "Ubicacion")
            {
                ubicacion = valor;
            }
            else if (campo == "Creditos")
            {
                // separar los creditos por coma
                string temp = "";
                for (size_t j = 0; j < valor.length(); j++)
                {
                    if (valor[j] == ',')
                    {
                        creditos.agregar(temp);
                        temp = "";
                    }
                    else
                    {
                        temp = temp + valor[j];
                    }
                }
                if (temp != "")
                {
                    creditos.agregar(temp);
                }
            }
        }
    }

    archivo.close();
    return true;
}

void Cancion::reproducir()
{
    cout << "\n=== REPRODUCIENDO CANCION ===" << endl;
    cout << "Archivo: " << archivoRuta << endl; // mostrar de donde se cargo
    cout << "ID: " << id_cancion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Artista: " << artista << endl;
    cout << "Album: " << album << endl;
    cout << "Duracion: " << duracion << " segundos" << endl;
    cout << "Ubicacion audio: " << ubicacion << endl;

    // imprimir los creditos
    cout << "Creditos: ";
    for (int i = 0; i < creditos.obtenerTamanio(); i++)
    {
        string *cred = creditos.obtener(i);
        if (cred)
        {
            cout << *cred;
            if (i < creditos.obtenerTamanio() - 1)
            {
                cout << ", ";
            }
        }
    }
    cout << endl;
    cout << "♪ Reproduciendo... ♪" << endl;
}